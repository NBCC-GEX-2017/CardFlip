#include "Controller/mainview.h"
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

    //set up the Deck deck; deck.shuffle

    //set up layout
    auto vlmain= new QVBoxLayout(ui->centralWidget);

    auto hlCard = new QHBoxLayout();
    auto hlShuffle = new QHBoxLayout();

    vlmain->addLayout(hlCard);
    vlmain->addLayout(hlShuffle);

    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23,101,17)"));
    // central widget -> vlMain -> hlCard
    //                          -> hlShuffle

    // set up cardButton
    QFont font;
    font.setPixelSize(40);

    auto* card = new QPushButton;
    card->setFont(font);
    card->setMinimumSize(QSize(128,192));
    card->setMaximumSize(QSize(128,192));
    card->setText("");
    card->setStyleSheet("border-image:url(:/media/Media/cardback.png)");

    hlCard->addWidget(card);


    // set up shuffle button
    auto newShuffleBtn= new QPushButton();

    newShuffleBtn->setText("Shuffle");
    newShuffleBtn->setStyleSheet(QStringLiteral("background-color:grey"));
    newShuffleBtn->setMinimumSize(QSize(128,20));
    newShuffleBtn->setMaximumSize(QSize(128,20));

    hlShuffle->addWidget(newShuffleBtn);





}

MainView::~MainView()
{
    delete ui;
}
