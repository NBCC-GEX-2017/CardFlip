#include "Controller/mainview.h"
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

    deck = std::unique_ptr<Deck>(new Deck());
    deck->shuffle();
    //set up model Deck deck; Deck.shuffle();

    // set up layouts
    // central widget -> vlMain -> hlCard
    //                          -> hlShuffle
    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23,101,17)"));
    auto vlmain = new QVBoxLayout(ui->centralWidget);//QVBoxLayout* vlmain
    //auto hlcard = new QHBoxLayout();
    auto glcard = new QGridLayout();
    vlmain->addLayout(glcard);
    auto hlshuffle = new QHBoxLayout();
    vlmain->addLayout(hlshuffle);

    // set up cardButton
    QFont font;
    //font.setPixelSize(40);
    font.setPixelSize(20);

    for(int i = 0; i < 32; i++)
    {
        cardDisplayBtn= new QPushButton;
        //auto* cardDisplayBtn= new QPushButton;
        cardDisplayBtn->setFont(font);
        cardDisplayBtn->setMinimumSize(QSize(32,48));
        cardDisplayBtn->setMaximumSize(QSize(32,48));
        cardDisplayBtn->setText("");
        cardDisplayBtn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
        glcard->addWidget(cardDisplayBtn, i/8, i%8);
        connect(cardDisplayBtn,
                &QPushButton::clicked,
                this,
                &MainView::onCardClick);

        //cardDisplayBtns->push_back(cardDisplayBtn);
        cardDisplayBtns.push_back(cardDisplayBtn);

    }

    // set up shuffle button
    auto* shufflebtn = new QPushButton;
    shufflebtn->setText("SHUFFLE");
    shufflebtn->setMinimumSize(QSize(128,25));
    shufflebtn->setMaximumSize(QSize(128,25));
    shufflebtn->setStyleSheet(QStringLiteral("background-color:lightsteelblue"));
    hlshuffle->addWidget(shufflebtn);
    connect(shufflebtn,
                &QPushButton::clicked,
                this,
                [this](){deck->shuffle(); drawView();});
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
    for(auto c : cardDisplayBtns)
    {

    }
    //for(int i=0; i<cardDisplayBtns.size(); i++)
    //{
    //    if(deck->isFlipped())
    //    {
    //        if(deck->getCardColor()==CardColor::Red)
    //        {
    //             cardDisplayBtns[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:red;");
    //        }
    //        else
    //        {
    //            cardDisplayBtns[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:black;");
    //        }
    //        cardDisplayBtns[i]->setText(QString::fromStdString(deck->topCardToString()));
    //    }
    //    else
    //    {
    //        cardDisplayBtns[i]->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
    //        cardDisplayBtns[i]->setText("");
    //    }
    //}

}
