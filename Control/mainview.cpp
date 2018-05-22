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



MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
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
    shuffButton->setText("Shuffle me");
    gridLayout->addWidget(shuffButton, 4, 0);
    shuffButton->setMaximumSize(QSize(70,20));
    shuffButton->setMinimumSize(QSize(70,20));
    shuffButton->setFont(font2);

    shuffButton->setStyleSheet(QStringLiteral("background-color:rgb(249, 252, 251);"));

    connect(shuffButton, &QPushButton::clicked, this,
            [this] () {deck->shuffle(); drawView();}
            );

    for(int i = 0; i < 32; ++i){
        CardQPushButton* cardDisplayBtn = new CardQPushButton(i);
        game->setCardAtN(deck->drawCard());
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
    game->setFlip(cardDisplayBtn->getIndex());

    drawView();
}

void MainView::drawView()
{

    for(int i = 0; i < cardDisplayBtns.size(); ++i)
    {
        if(game->isFlipped(i)){
            if(game->getCardColor(i) == CardColor::Red){
                cardDisplayBtns[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: red;");
            }
            else{
                cardDisplayBtns[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: black;");
            }
            cardDisplayBtns[i]->setText(QString::fromStdString(game->getText(i)));
        }
        else{
            cardDisplayBtns[i]->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardback.png);"));
            cardDisplayBtns[i]->setText("");
        }
    }

}
