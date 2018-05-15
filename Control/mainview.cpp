#include "Control/mainview.h"
#include "ui_mainview.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QFont>


MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);    

    deck = std::unique_ptr<Deck>(new Deck);
    deck->shuffle();

    // add gridlayout **
    auto* grid = new QGridLayout(ui->centralWidget);

    // set up layouts
    for(int i=0;i<24;i++)
    {
        QPushButton cardDisplayBtns* = new QPushButton(i);
        cardDisplayBtns(i)->setFont(font);
        cardDisplayBtns(i)->setMinimumSize(QSize(128,192));
        cardDisplayBtns(i)->setMaximumSize(QSize(128,192));
        cardDisplayBtns(i)->setText("");
        cardDisplayBtns(i)->setStyleSheet("border-image:url(:/new/Media/Media/cardback.png)");

        grid->addWidget(btn,i/6,i%4); //set buttons on a grid
            connect(cardDisplayBtns,
                    &QPushButton::clicked, //connect buttons to clicked event
                    this, //parent
                    &MainView::onButtonClick); //clicked event calls onButtonClick code
            buttons.push_back(cardDisplayBtns); //insert buttons in vector

    }


//    // central widget -> vlMain -> hlCard
//    auto vlMain = new QVBoxLayout(ui->centralWidget);

//    auto hlMain = new QHBoxLayout();
//    vlMain->addLayout(hlMain);

//    auto hlShuffle = new QHBoxLayout();
//    vlMain->addLayout(hlShuffle);


    //                          -> hlShuffle

    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23, 101, 17);"));

    // set up cardButton
    QFont font;
    font.setPixelSize(40);



    hlMain->addStretch(1);

    connect(cardDisplayBtn,
            &QPushButton::clicked,
            this,
            &MainView::onCardClick);

    //connect(card, &QPushButton::clicked, this, &MainView::centralWidget);

    // set up shuffleButton

    auto* shuffle = new QPushButton;
    shuffle->setText("Shuffle");
    shuffle->setMinimumSize(QSize(128,30));
    shuffle->setMaximumSize(QSize(128,30));
    shuffle->setStyleSheet(QStringLiteral("background-color:lightsteelblue"));

    hlShuffle->addWidget(shuffle); // add button to layout
    connect(shuffle,
            &QPushButton::clicked,
            this,
            [this](){
        deck->shuffle();
        drawView();});

}

MainView::~MainView()
{
    delete ui;
}

void MainView::onCardClick(){
    //deck->nextCard();
    drawView();
}

void MainView::drawView(){

    if(deck->isFlipped())
    {
        if(deck->getCardColor()== CardColor::Red){
           cardDisplayBtn->setStyleSheet("border-image:url(:/new/Media/Media/cardfront.png); "
                                         "color: red;");
        }
        else{
           cardDisplayBtn->setStyleSheet("border-image:url(:/new/Media/Media/cardfront.png); "
                                         "color: black;");
        }

        cardDisplayBtn->setText(QString::fromStdString(deck->topCardToString()));
        //cardDisplayBtn->setStyleSheet("color: red;");
    }
    else
    {
        cardDisplayBtn->setStyleSheet("border-image:url(:/new/Media/Media/cardback.png);");
        cardDisplayBtn->setText("");
    }



}
