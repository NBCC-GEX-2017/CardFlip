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

    // set up model Deck deck; deck shuffle

    // set up layouts
    //  central widget -> vlMain -> hlCard
    //                           -> hlShuffle
    auto vlMain = new QVBoxLayout(ui->centralWidget);
    auto hlCard = new QHBoxLayout();
    vlMain->addLayout(hlCard);
    auto hlShuffle = new QHBoxLayout();
    vlMain->addLayout(hlShuffle);

    ui->centralWidget->setStyleSheet("background-color:green;");

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
    auto shuffleButton = new QPushButton();
    shuffleButton->setText("Shuffle");
    shuffleButton->setMinimumSize(QSize(128,20));
    shuffleButton->setMaximumSize(QSize(128,20));
    shuffleButton->setStyleSheet(QStringLiteral("border-color:lightsteelblue"));
    hlShuffle->addWidget(shuffleButton);

}

MainView::~MainView()
{
    delete ui;
}
