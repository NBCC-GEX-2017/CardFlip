#include "mainview.h"
#include "ui_mainview.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QFont>
#include "View/cardqpushbutton.h"
#include "Model/game.h"
const int cardRows=4;
const int cardCols=8;
MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    deck = std::unique_ptr<Deck>(new Deck());
    deck->shuffle();

    auto vlmain = new QVBoxLayout(ui->centralWidget);

    auto hlcard = new QHBoxLayout();
    vlmain->addLayout(hlcard);

    auto glcard = new QGridLayout();
    vlmain->addLayout(glcard);

    auto hlshuffle = new QHBoxLayout();
    vlmain->addLayout(hlshuffle);

    //vlmain->addSpacing(100);

    auto hl_space_demo = new QHBoxLayout();
    vlmain->addLayout(hl_space_demo);


    vlmain->addStretch(1);
    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:darkolivegreen"));


    // set up cardButton
    QFont font;
    font.setPixelSize(40);

    for(int i = 0; i < cardCols * cardRows; ++i){
        auto btn = new CardQPushButton(i);
        btn->setFont(font);
        btn->setMinimumSize(QSize(128,192));
        btn->setMaximumSize(QSize(128,192));
        btn->setText("");
        btn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
        glcard->addWidget(btn, i / cardCols, i % cardRows);
        cardButtons.push_back(btn);
        connect(btn,
                &QPushButton::clicked,
                this,
                &MainView::onCardClick);
}
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
    // add some more buttons
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

    hl_space_demo->addStrut(2000);

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
    for(auto& c : cardButtons){
        auto game = new QPushButton;
        if(game->getCard(c->getIndex()).isFlipped()){

        }else{

        }
    }
}
