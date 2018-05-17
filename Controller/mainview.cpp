#include "Controller/mainview.h"
#include "ui_mainview.h"

const int CARD_ROWS = 4;
const int CARD_COLS = 8;

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    _deck = std::unique_ptr<Deck>(new Deck());
    _deck->shuffle();

    game = new Game;

    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23,101,17)"));

    auto* vlmain = new QVBoxLayout(ui->centralWidget);

    auto* glCard = new QGridLayout();
    auto* hlShuffle = new QHBoxLayout();

    vlmain->addLayout(glCard);
    vlmain->addLayout(hlShuffle);

    for(int i = 0; i < CARD_COLS*CARD_ROWS; i++){
        auto cardBtn = new CardQPushButton(i);

        connect(cardBtn,
                &CardQPushButton::clicked,
                this,
                &MainView::changeCard);

        glCard->addWidget(cardBtn, i/CARD_COLS, i%CARD_COLS);
        game->setCard(_deck->drawCard());
        _cardBtn.push_back(cardBtn);
    }

    _shuffleButton = new QPushButton();
    _shuffleButton->setText("Shuffle");
    _shuffleButton->setMinimumSize(QSize(128,20));
    _shuffleButton->setMaximumSize(QSize(128,20));
    _shuffleButton->setStyleSheet(QStringLiteral("background-color:lightgray"));
    hlShuffle->addWidget(_shuffleButton);

    connect(_shuffleButton,
            &QPushButton::clicked,
            this,
            [this](){_deck->shuffle();drawView();});

    _pointsLabel = new QLabel;
    _pointsLabel->setText(QStringLiteral("Points: %1").arg(game->getPoints()));

    hlShuffle->addWidget(_pointsLabel);
}

MainView::~MainView()
{
    delete ui;
}

void MainView::changeCard()
{
    auto* btn = dynamic_cast<CardQPushButton*>(sender());
    bool match = false;
    bool hasFlipped = false;
    for(int i =0; i < _cardBtn.size(); i++){
        if(i != btn->getIndex()){
            if(game->isFlipped(i) && !game->isMatched(i)) {
                hasFlipped = true;
                if(game->getSuit(i) == game->getSuit(btn->getIndex()))
                {
                    game->setMatched(i);
                    game->setMatched(btn->getIndex());
                    game->addPoints(3);
                    match = true;
                }
                else if(game->getFace(i) == game->getFace(btn->getIndex()))
                {
                    game->setMatched(i);
                    game->setMatched(btn->getIndex());
                    game->addPoints(5);
                    match = true;
                }
                game->flipCard(i);
            }
        }
    }
    if(!match && hasFlipped){
        game->addPoints(-1);
    }
    game->flipCard(btn->getIndex());
    drawView();
}

void MainView::shuffle()
{
   _deck->shuffle();
   for(int i =0; i < _cardBtn.size(); i++){
        game->setCard(i, _deck->drawCard());
   }
    drawView();
}

void MainView::drawView()
{
    for(int i =0; i < _cardBtn.size(); i++){
        if(game->isFlipped(i) || game->isMatched(i)){
            if(game->getCardColor(i) == CardColor::Red){
                _cardBtn[i]->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardfront.png);color:red;"));
            }else{
                _cardBtn[i]->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardfront.png);color:black;"));
            }
            _cardBtn[i]->setText(QString::fromStdString(game->getText(i)));
        }
        else
        {
            _cardBtn[i]->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardback.png)"));
            _cardBtn[i]->setText("");
        }
    }
    _pointsLabel->setText(QStringLiteral("Points: %1").arg(game->getPoints()));

}
