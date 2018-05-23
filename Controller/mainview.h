#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <memory>
#include <vector>


class QLabel;
class MatchingGame;
class Deck;

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

    QLabel* gameScore;
    std::unique_ptr<Deck> deck;
    std::unique_ptr<MatchingGame> game;

    std::vector<CardQPushButton*> cardButtons;

};

#endif // MAINVIEW_H
