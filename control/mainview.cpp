#include "mainview.h"
#include "ui_mainview.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFont>
#include <QPalette>

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    deck = std::unique_ptr<Deck>(new Deck());
    deck->shuffle();
   matchGame = std::unique_ptr<MatchingGame>(new MatchingGame(20, *deck));//CAN I DO THIS????
    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:green"));
    auto vlmain = new QVBoxLayout(ui->centralWidget);
    auto gridmain = new QGridLayout();
    auto hlmain2 = new QHBoxLayout();
    vlmain->addLayout(gridmain);
    vlmain->addLayout(hlmain2);
    font.setPixelSize(40);
    scoreDisplay = new QLabel();
    scoreDisplay->setFont(font);
    hlmain2->addWidget(scoreDisplay);

    for(int i = 0; i < 20; i++){
       auto* cButt = new CardQPushButton(i);
       cardDisplayBtn.push_back(cButt);
        cButt->setFont(font);
        cButt->setMinimumSize(QSize(64,96));
        cButt->setMaximumSize(QSize(64,96));
        cButt->setText("");
        cButt->setStyleSheet("border-image:url(:/new/media/Media/cardback.png)");
        gridmain->addWidget(cButt, i/5, i%5);
        connect (cButt,
                     &CardQPushButton::clicked,
                     this,
                     &MainView::onCardClick);
    }



    //set up shuffle button
    auto* shuffle = new QPushButton;
    shuffle->setFont(font);
    shuffle->setText("Shuffle");

//    QPalette pal = shuffle->palette();
//    pal.setColor(QPalette::Button,QColor(Qt::green));
//    shuffle->setAutoFillBackground(true);
//    shuffle->setPalette(pal);
//    shuffle->update();



    hlmain2->addWidget(shuffle);
    connect (shuffle,
                 &QPushButton::clicked,
                 this,
             [this](){
        deck->shuffle();
        matchGame->reDealCard(20, *deck);

        scoreDisplay->setText("Score:"+QString::number(matchGame->getScore()));

        drawView();

    });

}

MainView::~MainView()
{
    delete ui;
}

void MainView::onCardClick()
{
    auto* btn = dynamic_cast<CardQPushButton*>(sender());
    matchGame->flipCardAt(btn->getIntex());
    drawView();
}

void MainView::drawView()
{
    scoreDisplay->setText("Score:" + QString::number(matchGame->getScore()));
    for(int i = 0; i < cardDisplayBtn.size(); i++)
    {
        CardPtr card = matchGame->getCardAt(i);
        if(card->isMatched())
        {
            cardDisplayBtn[i]->setDisabled(true);
            if(matchGame->getCardAt(i)->getCardColor() == CardColor::Red)
                cardDisplayBtn[i]->setStyleSheet("border-image:url(:/new/media/Media/cardfrontGray.png); color: red;"); //:/new/media/Media/cardfrontGray.png
           else
                cardDisplayBtn[i]->setStyleSheet("border-image:url(:/new/media/Media/cardfrontGray.png); color: black;");
            cardDisplayBtn[i]->setText( QString::fromStdString(matchGame->getCardAt(i)->toString()));
        }
        else if(card->isFlipped())
        {
            cardDisplayBtn[i]->setDisabled(true);
            if(matchGame->getCardAt(i)->getCardColor() == CardColor::Red)
                cardDisplayBtn[i]->setStyleSheet("border-image:url(:/new/media/Media/cardfront.png); color: red;");
           else
                cardDisplayBtn[i]->setStyleSheet("border-image:url(:/new/media/Media/cardfront.png); color: black;");
            cardDisplayBtn[i]->setText( QString::fromStdString(matchGame->getCardAt(i)->toString()));

        }
        else
        {
            cardDisplayBtn[i]->setEnabled(true);
            cardDisplayBtn[i]->setStyleSheet("border-image:url(:/new/media/Media/cardback.png); color: black;");
            cardDisplayBtn[i]->setText( "");
        }

    }
}
