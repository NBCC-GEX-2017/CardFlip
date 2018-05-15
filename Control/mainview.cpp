#include "Control/mainview.h"
#include "ui_mainview.h"
#include "View/cardbutton.h"
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

    //QFont font;
    //font.setPixelSize(40);

    // set up cardButton
    for (int i=0;i<32;i++)
    {
        CardButton* cardButton = new CardButton(i);
        //cardButton->setFont(font);
        //cardButton->setMinimumSize(QSize(128,192));
        //cardButton->setMaximumSize(QSize(128,192));
        //cardButton->setText("");
        //cardButton->setStyleSheet("border-image:url(:/media/Media/cardback.png)");

        grid->addWidget(cardButton, i/8, i%8);


        connect(cardButton,
                &QPushButton::clicked,
                this,
                &MainView::onCardClick);

        buttons.push_back(cardButton);
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
    deck->nextCard();
    drawView();
}

void MainView::drawView()
{
    for (int i=0;i<buttons.size();i++)
    {
        if (deck->isFlipped())
        {
            if(deck->getCardColor() == CardColor::Red)
                buttons[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:red;");
            else
                buttons[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:black;");

            buttons[i]->setText(QString::fromStdString(deck->topCardToString()));
        }
        else
        {
            buttons[i]->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
            buttons[i]->setText("");
        }
    }
}
