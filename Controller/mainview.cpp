#include "mainview.h"
#include "ui_mainview.h"
#include <QPushbutton>
#include <QVboxLayout>
#include <QHboxLayout>
#include <QString>
#include <QFont>
#include <QGridLayout>


MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    deck = std::unique_ptr<Deck>(new Deck());  //
    deck->shuffle();                           //


    auto* grid = new QGridLayout(ui->centralWidget);
    QFont font;
    font.setPixelSize(40);

    for(int i=0;i<32;i++){
        QPushButton* buttons = new QPushButton();
        buttons->setFont(font);
        buttons->setMaximumSize(QSize(QSize(128,192)));
        buttons->setMinimumSize(QSize(QSize(128,192)));
        buttons->setText("");
        buttons->setStyleSheet("border-image:url(:/media/Media/cardback.png)");

        grid->addWidget(buttons, i/8, i%8);

        connect(buttons,
                &QPushButton::clicked,
                this,
                &MainView::onCardClick);

        btn.push_back(buttons);

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
    deck->nextCard();
    drawView();
}

void MainView::drawView() {

    for (int i=0;i<32;i++){
        if(deck->isFlipped()){
            if(deck->getCardColor() == CardColor::Red){
                btn[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:red;");
            }else {
                btn[i]->setStyleSheet("border-image:url(:/media/Media/cardfront.png); color:black;");
            }
            btn[i]->setText(QString::fromStdString(deck->topCardToString()));
        } else{
            btn[i]->setStyleSheet("border-image:url(:/media/Media/cardback.png)");
            btn[i]->setText("");
        }
    }

}
