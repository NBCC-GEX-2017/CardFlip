#include "mainview.h"
#include "ui_mainview.h"
#include <QPushbutton>
#include <QVboxLayout>
#include <QHboxLayout>
#include <QString>
#include <QFont>

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    // set up model Deck deck; deck.shuffle

    // set up layouts
    //  central widget -> vlMain -> hlCard
    //                           -> hlShuffle
    auto vlmain = new QVBoxLayout(ui->centralWidget);

    auto hlcard = new QHBoxLayout();
    vlmain->addLayout(hlcard);

    auto hlshuffle = new QHBoxLayout();
    vlmain->addLayout(hlshuffle);

    //vlmain->addSpacing(100);

    auto hl_space_demo = new QHBoxLayout();
    vlmain->addLayout(hl_space_demo);


    vlmain->addStretch(1);
    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:darkolivegreen"));

    // set up cardButton
    QFont font;
    font.setPixelSize(40);

    auto* card = new QPushButton;
    card->setFont(font);
    card->setMinimumSize(QSize(128,192));
    card->setMaximumSize(QSize(128,192));
    card->setText("");
    card->setStyleSheet("border-image:url(:/media/Media/cardback.png)");

    hlcard->addWidget(card);
    hlcard->addStretch(1);

    // set up shuffle button

    auto shuffleButton = new QPushButton();
    shuffleButton->setText("Shuffle");
    shuffleButton->setMinimumSize(QSize(128,20));
    shuffleButton->setMaximumSize(QSize(128,20));
    shuffleButton->setStyleSheet(QStringLiteral("background-color:aliceblue"));

    hlshuffle->addStretch(1);
    hlshuffle->addWidget(shuffleButton);

    // add some more buttons
    for (int i=0;i<5;++i)
    {
        auto btn = new QPushButton();
        btn->setText("X");
        btn->setMinimumSize(QSize(20,20));
        btn->setMaximumSize(QSize(20,20));
        btn->setStyleSheet(QStringLiteral("background-color:plum"));
        hl_space_demo->addWidget(btn);
    }

    hl_space_demo->addStretch(1);

    // add some more buttons
    for (int i=0;i<5;++i)
    {
        auto btn = new QPushButton();
        btn->setText("X");
        btn->setMinimumSize(QSize(20,20));
        btn->setMaximumSize(QSize(20,20));
        btn->setStyleSheet(QStringLiteral("background-color:plum"));
        hl_space_demo->addWidget(btn);
        hl_space_demo->addSpacing(20);
    }

    hl_space_demo->addStrut(2000);

}


MainView::~MainView()
{
    delete ui;
}
