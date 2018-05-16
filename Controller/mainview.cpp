#include "mainview.h"
#include "ui_mainview.h"
#include <QPushbutton>
#include <QVboxLayout>
#include <QHboxLayout>
#include <QString>
#include <QFont>
#include "View/cardqpushbutton.h"

int NUM_COLM=8;
int NUM_ROWS=4;
MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    flippin = new Game; // create an instance of game
    qsrand(time(0));
    ui->setupUi(this);
    deck = std::unique_ptr<Deck>(new Deck());
    deck->shuffle();
    // set up model Deck deck; deck.shuffle
     QFont font;
     font.setPixelSize(24);
    // set up layouts
    //  central widget -> vlMain -> hlCard
    //                           -> hlShuffle
    auto vlmain = new QVBoxLayout(ui->centralWidget);


    auto hlcard = new QGridLayout();
    vlmain->addLayout(hlcard);
    for(int i=0;i<(NUM_ROWS*NUM_COLM);i++){
        auto btn=new CardQPushButton(i);
        cardButtons.push_back(btn);          // same index because we created it at the time
        flippin->setCard(deck->drawCard()); //
        btn->setFont(font);
        btn->setMinimumSize(QSize(100,128));
        btn->setMaximumSize(QSize(100,128));
        btn->setText("");
        btn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
        hlcard->addWidget(btn,i/NUM_COLM,i%NUM_COLM);
        connect(btn,
                &CardQPushButton::clicked,
                this,
                &MainView::onCardClick);
    }

    auto hlshuffle = new QHBoxLayout();
    vlmain->addLayout(hlshuffle);

    vlmain->addSpacing(100);

    auto hl_space_demo = new QHBoxLayout();
    vlmain->addLayout(hl_space_demo);


    vlmain->addStretch(1);
    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:darkolivegreen"));

    // set up cardButton

    font.setPixelSize(40);

    /*cardDisplaybtn = new QPushButton;
    cardDisplaybtn->setFont(font);
    cardDisplaybtn->setMinimumSize(QSize(128,192));
    cardDisplaybtn->setMaximumSize(QSize(128,192));
    cardDisplaybtn->setText("");
    cardDisplaybtn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");

    hlcard->addWidget(cardDisplaybtn);
    hlcard->addStretch(1);
    connect(cardDisplaybtn,
            &QPushButton::clicked,
            this,
            &MainView::onCardClick);*/
    // set up shuffle button

    auto shuffleButton = new QPushButton();
    shuffleButton->setText("Shuffle");
    shuffleButton->setMinimumSize(QSize(128,20));
    shuffleButton->setMaximumSize(QSize(128,20));
    shuffleButton->setStyleSheet(QStringLiteral("background-color:aliceblue"));

    hlshuffle->addStretch(1);
    hlshuffle->addWidget(shuffleButton);
    connect(shuffleButton,
            &QPushButton::clicked,
            this,
            [this](){deck->shuffle();drawView();});
/*    // add some more buttons
    for (int i=0;i<5;++i)
    {
        auto btn = new QPushButton();
        btn->setText("X");
        btn->setMinimumSize(QSize(20,20));
        btn->setMaximumSize(QSize(20,20));
        btn->setStyleSheet(QStringLiteral("background-color:plum"));
        hl_space_demo->addWidget(btn);
    }

    hl_space_demo->addStretch(1);

    // add some more buttons
    for (int i=0;i<5;++i)
    {
        auto btn = new QPushButton();
        btn->setText("X");
        btn->setMinimumSize(QSize(20,20));
        btn->setMaximumSize(QSize(20,20));
        btn->setStyleSheet(QStringLiteral("background-color:plum"));
        hl_space_demo->addWidget(btn);
        hl_space_demo->addSpacing(20);
    }

    //hl_space_demo->addStrut(2000); */

}


MainView::~MainView()
{
    delete ui;
}

void MainView::onCardClick()
{

    auto* tmp=dynamic_cast<CardQPushButton*>(sender());

    flippin->setFlip(tmp->getIndex()); //setting the flip function of the game"flippin"

            // deck->nextCard();
    drawView(); //redraw the view on drawing card

}
void MainView::drawView()
{

     for(int y=0;y<cardButtons.size();y++) // y becasuse i said so
     {
         if(flippin->isFlipped(y))
         {
             if(flippin->getColor(y)==CardColor::RED)
             {
                cardButtons[y]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: red;");
             }
             else
             {
                 cardButtons[y]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: black;");
             }
             cardButtons[y]->setText(QString::fromStdString(flippin->getText(y)));
         }
         else
         {
             cardButtons[y]->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
             cardButtons[y]->setText("");
         }
     }
    /*
    if(deck->isFlipped())
    {
        if(deck->getCardColor()==CardColor::Red)
        {
        btn->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: red;");
        }
        else
      {
            btn->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: black;");
        }
        btn->setText(QString::fromStdString(deck->topCardToString()));
    //    cardDisplaybtn->setStyleSheet()
        }

    else
    {
        btn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
        btn->setText("");
 */
}
