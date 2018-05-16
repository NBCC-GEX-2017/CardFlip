#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "Model/Deck.h"
#include <memory>
#include <vector>
#include "Model/matchinggame.h"


class CardQPushButton;

namespace Ui {
class MainView;
}

class QPushButton;


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
    Ui::MainView *ui;

    std::unique_ptr<Deck> deck;
    //QPushButton* cardDisplayBtn;//change to vector deal 32 card and change a layout to grid
    std::vector<CardQPushButton*> cardDisplayBtns;
    //MatchingGame* game;
    std::unique_ptr<MatchingGame>game;
    //MatchingGame* game;
};

#endif // MAINVIEW_H
