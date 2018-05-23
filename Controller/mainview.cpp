/*
* @file
* @author Jhon Romero.
* @version 1.0
*
* @section LICENSE
*
*
* Copyright 2018 Jhon Romero
* Permission to use, copy, modify, and/or distribute this software for
* any purpose with or without fee is hereby granted, provided that the
* above copyright notice and this permission notice appear in all copies.
*
* THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
* WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
* ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
* WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
* ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
* OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
* @section Academic Integrity
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*/

#include "Controller/mainview.h"
#include "ui_mainview.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QDesktopWidget>
#include <QFont>
#include "View/cardqpushbutton.h"

const int ROWS=4;
const int COLUMNS=8;

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    this->setWindowTitle("Memory game");//window title

    QDesktopWidget dw;

    //set size of the window
    int x=dw.width()*0.7;
    int y=dw.height()*0.8;

    this->setFixedSize(x,y);

    game = new Game(ROWS*COLUMNS);

    //set up layout
    auto vlmain= new QVBoxLayout(ui->centralWidget);

    auto* grid = new QGridLayout();
    auto hlLblBtn = new QHBoxLayout();

    vlmain->addLayout(grid);
    vlmain->addLayout(hlLblBtn);

    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23,101,17)"));

    //set up cards
    for(int i=0;i<ROWS*COLUMNS;i++){

        QFont font;
        font.setPixelSize(40);

        auto btn = new CardQPushButton(i);
        grid->addWidget(btn,i/COLUMNS,i%COLUMNS);

        btn->setFont(font);
        btn->setMinimumSize(QSize(100,150));
        btn->setMaximumSize(QSize(100,150));
        btn->setText("");
        btn->setStyleSheet("border-image:url(:/media/Media/cardback.png)");

        //connect button
        connect(btn,
                &QPushButton::clicked,
                this,
                &MainView::onCardClick);

        cardDisplayBtns.push_back(btn);

    }

    //set up score label
    scoreLabel= new QLabel();

    QFont font("Comic Sans MS", 14, QFont::Bold);

    scoreLabel->setText("Score: " +QString::number(game->getScore()));
    scoreLabel->setMinimumSize(QSize(128,20));
    scoreLabel->setMaximumSize(QSize(128,20));
    scoreLabel->setFont(font);
    hlLblBtn->addWidget(scoreLabel);



    // set up shuffle button
    auto newShuffleBtn= new QPushButton();

    newShuffleBtn->setText("Shuffle");
    newShuffleBtn->setStyleSheet(QStringLiteral("background-color:grey"));
    newShuffleBtn->setMinimumSize(QSize(128,20));
    newShuffleBtn->setMaximumSize(QSize(128,20));


    hlLblBtn->addStretch(1);

    hlLblBtn->addWidget(newShuffleBtn);

    connect(newShuffleBtn,
            &QPushButton::clicked,
            this,
            [this](){delete (game); game = new Game(ROWS*COLUMNS); drawView();});





}

MainView::~MainView()
{
    delete ui;
}

void MainView::onCardClick()
{
    auto* btn= dynamic_cast<CardQPushButton*>(sender());//address of the sender pointer, returns a q object pointer

    game->flipCardN(btn->getIndex());
    drawView();
}

void MainView::drawView()
{

    for(auto& c: cardDisplayBtns ){

        CardPtr card= game->getCardN(getIndexOfPtr(c));

        if(card->isMatched()){
            c->setText(QString::fromStdString(card->toString()));
            if(card->getColor()==CardColor::Red)
                c->setStyleSheet("border-image:url(:/media/Media/cardfrontGray.png); color: red;");
            else
                c->setStyleSheet("border-image:url(:/media/Media/cardfrontGray.png); color: black;");
        }
        else{

            if(card->isFlipped()){
                if(card->getColor()==CardColor::Red)
                {
                    c->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: red;");


                }
                else{
                    c->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color: black;");
                }
                c->setText(QString::fromStdString(card->toString()));

            }
            else{

                c->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
                c->setText("");
            }

        }

    }

    scoreLabel->setText("Score: " +QString::number(game->getScore()));


}

int MainView::getIndexOfPtr(CardQPushButton *ptr) const
{
    auto itr = std::find_if(cardDisplayBtns.begin(),cardDisplayBtns.end(),
                 [ptr](CardQPushButton* p){
                    return (p==ptr);

    });

    int index{0};
    if(itr!= cardDisplayBtns.end()){

        index=itr-cardDisplayBtns.begin();
    }

    return index;

}


