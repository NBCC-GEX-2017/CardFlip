#include "mainview.h"
#include "ui_mainview.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFont>
#include <QGridLayout>

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    //set up model Deck deck; Deck.shuffle();

    // set up layouts
    // central widget -> vlMain -> hlCard
    //                          -> hlShuffle
    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23,101,17)"));
    auto vlmain = new QVBoxLayout(ui->centralWidget);//QVBoxLayout* vlmain
    //auto hlcard = new QHBoxLayout();
    auto hlcard = new QGridLayout();
    vlmain->addLayout(hlcard);
    auto hlshuffle = new QHBoxLayout();
    vlmain->addLayout(hlshuffle);

    // set up cardButton
    QFont font;
    font.setPixelSize(40);

    for(int i = 0; i < 32; i++)
    {
        cardDisplayBtn= new QPushButton;
        cardDisplayBtn->setFont(font);
        cardDisplayBtn->setMinimumSize(QSize(128,192));
        cardDisplayBtn->setMaximumSize(QSize(128,192));
        cardDisplayBtn->setText("");
        cardDisplayBtn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
        hlcard->addWidget(cardDisplayBtn, i/8, i%4);
        cardDisplayBtns.push_back(cardDisplayBtn);

    }
    //for(int i = 0; i < 32; i++)
    //{
    //    auto* card = new QPushButton;
    //    card->setFont(font);
    //    card->setMinimumSize(QSize(128,192));
    //    card->setMaximumSize(QSize(128,192));
    //    card->setText("");
    //    card->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
    //    hlcard->addWidget(card, i/8, i%4);
    //    cardDisplayBtns.push_back(card);
    //
    //}


    // set up shuffle button
    auto* shufflebtn = new QPushButton;
    shufflebtn->setText("SHUFFLE");
    shufflebtn->setMinimumSize(QSize(128,25));
    shufflebtn->setMaximumSize(QSize(128,25));
    shufflebtn->setStyleSheet(QStringLiteral("background-color:lightsteelblue"));
    hlshuffle->addWidget(shufflebtn);
}

MainView::~MainView()
{
    delete ui;
}

void MainView::onCardClick()
{
    //deck->nextCard();
    drawView();
}
void MainView::drawView()
{
    if(deck->isFlipped())
    {
        if(deck->getCardColor()==CardColor::Red)
        {
             cardDisplayBtn->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:red;");
        }
        else{
        cardDisplayBtn->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:black;");
        }
        cardDisplayBtn->setText(QString::fromStdString(deck->topCardToString()));
    }
    else
    {
        cardDisplayBtn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
        cardDisplayBtn->setText("");
    }
    //if(deck->isFlipped())
    //{
    //    if(deck->getCardColor()==CardColor::Red)
    //    {
    //         cardDisplayBtn->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:red;");
    //    }
    //    else{
    //    cardDisplayBtn->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:black;");
    //    }
    //    cardDisplayBtn->setText(QString::fromStdString(deck->topCardToString()));
    //}
    //else
    //{
    //    cardDisplayBtn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
    //    cardDisplayBtn->setText("");
    //}
}
