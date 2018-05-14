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

    //set up model Deck deck; Deck.shuffle();

    // set up layouts
    // central widget -> vlMain -> hlCard
    //                          -> hlShuffle
    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23,101,17)"));
    auto vlmain = new QVBoxLayout(ui->centralWidget);//QVBoxLayout* vlmain
    auto hlcard = new QHBoxLayout();
    vlmain->addLayout(hlcard);
    auto hlshuffle = new QHBoxLayout();
    vlmain->addLayout(hlshuffle);

    // set up cardButton
    QFont font;
    font.setPixelSize(40);

    auto* card = new QPushButton;
    card->setFont(font);
    card->setMinimumSize(QSize(128,192));
    card->setMaximumSize(QSize(128,192));
    card->setText("");
    card->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
    //card->setStyleSheet("border-image:url(qrc:/media/Media/cardback.png)");
    //card->setStyleSheet("QWidget{background-image:url(:/media/Media/cardback.png)}");
    //card->setStyleSheet("background-image:url(qrc:/media/Media/cardback.png)");
    //card->setStyleSheet("background-image:url(:/media/Media/cardback.png)");

    hlcard->addWidget(card);

    // set up shuffle button
    auto* shufflebtn = new QPushButton;
    shufflebtn->setText("SHUFFLE");
    shufflebtn->setMinimumSize(QSize(128,25));
    shufflebtn->setMaximumSize(QSize(128,25));
    shufflebtn->setStyleSheet(QStringLiteral("background-color:lightsteelblue"));
    hlshuffle->addWidget(shufflebtn);
}

MainView::~MainView()
{
    delete ui;
}
