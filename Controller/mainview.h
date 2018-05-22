#ifndef MAINVIEW_H
#define MAINVIEW_H
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QFont>
#include "Model/Deck.h"
#include <memory>
#include <QMainWindow>
#include <vector>
#include "View/cardqpushbutton.h"
#include "Controller/game.h"
#include <QLabel>

namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = 0);
    ~MainView();

private slots:
    void changeCard();
    void shuffle();

private:
    Ui::MainView *ui;
    std::unique_ptr<Deck> _deck;
    QPushButton* _shuffleButton;
    Game* game;
    std::vector<CardQPushButton*> _cardBtn;
    int currentCard{0};
    void drawView();
    QLabel* _pointsLabel;
    QLabel* _highScore;
    QLabel* _message;
    QLabel* _availableMoves;
};

#endif // MAINVIEW_H
