#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <memory>
#include <vector>
#include "Model/Deck.h"
#include "Model/game.h"


namespace Ui {
class MainView;
}

class CardButton;

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private:
    void drawView();
    void onCardClick();

private:
    Ui::MainView *ui;

    std::unique_ptr<Deck> deck;
    std::unique_ptr<Game> game;
    std::vector<CardButton*> cardButtons;

};

#endif // MAINVIEW_H
