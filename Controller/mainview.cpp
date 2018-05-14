#include "Controller/mainview.h"
#include "ui_mainview.h"
#include <QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QString>
#include<QFont>


MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    // set up model Deck deck deck.shuffle

    // set up Layouts ,
    // central widge -> vlmain -> hlCard
    auto vlmain = new QVBoxLayout(ui->centralWidget);
    auto hlcard= new QHBoxLayout();
    vlmain->addLayout(hlcard);
    auto hlshuffle=new QHBoxLayout();
    vlmain->addLayout(hlshuffle);
    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(55,123,45)"));

    // button to shuffle      ->  hlShuffle
    QFont shuffle;
    shuffle.setPixelSize(12);
    auto* shufflebutton=new QPushButton();
    shufflebutton->setFont(shuffle);
    shufflebutton->setMinimumSize(QSize(120,30));
    shufflebutton->setMaximumSize(QSize(120,30));
    shufflebutton->setText("SHUFFLE!!!!");
    shufflebutton->setStyleSheet(QStringLiteral("background-color:rgb(lightGray)"));
    // set up cardButton
    QFont font;
    font.setPixelSize(40);

    auto* card = new QPushButton;
    card ->setFont(font);
    card->setMinimumSize(QSize(128,192));
    card->setMaximumSize(QSize(128,192));
    card->setText("");
    card->setStyleSheet("border-image:url(:/new/prefix1/Media/cardback.png)");

    hlcard->addWidget(card);
    hlshuffle->addWidget(shufflebutton);
    //set up a Shuffle button






}

MainView::~MainView()
{
    delete ui;
}
