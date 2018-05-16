#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "Model/Deck.h"
#include <memory>
#include <QPushButton>
#include "Model/matchinggame.h"

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
    Ui::MainView *ui;
    std::unique_ptr<Deck> deck;
    std::vector<CardQPushButton*> cardDisplayBtns;
    MatchingGame *game;

};

#endif // MAINVIEW_H
