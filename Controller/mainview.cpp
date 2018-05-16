#include "Controller/mainview.h"
#include "ui_mainview.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFont>
#include <QGridLayout>
#include "View/cardqpushbutton.h"
#include "Model/matchinggame.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    deck = std::unique_ptr<Deck>(new Deck());
    deck->shuffle();
    game = std::unique_ptr<MatchingGame>(new MatchingGame(52,*deck));
    //game = new MatchingGame(52,deck);
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
        auto btn= new CardQPushButton(i);
        //auto* cardDisplayBtn= new QPushButton;
        btn->setFont(font);
        btn->setMinimumSize(QSize(32,48));
        //btn->setMinimumSize(QSize(128,192));
        btn->setMaximumSize(QSize(32,48));
        btn->setText("");
        btn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
        glcard->addWidget(btn, i/8, i%8);
        connect(btn,
                &CardQPushButton::clicked,
                this,
                &MainView::onCardClick);

        //cardDisplayBtns->push_back(cardDisplayBtn);
        cardDisplayBtns.push_back(btn);

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
    auto tmp = sender();

    CardQPushButton* cardIndex = dynamic_cast<CardQPushButton*>(tmp);
    game->selectCard(cardIndex->getIndex());
    //ask qpushbutton for its index
    //tell model card @index changed
    //tmp->getIndex();
    //tmp->flip();

    drawView();
}
void MainView::drawView()
{
    for(auto& c : cardDisplayBtns)
    {
        CardPtr tmp = game->getCard(c->getIndex());
        //if(game->getCard(c->getIndex()).isFlipped())
        if(tmp->isFlipped())
        {
            c->setText(QString::fromStdString(tmp->toString()));
            if(tmp->getColor()==CardColor::Red)
            //if(game->getCard(c->getIndex())->getColor()==CardColor::Red)
            {
                 c->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:red;");
            }
            else
            {
                c->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:black;");
            }
        }
            //c->setText(QString::fromStdString(deck->topCardToString()));
        else
        {
            c->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
            c->setText("");
        }
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
