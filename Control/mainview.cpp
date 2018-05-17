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

    game = new Game();

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
        auto* btn = new CardQPushButton(i);

        game->setCardAtN(deck->drawCard());
        ////////////////////////////////
        btn->setFont(font);
        btn->setMinimumSize(QSize(128,192));
        btn->setMaximumSize(QSize(128,192));
        btn->setText("");
        btn->setStyleSheet("border-image:url(:/new/Media/Media/cardback.png)");

        cardsLayout->addWidget(btn,i%4,i/4); //set buttons on a grid
            connect(btn,
                    &CardQPushButton::clicked, //connect buttons to clicked event
                    this, //parent
                    &MainView::onCardClick); //clicked event calls onButtonClick code

            cardDisplayBtns.push_back(btn); //insert buttons in vector

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

    CardQPushButton* btn = dynamic_cast<CardQPushButton*>(sender());
    //deck->nextCard();
    game->setFlipped(btn->getIndex());


    drawView();

}

void MainView::drawView(){

    for(int i=0;i<32;i++)
    {
        if(game->isFlipped(i))
        {
            if(game->getCardColor(i)== CardColor::Red){
               cardDisplayBtns[i]->setStyleSheet("border-image:url(:/new/Media/Media/cardfront.png); "
                                             "color: red;");
            }
            else{
               cardDisplayBtns[i]->setStyleSheet("border-image:url(:/new/Media/Media/cardfront.png); "
                                             "color: black;");
            }

            cardDisplayBtns[i]->setText(QString::fromStdString(game->getText(i)));

        }
        else
        {
            cardDisplayBtns[i]->setStyleSheet("border-image:url(:/new/Media/Media/cardback.png);");
            cardDisplayBtns[i]->setText("");

        }
    }


}
