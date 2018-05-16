#include "Control/mainview.h"
#include "ui_mainview.h"
#include "View/cardbutton.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QString>
#include <QFont>

const int CARD_ROWS = 4;
const int CARD_COLS = 8;

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    deck = std::unique_ptr<Deck>(new Deck());
    deck->shuffle();
    // set up model Deck deck; deck shuffle

    // set up layouts
    //  central widget -> vlMain -> hlCard
    //                           -> hlShuffle
    //auto vlMain = new QVBoxLayout(ui->centralWidget);
    //auto hlCard = new QHBoxLayout();
    //vlMain->addLayout(hlCard);
    auto* grid = new QGridLayout(ui->centralWidget);
    //auto hlShuffle = new QHBoxLayout();
    //vlMain->addLayout(hlShuffle);

    ui->centralWidget->setStyleSheet("background-color:green;");

    QFont font;
    font.setPixelSize(40);

    // set up cardButton
    for (int i=0;i<CARD_ROWS * CARD_COLS;++i)
    {
        CardButton* cardButton = new CardButton(i);
        cardButton->setFont(font);
        cardButton->setMinimumSize(QSize(128,192));
        cardButton->setMaximumSize(QSize(128,192));
        cardButton->setText("");
        cardButton->setStyleSheet("border-image:url(:/media/Media/cardback.png)");

        grid->addWidget(cardButton, i/CARD_COLS, i%CARD_COLS);


        connect(cardButton,
                &QPushButton::clicked,
                this,
                &MainView::onCardClick);

        cardButtons.push_back(cardButton);
    }
    // set up shuffle button
    auto shuffleButton = new QPushButton();
    shuffleButton->setText("Shuffle");
    shuffleButton->setMinimumSize(QSize(128,20));
    shuffleButton->setMaximumSize(QSize(128,20));
    shuffleButton->setStyleSheet(QStringLiteral("border-color:aliceblue"));
    shuffleButton->setStyleSheet("background-color: white;");

    grid->addWidget(shuffleButton, 4, 7);

    connect(shuffleButton,
            &QPushButton::clicked,
            this,
            [this](){deck->shuffle();drawView();});

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
    //for (int i=0;i<cardButtons.size();i++)
    //{
        //if (deck->isFlipped())
        //{
            //if(deck->getCardColor() == CardColor::Red)
                //cardButtons[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:red;");
            //else
                //cardButtons[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:black;");

            //cardButtons[i]->setText(QString::fromStdString(deck->topCardToString()));
        //}
        //else
        //{
            //cardButtons[i]->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
            //cardButtons[i]->setText("");
        //}
    //}
}
