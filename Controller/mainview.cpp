#include "Controller/mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    //set up mode Deck deck; deck.shuffle();

    //Deck deck;

    //set up layouts
    //central wigdget -> vlmain -> hlCard
    //                          -> hlShuffle

    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23,101,17)"));

    auto* vlmain = new QVBoxLayout(ui->centralWidget);

    auto* hlCard = new QHBoxLayout();
    auto* hlShuffle = new QHBoxLayout();

    vlmain->addLayout(hlCard);
    vlmain->addLayout(hlShuffle);

    //set up card button
    card = new QPushButton();

    QFont font;
    font.setPixelSize(40);

    card->setFont(font);
    card->setMinimumSize(QSize(128,192));
    card->setMaximumSize(QSize(128,192));
    card->setText("");
    card->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardback.png)"));

    connect(card,
            &QPushButton::clicked,
            this,
            &MainView::changeCard);

    hlCard->addWidget(card);

    //set up shuffle button

    shuffleButton = new QPushButton();
    shuffleButton->setText("Shuffle");
    shuffleButton->setMinimumSize(QSize(128,20));
    shuffleButton->setMaximumSize(QSize(128,20));
    shuffleButton->setStyleSheet(QStringLiteral("background-color:lightgray"));
    hlShuffle->addWidget(shuffleButton);

    connect(shuffleButton,
            &QPushButton::clicked,
            this,
            &MainView::changeCard);

    //Button to shuffle


}

MainView::~MainView()
{
    delete ui;
}

void MainView::changeCard()
{
    if(currentCard){
        card->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardback.png)"));
        currentCard = 0;
    }else {
        card->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardfront.png)"));
        currentCard = 1;
    }
}

void MainView::drawView()
{

}
