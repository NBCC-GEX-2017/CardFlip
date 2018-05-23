#include "mainview.h"
#include "ui_mainview.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFont>
#include <QGridLayout>
#include "View/cardqpushbutton.h"
#include "Model/matchinggame.h"
#include "Model/Deck.h"


const int Card_Rows=4;
const int Card_Cols=8;

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);


    deck=std::unique_ptr<Deck>(new Deck());
    deck->shuffle();


    game=std::unique_ptr<MatchingGame>(new MatchingGame(Card_Cols*Card_Rows, *deck));


    QVBoxLayout* vlMain=new QVBoxLayout(ui->centralWidget);
    QGridLayout* glcard=new QGridLayout();
    vlMain->addLayout(glcard);


    QHBoxLayout* hlShuffle=new QHBoxLayout();
    vlMain->addLayout(hlShuffle);



    vlMain->addStretch(1);

    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23,101,17)"));


    //set up CardButton
    QFont font;
    font.setPixelSize(40);




        for(int i=0;i<Card_Cols*Card_Rows;i++){
            CardQPushButton* btn = new CardQPushButton(i);


            btn->setFont(font);
            btn->setMinimumSize(QSize(128,172));
            btn->setMaximumSize(QSize(128,172));
            btn->setText("");
            btn->setStyleSheet("border-image:url(:/new/prefix1/Media/cardback.png)");

            glcard->addWidget(btn, i/Card_Cols,i%Card_Cols);
            cardButtons.push_back(btn);



            connect(btn,
                    &CardQPushButton::clicked,
                    this,
                    &MainView::onCardClick);


        }

    //set up ShuffleButton

    auto* shuffle=new QPushButton;
    shuffle->setText("Shuffle");
    shuffle->setMinimumSize(QSize(128,20));
    shuffle->setMaximumSize(QSize(128,20));
    shuffle->setStyleSheet(QStringLiteral("background-color:lightsteelblue"));


    hlShuffle->addStretch(1);
    hlShuffle->addWidget(shuffle);

    connect(shuffle,
            &QPushButton::clicked,
            this,
            [this](){deck->shuffle();
                    game=std::unique_ptr<MatchingGame>(new MatchingGame(Card_Cols*Card_Rows, *deck));
                    drawView();});



}

MainView::~MainView()
{
    delete ui;
}


void MainView::onCardClick()
{
    auto fromButton=sender();
    CardQPushButton* fromCardButton=dynamic_cast<CardQPushButton*>(fromButton);
    game->selectCard(fromCardButton->getIndex());

    drawView();


}

void MainView::drawView()
{

    for(auto& c : cardButtons){


        CardPtr card=game->getCard(c->getIndex());

        if(card->isMathced())
        {
            c->setText(QString::fromStdString(card->toString()));
            if(card->getColor()==CardColor::Red)
                c->setStyleSheet("border-image:url(:/new/prefix1/Media/cardfrontGray.png); color:red");
            else
                c->setStyleSheet("border-image:url(:/new/prefix1/Media/cardfrontGray.png); color:black");
        }
        else
        {
            if(card->isFlipped())
            {
                c->setText(QString::fromStdString(card->toString()));
                if(card->getColor()==CardColor::Red)
                    c->setStyleSheet("border-image:url(:/new/prefix1/Media/cardfront.png); color:red");
                else
                    c->setStyleSheet("border-image:url(:/new/prefix1/Media/cardfront.png); color:black");
            }
            else
            {
                c->setText("");
                c->setStyleSheet("border-image:url(:/new/prefix1/Media/cardback.png)");

            }
        }
    }

}




