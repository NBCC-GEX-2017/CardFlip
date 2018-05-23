#include "mainview.h"
#include "ui_mainview.h"
#include "View/cardqpushbutton.h"
#include <QPushButton>
#include <QVBoxLayout>
#include "Model/matchinggame.h"
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QFont>
#include <QDebug>

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    srand(time(0));
    ui->setupUi(this);
    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(39, 163, 101);"));
    this->setWindowTitle("Matching Game!");

    deck = std::unique_ptr<Deck>(new Deck());
    deck->shuffle();
    game = new MatchingGame();

    QFont font;
    font.setPixelSize(40);
    QFont font2;
    font2.setPixelSize(15);
    font2.setFamily("Times new Roman");

    auto* verticalLayoutMain = new QVBoxLayout(ui->centralWidget);
    auto* gridLayout = new QGridLayout();
    verticalLayoutMain->addLayout(gridLayout);

    //set up shuffle button
    auto* shuffButton = new QPushButton;
    shuffButton->setText("SHUFFLE");
    gridLayout->addWidget(shuffButton, 4, 0);
    shuffButton->setMaximumSize(QSize(70,20));
    shuffButton->setMinimumSize(QSize(70,20));
    shuffButton->setFont(font2);

    shuffButton->setStyleSheet(QStringLiteral("background-color:rgb(249, 252, 251);"));

    score = new QLabel;
    score->setText("Score: 0");
    gridLayout->addWidget(score, 4, 1);
    score->setFont(font2);

    connect(shuffButton, &QPushButton::clicked, this,
            [this] () {deck->shuffle(); game->setScore(0); drawView(); }
            );

    for(int i = 0; i < 32; ++i){
        CardQPushButton* cardDisplayBtn = new CardQPushButton(i);
        game->insertCardAtN(deck->drawCard());

        cardDisplayBtn->setFont(font);
        cardDisplayBtn->setMaximumSize(QSize(128,192));
        cardDisplayBtn->setMinimumSize(QSize(128,192));
        cardDisplayBtn->setText("");
        cardDisplayBtn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
        gridLayout->addWidget(cardDisplayBtn, i%4, i/4);
        connect(cardDisplayBtn, &CardQPushButton::clicked, this, &MainView::onCardClick);
        cardDisplayBtns.push_back(cardDisplayBtn);
    }


}

MainView::~MainView()
{
    delete ui;
}

void MainView::onCardClick()
{
    auto* cardDisplayBtn = dynamic_cast<CardQPushButton*>(sender());
    game->setCardN(cardDisplayBtn->getIndex());

    drawView();
    game->delay(500);
    game->cardNotMatched();
    drawView();
}

void MainView::drawView()
{

    score->setText(QString("Score: ") + QString::number(game->getScore()));

    for(auto c : cardDisplayBtns)
    {
        c->setEnabled(true);
        CardPtr card = game->getCardAtN(c->getIndex());
        if(card->isFlipped()){
            if(card->getColor() == CardColor::Red){
                c->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: red;");
            }
            else{
                c->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: black;");
            }
            c->setText(QString::fromStdString(card->toString()));
        }
        else{
            c->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardback.png);"));
            c->setText("");
        }
        if(card->isMatched())
        {
            c->setEnabled(false);
            if(card->getColor() == CardColor::Red){
                c->setStyleSheet("border-image:url(:/media/Media/cardfrontGray.png); color: red;");
            }
            else
            {
                c->setStyleSheet("border-image:url(:/media/Media/cardfrontGray.png); color: black;");
            }
        }
    }

}
