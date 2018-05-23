#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <Model/Deck.h>
#include <memory>
#include <vector>

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
    CardQPushButton* cardDisplayBtn;
    std::vector<CardQPushButton*> cardButtons;
};

#endif // MAINVIEW_H
