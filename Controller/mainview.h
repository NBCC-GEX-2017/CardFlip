#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "Model/Deck.h"
#include <memory>
#include <QPushButton>
#include <QLabel>
#include <Model/game.h>


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

private slots:
    void onCardClick();

private:
    void drawView();

private:
    int getIndexOfPtr(CardQPushButton* ptr) const;

private:
    Ui::MainView *ui;
    std::unique_ptr<Deck> deck;
    QPushButton* cardDisplayBtn;
    QLabel* scoreLabel;
    Game* game;
    //std::vector<QPushButton*> cardDisplayBtns;
    std::vector<CardQPushButton*> cardDisplayBtns;


};

#endif // MAINVIEW_H
