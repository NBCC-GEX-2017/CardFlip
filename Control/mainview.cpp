#include "mainview.h"
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
    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(39, 163, 101);"));
    this->setWindowTitle("Card Flip Palooza");

    deck = std::unique_ptr<Deck>(new Deck());
    deck->shuffle();


    QFont font;

    font.setPixelSize(40);
    auto* verticalLayoutMain = new QVBoxLayout(ui->centralWidget);
    auto* gridLayout = new QGridLayout();
    verticalLayoutMain->addLayout(gridLayout);

    for(int i = 0; i < 32; ++i){
        cardDisplayBtn = new QPushButton;
        cardDisplayBtn->setFont(font);
        cardDisplayBtn->setMaximumSize(QSize(128,192));
        cardDisplayBtn->setMinimumSize(QSize(128,192));
        cardDisplayBtn->setText("");
        cardDisplayBtn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
        gridLayout->addWidget(cardDisplayBtn, i%4, i/4);
        connect(cardDisplayBtn, &QPushButton::clicked, this, &MainView::onCardClick);
        cardDisplayBtns.push_back(cardDisplayBtn);
    }



    //set up shuffle button
    auto* shuffButton = new QPushButton;
    shuffButton->setText("Shuffle me");
    shuffButton->setMaximumSize(QSize(70,20));
    shuffButton->setMaximumSize(QSize(70,20));
    gridLayout->addWidget(shuffButton);

    shuffButton->setStyleSheet(QStringLiteral("background-color:rgb(249, 252, 251);"));

    connect(shuffButton, &QPushButton::clicked, this,
            [this] () {deck->shuffle(); drawView();}
            );

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
    for(int i = 0; i < 32; ++i){
        if(deck->isFlipped())
        {
            if(deck->getCardColor() == CardColor::Red)
                cardDisplayBtns[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: red;");
            else
                cardDisplayBtns[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: black;");

            cardDisplayBtns[i]->setText(QString::fromStdString(deck->topCardToString()));
        }
        else{
            cardDisplayBtns[i]->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
            cardDisplayBtns[i]->setText("");
        }
    }

}
