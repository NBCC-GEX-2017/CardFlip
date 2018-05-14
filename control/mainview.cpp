#include "mainview.h"
#include "ui_mainview.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFont>
#include <QPalette>

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView)
{
    ui->setupUi(this);
    ui->centralWidget->setStyleSheet(QStringLiteral("background-color:green"));
    auto vlmain = new QVBoxLayout(ui->centralWidget);
    auto hlmain = new QHBoxLayout();
    auto hlmain2 = new QHBoxLayout();
    vlmain->addLayout(hlmain);
    vlmain->addLayout(hlmain2);
    QFont font;
    font.setPixelSize(40);
    auto* card = new QPushButton;
    card->setFont(font);
    card->setMinimumSize(QSize(128,192));
    card->setMaximumSize(QSize(128,192));
    card->setText("");
    card->setStyleSheet("border-image:url(:/new/media/Media/cardback.png)");



    //set up shuffle button
    auto* shuffle = new QPushButton;
    shuffle->setFont(font);
    shuffle->setText("Shuffle");

//    QPalette pal = shuffle->palette();
//    pal.setColor(QPalette::Button,QColor(Qt::green));
//    shuffle->setAutoFillBackground(true);
//    shuffle->setPalette(pal);
//    shuffle->update();


    hlmain->addWidget(card);
    hlmain2->addWidget(shuffle);
}

MainView::~MainView()
{
    delete ui;
}
