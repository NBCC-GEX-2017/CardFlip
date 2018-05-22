#include "mainview.h"
#include "ui_mainview.h"
#include <QPushbutton>
#include <QVboxLayout>
#include <QHboxLayout>
#include <QString>
#include <QFont>
#include <QGridLayout>
#include "View/cardqpushbutton.h"

const int CARD_COLS = 8;
const int CARD_ROW = 4;


MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    matchingGame = new MatchingGame();

    deck = std::unique_ptr<Deck>(new Deck());  //
    deck->shuffle();                           //


    auto* grid = new QGridLayout(ui->centralWidget);
    QFont font;
    font.setPixelSize(40);

    for(int i=0;i<(CARD_COLS * CARD_ROW);i++){
        auto buttons = new CardQPushButton(i);
        //QPushButton* buttons = new QPushButton;
        buttons->setFont(font);
        buttons->setMaximumSize(QSize(QSize(128,192)));
        buttons->setMinimumSize(QSize(QSize(128,192)));
        buttons->setText("");
        buttons->setStyleSheet("border-image:url(:/media/Media/cardback.png)");

        grid->addWidget(buttons, i/CARD_COLS, i%CARD_COLS);
        btn.push_back(buttons);

        connect(buttons,
                &CardQPushButton::clicked,
                this,
                &MainView::onCardClick);

    }

    auto shuffleButton = new QPushButton();
    shuffleButton->setText("Shuffle");
    shuffleButton->setMinimumSize(QSize(128,20));
    shuffleButton->setMaximumSize(QSize(128,20));
    shuffleButton->setStyleSheet(QStringLiteral("background-color:aliceblue"));
    grid->addWidget(shuffleButton);


    connect(shuffleButton,
            &QPushButton::clicked,
            this,
            [this](){deck->shuffle();drawView();});


}


MainView::~MainView()
{
    delete ui;
}


void MainView::onCardClick(){
//    deck->nextCard();

    auto* tmp = dynamic_cast<CardQPushButton*>(sender());
    matchingGame->flipCard(tmp->getIndex());
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
            if(card->isFlipped()){
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


//    for (int i=0;i<32;i++){
//         CardPtr card = matchingGame->getSquareN(btn[i]->getIndex());
//         if(card->isMatched()){
//             btn[i]->setText(QString::fromStdString(card->toString()));
//             if(card->getColor() == CardColor::Red){
//                 btn[i]->setStyleSheet("border-image:url(:/media/Media/cardfrontGray.png); color:red;");
//             }else{
//                 btn[i]->setStyleSheet("border-image:url(:/media/Media/cardfrontGray.png); color:black;");
//             }

//         }else{
//             if(card->isFlipped()){
//                 if(card->getColor() == CardColor::Red ){
//                     btn[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:red;");
//                 }else {
//                     btn[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:black;");
//                 }
//                 btn[i]->setText(QString::fromStdString(card->toString()));
//             } else {
//                 btn[i]->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
//                 btn[i]->setText("");
//             }
//         }
//    }


//    for (int i=0;i<32;i++){
//        if(deck->isFlipped()){
//            if(deck->getCardColor() == CardColor::Red){
//                btn[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:red;");
//            }else {
//                btn[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:black;");
//            }
//            btn[i]->setText(QString::fromStdString(deck->topCardToString()));
//        } else{
//            btn[i]->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
//            btn[i]->setText("");
//        }
//    }

}
