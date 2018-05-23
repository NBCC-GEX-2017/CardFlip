#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "Model/Deck.h"   //
#include "Model/Card.h"   // //
#include <memory>         //
#include <vector>         //
#include "Model/matchinggame.h" //

namespace Ui {
class MainView;
}

//class QPushButton;
class CardQPushButton;
class MatchingGame;

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private slots:              //
    void onCardClick();     //


private:  //
    void drawView();    //

private:
    Ui::MainView *ui;

    std::unique_ptr<Deck> deck;
    std::unique_ptr<MatchingGame> matchingGame;

    std::vector<CardQPushButton*> btn;
};

#endif // MAINVIEW_H
