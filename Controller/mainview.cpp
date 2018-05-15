#include "Controller/mainview.h"
#include "ui_mainview.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFont>


MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    //set up the Deck deck; deck.shuffle
    deck=std::unique_ptr<Deck>(new Deck());

    deck->shuffle();

    //set up layout
    auto vlmain= new QVBoxLayout(ui->centralWidget);

    //auto hlCard = new QHBoxLayout();
    auto* grid = new QGridLayout();
    auto hlShuffle = new QHBoxLayout();
    //auto hl_space_demo = new QHBoxLayout();

    //vlmain->addLayout(hlCard);
    vlmain->addLayout(grid);
    vlmain->addLayout(hlShuffle);
    //vlmain->addLayout(hl_space_demo);

    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23,101,17)"));
    // central widget -> vlMain -> hlCard
    //                          -> hlShuffle

    //set up grid


    // set up cardButtons
    for(int i=0;i<32;i++){

        QFont font;
        font.setPixelSize(40);

        cardDisplayBtn = new QPushButton();
        grid->addWidget(cardDisplayBtn,i/8,i%8);

        cardDisplayBtn->setFont(font);
        cardDisplayBtn->setMinimumSize(QSize(100,150));
        cardDisplayBtn->setMaximumSize(QSize(100,150));
        cardDisplayBtn->setText("");
        cardDisplayBtn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");

        //connect button
        connect(cardDisplayBtn,
                &QPushButton::clicked,
                this,
                &MainView::onCardClick);

        cardDisplayBtns.push_back(cardDisplayBtn);

    }



    // set up shuffle button
    auto newShuffleBtn= new QPushButton();

    newShuffleBtn->setText("Shuffle");
    newShuffleBtn->setStyleSheet(QStringLiteral("background-color:grey"));
    newShuffleBtn->setMinimumSize(QSize(128,20));
    newShuffleBtn->setMaximumSize(QSize(128,20));


    hlShuffle->addStretch(1);

    hlShuffle->addWidget(newShuffleBtn);

    connect(newShuffleBtn,
            &QPushButton::clicked,
            this,
            [this](){deck->shuffle();
                    drawView();});

//    // add some more buttons

//    for (int i=0;i<5;++i)
//    {
//        auto btn = new QPushButton();
//        btn->setText("X");
//        btn->setMinimumSize(QSize(20,20));
//        btn->setMaximumSize(QSize(20,20));
//        btn->setStyleSheet(QStringLiteral("background-color:plum"));
//        hl_space_demo->addWidget(btn);
//    }

//    hl_space_demo->addStretch(1);

//    // add some more buttons
//    for (int i=0;i<5;++i)
//    {
//        auto btn = new QPushButton();
//        btn->setText("X");
//        btn->setMinimumSize(QSize(20,20));
//        btn->setMaximumSize(QSize(20,20));
//        btn->setStyleSheet(QStringLiteral("background-color:plum"));
//        hl_space_demo->addWidget(btn);
//        hl_space_demo->addSpacing(20);
//    }


}

MainView::~MainView()
{
    delete ui;
}

void MainView::onCardClick()
{
    deck->nextCard();
    drawView();
}

void MainView::drawView()
{
    for(int i=0;i<32;i++){

        if(deck->isFlipped()){
            if(deck->getCardColor()==CardColor::Red)
            {
                cardDisplayBtns[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: red;");


            }
            else{
                cardDisplayBtns[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: black;");
            }
            cardDisplayBtns[i]->setText(QString::fromStdString(deck->topCardToString()));

        }
        else{

            cardDisplayBtns[i]->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
            cardDisplayBtns[i]->setText("");
        }

    }


}


