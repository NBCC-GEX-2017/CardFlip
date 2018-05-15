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


    // set up model Deck deckl deck.shuffle


    QFont font;

    font.setPixelSize(40);


    auto* card = new QPushButton;
    card->setFont(font);
    card->setMaximumSize(QSize(128,192));
    card->setMinimumSize(QSize(128,192));
    card->setText("");
    card->setStyleSheet("border-image:url(:/media/Media/cardback.png)");

    auto* verticalLayoutMain = new QVBoxLayout(ui->centralWidget);
    auto* gridLayout = new QGridLayout();
    verticalLayoutMain->addLayout(gridLayout);
    gridLayout->addWidget(card);

    //set up shuffle button
    auto* shuffButton = new QPushButton;
    shuffButton->setText("Shuffle me");
    shuffButton->setMaximumSize(QSize(70,20));
    shuffButton->setMaximumSize(QSize(70,20));
    gridLayout->addWidget(shuffButton);

    shuffButton->setStyleSheet(QStringLiteral("background-color:rgb(249, 252, 251);"));

    auto gridLayoutSpace = new QGridLayout();
    verticalLayoutMain->addLayout(gridLayoutSpace);


}

MainView::~MainView()
{
    delete ui;
}
