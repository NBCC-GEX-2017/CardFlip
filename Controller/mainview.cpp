#include "mainview.h"
#include "ui_mainview.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QFont>
#include "View/cardqpushbutton.h"
#include "Model/matchinggame.h"
#include "Model/Deck.h"
#include <QLabel>
#include <QDebug>


const int CARD_ROWS = 3;
const int CARD_COLS = 8;

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    deck = std::unique_ptr<Deck>(new Deck());
    deck->shuffle();

    game = std::unique_ptr<MatchingGame>(new MatchingGame(CARD_ROWS * CARD_COLS, *deck));

    auto vlmain = new QVBoxLayout(ui->centralWidget);

    auto glcard = new QGridLayout();
    vlmain->addLayout(glcard);

    auto hlshuffle = new QHBoxLayout();
    vlmain->addLayout(hlshuffle);

    vlmain->addStretch(1);
    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:darkolivegreen"));

    // set up cardButton
    QFont font;
    font.setPixelSize(40);

    for (int i=0;i< CARD_COLS * CARD_ROWS;++i)
    {
        auto btn = new CardQPushButton(i);
        btn->setFont(font);
        btn->setMinimumSize(QSize(128,192));
        btn->setMaximumSize(QSize(128,192));
        btn->setText("");
        btn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
        glcard->addWidget(btn, i / CARD_COLS, i % CARD_COLS);
        cardButtons.push_back(btn);

        connect(btn,
                &CardQPushButton::clicked,
                this,
                &MainView::onCardClick);

    }





    // set up shuffle button

    auto shuffleButton = new QPushButton();
    shuffleButton->setText("New Game");
    shuffleButton->setMinimumSize(QSize(128,20));
    shuffleButton->setMaximumSize(QSize(128,20));
    shuffleButton->setStyleSheet(QStringLiteral("background-color:aliceblue"));

    hlshuffle->addStretch(1);
    hlshuffle->addWidget(shuffleButton);

    connect(shuffleButton,
            &QPushButton::clicked,
            this,
            [this](){
        deck->shuffle();
        game = std::unique_ptr<MatchingGame>(new MatchingGame(CARD_ROWS * CARD_COLS, *deck));
        drawView();
    });

    gameScore = new QLabel();
    gameScore->setText("0");
    hlshuffle->addWidget(gameScore);
}

MainView::~MainView()
{
    delete ui;
}

void MainView::onCardClick()
{
    auto fromButton = sender();
    CardQPushButton* fromCardButton = dynamic_cast<CardQPushButton*>(fromButton);
    game->selectCardN(fromCardButton->getIndex());
    drawView();
}

void MainView::drawView()
{

    for (auto& c : cardButtons)
    {
        CardPtr card = game->getCardN(c->getIndex());
        if(card->isMatched())
        {
            c->setText(QString::fromStdString(card->toString()));
            if (card->getColor() == CardColor::Red)
                c->setStyleSheet("border-image:url(:/media/Media/cardfrontGray.png); color: red;");
            else
                c->setStyleSheet("border-image:url(:/media/Media/cardfrontGray.png); color: black;");
        }
        else{
        if (card->isFlipped())
        {
            c->setText(QString::fromStdString(card->toString()));
            if (card->getColor() == CardColor::Red)
                c->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: red;");
            else
                c->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: black;");


        }
        else
        {
            c->setText("");
            c->setStyleSheet("border-image:url(:/media/Media/cardback.png);");
        }
        }
    }
    gameScore->setText(QString::number(game->getScore()));
}


