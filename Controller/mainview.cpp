#include "mainview.h"
#include "ui_mainview.h"
#include <QPushbutton>
#include <QString>
#include <QFont>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPalette>
#include "View/cardqpushbutton.h"

const int CARD_COLS = 8;
const int CARD_ROWS = 4;


MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    deck = std::unique_ptr<Deck>(new Deck());  //
    deck->shuffle();                           //

    matchingGame = std::unique_ptr<MatchingGame>(new MatchingGame(CARD_ROWS * CARD_COLS, *deck));

    auto* vlMain = new QVBoxLayout(ui->centralWidget);
    auto* cardGrid = new QGridLayout();
    vlMain->addLayout(cardGrid);
    vlMain->addSpacing(15);

    QFont font;
    font.setPixelSize(50);
    font.setBold(true);



    for(int i=0;i<(CARD_COLS * CARD_ROWS);i++){
        auto buttons = new CardQPushButton(i);
        buttons->setFont(font);
        buttons->setMaximumSize(QSize(QSize(192,288)));
        buttons->setMinimumSize(QSize(QSize(192,288)));
        buttons->setText("");
        buttons->setStyleSheet("border-image:url(:/media/Media/cardback.png)");

        cardGrid->addWidget(buttons, i/CARD_COLS, i%CARD_COLS);
        btn.push_back(buttons);

        connect(buttons,
                &CardQPushButton::clicked,
                this,
                &MainView::onCardClick);

    }

    QFont font1;
    font1.setPixelSize(30);
    font1.setBold(true);

    auto* btnGrid = new QGridLayout();
    vlMain->addLayout(btnGrid);

    auto newGameButton = new QPushButton();
    newGameButton->setText("New Game");
    newGameButton->setFont(font1);
    newGameButton->setMinimumSize(QSize(192,80));
    newGameButton->setMaximumSize(QSize(192,80));
    newGameButton->setStyleSheet(QStringLiteral("background-color:aliceblue"));
    btnGrid->addWidget(newGameButton, 0, 1);

    connect(newGameButton,
            &QPushButton::clicked,
            this,
            [this](){
            deck->shuffle();
            matchingGame = std::unique_ptr<MatchingGame>(new MatchingGame(CARD_ROWS * CARD_COLS, *deck));
            drawView();});


    _displayCount = new QLabel;
    _displayCount->setText(QStringLiteral("Your Point: %1").arg(matchingGame->getScore()));
    _displayCount->setFont(font1);
    btnGrid->addWidget(_displayCount, 0, 0);
}


MainView::~MainView()
{
    delete ui;
}


void MainView::onCardClick(){
    auto fromButton = sender();
    CardQPushButton* fromCardButton = dynamic_cast<CardQPushButton*>(fromButton);
    matchingGame->selectCardN(fromCardButton->getIndex());

    drawView();
}

void MainView::drawView() {

    for(auto& c : btn){
        CardPtr card = matchingGame->getSquareN(c->getIndex());
        if(card->isMatched()){
            c->setText(QString::fromStdString(card->toString()));
            if(card->getColor() == CardColor::Red){
                c->setStyleSheet("border-image:url(:/media/Media/cardfrontGray.png); color:red;");
            }else{
                c->setStyleSheet("border-image:url(:/media/Media/cardfrontGray.png); color:black;");
            }

        }else{
            if(card->isSelected()){
                if(card->getColor() == CardColor::Red ){
                    c->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:red;");
                }else {
                    c->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:black;");
                }
                c->setText(QString::fromStdString(card->toString()));
            } else {
                c->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
                c->setText("");
            }
        }
    }

    _displayCount->setText(QStringLiteral("Your Point: %1").arg(matchingGame->getScore()));
}
