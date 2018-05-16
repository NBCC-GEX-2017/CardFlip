#include "Control/mainview.h"
#include "ui_mainview.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QFont>
#include <View/cardqpushbutton.h>



MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);    

    deck = std::unique_ptr<Deck>(new Deck);
    deck->shuffle();

    //vertical layout
    auto vlmain = new QVBoxLayout(ui->centralWidget);

    //horizontal layout
    auto cardsLayout = new QGridLayout();
    vlmain->addLayout(cardsLayout);

    auto shuffleLayout = new QHBoxLayout();
    vlmain->addLayout(shuffleLayout);

    // add gridlayout **
    //QGridLayout* grid = new QGridLayout();
    QFont font;
    font.setPixelSize(40);

    for(int i=0;i<32;i++)
    {
        auto* card = new CardQPushButton(i);


        card->setFont(font);
        card->setMinimumSize(QSize(128,192));
        card->setMaximumSize(QSize(128,192));
        card->setText("");
        card->setStyleSheet("border-image:url(:/new/Media/Media/cardback.png)");

        cardsLayout->addWidget(card,i%4,i/4); //set buttons on a grid
            connect(card,
                    &CardQPushButton::clicked, //connect buttons to clicked event
                    this, //parent
                    &MainView::onCardClick); //clicked event calls onButtonClick code

            cardDisplayBtns.push_back(card); //insert buttons in vector

            //grid->addWidget(cardDisplayBtns[i]);
    }

    //                          -> hlShuffle

    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23, 101, 17);"));

    // set up shuffleButton

   auto shuffleButton = new QPushButton();
   shuffleLayout->addWidget(shuffleButton);   
   shuffleButton->setText("Shuffle");
   shuffleButton->setMinimumSize(QSize(128,20));
   shuffleButton->setMaximumSize(QSize(128,20));
   shuffleButton->setStyleSheet(QStringLiteral("background-color:aliceblue"));

    connect(shuffleButton,
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

    auto* card = dynamic_cast<CardQPushButton*>(sender());
    //deck->nextCard();
    card->getIndex();

    drawView();

}

void MainView::drawView(){

//    for(int i=0;i<32;i++)
//    {
//        if(card->isFlipped())
//        {
//            if(card->getCardColor()== CardColor::Red){
//               cardDisplayBtns[i]->setStyleSheet("border-image:url(:/new/Media/Media/cardfront.png); "
//                                             "color: red;");
//            }
//            else{
//               cardDisplayBtns[i]->setStyleSheet("border-image:url(:/new/Media/Media/cardfront.png); "
//                                             "color: black;");
//            }

//            cardDisplayBtns[i]->setText(QString::fromStdString(deck->topCardToString()));

//        }
//        else
//        {
//            cardDisplayBtns[i]->setStyleSheet("border-image:url(:/new/Media/Media/cardback.png);");
//            cardDisplayBtns[i]->setText("");

//        }
//    }


}
