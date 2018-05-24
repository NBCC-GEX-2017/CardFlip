#ifndef MAINVIEW_H
#define MAINVIEW_H
#include "Controller/game.h"
#include <QMainWindow>
#include "Model/Deck.h"
#include <memory>
#include<vector>
#include<QLabel>
namespace Ui {
class MainView;
}

class CardQPushButton;

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();
private:
    void drawView();

 private slots:
    void onCardClick();

private:

    Ui::MainView *ui;

    std::unique_ptr<Deck> deck;
   // QPushButton* cardDisplaybtn;
     std::vector<CardQPushButton*>cardButtons;
     Game* flippin;
     QLabel* scorepoints;
};

#endif // MAINVIEW_H
