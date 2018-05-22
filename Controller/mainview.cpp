#include "Controller/mainview.h"
#include "ui_mainview.h"

const int CARD_ROWS = 4;
const int CARD_COLS = 8;

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    srand(time(0));
    _deck = std::unique_ptr<Deck>(new Deck());
    _deck->shuffle();

    game = new Game;

    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23,101,17)"));

    auto* vlmain = new QVBoxLayout(ui->centralWidget);

    auto* glCard = new QGridLayout();
    auto* hlShuffle = new QHBoxLayout();
    auto* hlMessage = new QHBoxLayout();
    vlmain->addLayout(glCard);
    vlmain->addLayout(hlShuffle);
    vlmain->addLayout(hlMessage);

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
            &MainView::shuffle);

    QFont font;
    font.setPixelSize(20);
    _pointsLabel = new QLabel;
    _pointsLabel->setText(QStringLiteral("Points: %1").arg(game->getPoints()));
    _pointsLabel->setStyleSheet("color:white;");
    _pointsLabel->setFont(font);

    hlShuffle->addWidget(_pointsLabel);
    hlShuffle->addStretch(1);

    _availableMoves = new QLabel;
    _availableMoves->setFont(font);
    _availableMoves->setText(QStringLiteral("Available moves: %1").arg(game->countAvailableMoves()));
    _availableMoves->setStyleSheet("color: white;");

    hlShuffle->addWidget(_availableMoves);
    hlShuffle->addStretch(1);

    _highScore = new QLabel;
    _highScore->setFont(font);
    _highScore->setText(QStringLiteral("HighScore: %1").arg(game->getHighScore()));
    _highScore->setStyleSheet("color:blue;");

    hlShuffle->addWidget(_highScore);

    _message = new QLabel;
    _message->setText("");
    _message->setFont(font);
    hlMessage->addStretch(1);
    hlMessage->addWidget(_message);
    hlMessage->addStretch(1);
}

MainView::~MainView()
{
    delete ui;
}

void MainView::changeCard()
{
    auto* btn = dynamic_cast<CardQPushButton*>(sender());
    game->clickCard(btn->getIndex());
    drawView();
}

void MainView::shuffle()
{
   game->reset();
   _deck = nullptr;
   _deck = std::unique_ptr<Deck>(new Deck());
   _deck->shuffle();
   for(int i =0; i < _cardBtn.size(); i++){
        game->setCard(_deck->drawCard());
   }
    drawView();
}

void MainView::drawView()
{
    _message->setText("");
    _message->setStyleSheet(QStringLiteral("background-color:rgb(23,101,17)"));
    _pointsLabel->setText(QStringLiteral("Points: %1").arg(game->getPoints()));
    _highScore->setText(QStringLiteral("HighScore: %1").arg(game->getHighScore()));
    _availableMoves->setText(QStringLiteral("Available moves: %1").arg(game->countAvailableMoves()));
    _availableMoves->setStyleSheet("color: white;");
    if(game->countAvailableMoves() < 7){
        _availableMoves->setStyleSheet("color: yellow;");
    }
    if(game->countAvailableMoves() < 3){
        _availableMoves->setStyleSheet("color: red;");
    }

    if(!game->moveAvailable()){
        _message->setText("No more available moves");
        _message->setStyleSheet("background-color: yellow; color:red;");
        game->flipAll();
    }
    for(int i =0; i < _cardBtn.size(); i++){
        if(game->isFlipped(i) || game->isMatched(i)){
            if(game->getCardColor(i) == CardColor::Red){
                if(game->isMatched(i)){
                    _cardBtn[i]->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardfrontGray.png);color:red;"));
                }else{
                    _cardBtn[i]->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardfront.png);color:red;"));
                }
            }else{
                if(game->isMatched(i)){
                    _cardBtn[i]->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardfrontGray.png);color:black;"));
                }else{
                    _cardBtn[i]->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardfront.png);color:black;"));
                }
            }
            _cardBtn[i]->setText(QString::fromStdString(game->getText(i)));
        }
        else
        {
            _cardBtn[i]->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardback.png)"));
            _cardBtn[i]->setText("");
        }
    }
}
