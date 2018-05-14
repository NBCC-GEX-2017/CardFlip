#include "Control/mainview.h"
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
    //auto* grid = new QGridLayout(ui->centralWidget);
    // set up model Deck deck; deck.shuffle();

    // set up layouts

    // central widget -> vlMain -> hlCard
    auto vlMain = new QVBoxLayout(ui->centralWidget);

    auto hlMain = new QHBoxLayout();
    vlMain->addLayout(hlMain);

    auto hlShuffle = new QHBoxLayout();
    vlMain->addLayout(hlShuffle);


    //                          -> hlShuffle

    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23, 101, 17"));

    // set up cardButton
    QFont font;
    font.setPixelSize(40);


    auto* card = new QPushButton;
    card->setFont(font);
    card->setMinimumSize(QSize(128,192));
    card->setMaximumSize(QSize(128,192));
    card->setText("");
    card->setStyleSheet("border-image:url(:/new/Media/Media/cardback.png)");
    hlMain->addWidget(card); // add button to layout

    //connect(card, &QPushButton::clicked, this, &MainView::centralWidget);

    // set up shuffleButton

    auto* shuffle = new QPushButton;
    shuffle->setText("Shuffle");
    shuffle->setMinimumSize(QSize(128,30));
    shuffle->setMaximumSize(QSize(128,30));
    shuffle->setStyleSheet(QStringLiteral("background-color:lightsteelblue"));

    hlShuffle->addWidget(shuffle); // add button to layout
    //connect(shuffle, &QPushButton::clicked, this, &MainView::centralWidget);

}

MainView::~MainView()
{
    delete ui;
}
