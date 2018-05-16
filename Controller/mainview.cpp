#include "mainview.h"
#include "ui_mainview.h"
#include <QPushButton>
#include <QVboxLayout>
#include <QHboxLayout>
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

    auto vlmain = new QVBoxLayout(ui->centralWidget);

    auto glcard = new QGridLayout();
    vlmain->addLayout(glcard);

    auto hlshuffle = new QHBoxLayout();
    vlmain->addLayout(hlshuffle);

    vlmain->addStretch(1);
    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:darkolivegreen"));

    // set up cardButton
    QFont font;
    font.setPixelSize(40);

    for (int i=0;i< CARD_COLS * CARD_ROWS;++i)
    {
        auto btn = new QPushButton;
        btn->setFont(font);
        btn->setMinimumSize(QSize(128,192));
        btn->setMaximumSize(QSize(128,192));
        btn->setText("");
        btn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
        glcard->addWidget(btn, i / CARD_COLS, i %CARD_COLS);
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

    for (auto& c : cardButtons)
    {

    }

}


