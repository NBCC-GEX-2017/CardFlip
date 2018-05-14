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

    //set up model: Deck deck; deck.shuffle


    //set up layouts
    //central widget->vlMain->hlCard
    //                      ->hlShuffle

    QVBoxLayout* vlMain=new QVBoxLayout(ui->centralWidget);
    QHBoxLayout* hlCard=new QHBoxLayout();
    vlMain->addLayout(hlCard);

    QHBoxLayout* hlShuffle=new QHBoxLayout();
    vlMain->addLayout(hlShuffle);

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


    //set up ShuffleButton

    auto* shuffle=new QPushButton;
    shuffle->setText("Shuffle");
    shuffle->setMinimumSize(QSize(128,20));
    shuffle->setMaximumSize(QSize(128,20));
    shuffle->setStyleSheet(QStringLiteral("background-color:lightsteelblue"));


    hlShuffle->addWidget(shuffle);
}

MainView::~MainView()
{
    delete ui;
}
