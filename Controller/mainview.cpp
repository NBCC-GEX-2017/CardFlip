#include "Controller/mainview.h"
#include "ui_mainview.h"

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);

    _deck = std::unique_ptr<Deck>(new Deck());
    _deck->shuffle();

    //set up mode Deck deck; deck.shuffle();

    //Deck deck;

    //set up layouts
    //central wigdget -> vlmain -> hlCard
    //                          -> hlShuffle

    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:rgb(23,101,17)"));

    auto* vlmain = new QVBoxLayout(ui->centralWidget);

    auto* glCard = new QGridLayout();
    auto* hlShuffle = new QHBoxLayout();

    vlmain->addLayout(glCard);
    vlmain->addLayout(hlShuffle);

    //Homework - Grid
    for(int i = 0; i < 32; i++){
        auto cardBtn = new QPushButton();

        QFont font;
        font.setPixelSize(40);

        cardBtn->setFont(font);
        cardBtn->setMinimumSize(QSize(128,192));
        cardBtn->setMaximumSize(QSize(128,192));
        cardBtn->setText("");
        cardBtn->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardback.png)"));

        connect(cardBtn,
                &QPushButton::clicked,
                this,
                &MainView::changeCard);

        glCard->addWidget(cardBtn, i/8, i%8);
        _cardBtn.push_back(cardBtn);
    }

    //set up shuffle button

    _shuffleButton = new QPushButton();
    _shuffleButton->setText("Shuffle");
    _shuffleButton->setMinimumSize(QSize(128,20));
    _shuffleButton->setMaximumSize(QSize(128,20));
    _shuffleButton->setStyleSheet(QStringLiteral("background-color:lightgray"));
    hlShuffle->addWidget(_shuffleButton);

    /*connect(_shuffleButton,
            &QPushButton::clicked,
            this,
            &MainView::shuffle);*/
    //or
    connect(_shuffleButton,
            &QPushButton::clicked,
            this,
            [this](){_deck->shuffle();drawView();});
}

MainView::~MainView()
{
    delete ui;
}

void MainView::changeCard()
{
    //_deck->nextCard();
    drawView();
    //homework -> only draw view
}

void MainView::shuffle()
{
    _deck->shuffle();
    drawView();
}

void MainView::drawView()
{
    for(int i =0; i < _cardBtn.size(); i++){
        if(_deck->isFlipped()){
            if(_deck->getCardColor() == CardColor::Red){
                _cardBtn[i]->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardfront.png);color:red;"));
            }else{
                _cardBtn[i]->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardfront.png);color:black;"));
            }
            _cardBtn[i]->setText(QString::fromStdString(_deck->topCardToString()));
        }
        else
        {
            _cardBtn[i]->setStyleSheet(QStringLiteral("border-image:url(:/media/Media/cardback.png)"));
            _cardBtn[i]->setText("");
        }
    }

}
