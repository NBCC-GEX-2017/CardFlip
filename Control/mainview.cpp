#include "mainview.h"
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


    deck=std::unique_ptr<Deck>(new Deck());
    deck->shuffle();

    /*//set up model: Deck deck; deck.shuffle


    //set up layouts
    //central widget->vlMain->hlCard
    //                      ->hlShuffle*/

    QVBoxLayout* vlMain=new QVBoxLayout(ui->centralWidget);
    QHBoxLayout* hlCard=new QHBoxLayout();
    vlMain->addLayout(hlCard);

    QHBoxLayout* hlShuffle=new QHBoxLayout();
    vlMain->addLayout(hlShuffle);

        //vlmain->addSpacing(100);

        auto hl_space_demo = new QHBoxLayout();
        vlMain->addLayout(hl_space_demo);


        vlMain->addStretch(1);

    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23,101,17)"));


    //set up CardButton
    QFont font;
    font.setPixelSize(40);


    auto* card = new QPushButton;
    card->setFont(font);
    card->setMinimumSize(QSize(128,192));
    card->setMaximumSize(QSize(128,192));
    card->setText("");
    card->setStyleSheet("border-image:url(:/new/prefix1/Media/cardback.png)");


    hlCard->addWidget(card);
        hlCard->addStretch(1);

    //set up ShuffleButton

    auto* shuffle=new QPushButton;
    shuffle->setText("Shuffle");
    shuffle->setMinimumSize(QSize(128,20));
    shuffle->setMaximumSize(QSize(128,20));
    shuffle->setStyleSheet(QStringLiteral("background-color:lightsteelblue"));


        hlShuffle->addStretch(1);
    hlShuffle->addWidget(shuffle);




       /* // add some more buttons
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

            //hl_space_demo->addStrut(200);*/
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



}




