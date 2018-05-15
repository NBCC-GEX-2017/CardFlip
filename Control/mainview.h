#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include "Model/Deck.h"
#include <memory>


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
    QPushButton* cardDisplayBtn;//change to vector,deal 32 cards

};

#endif // MAINVIEW_H
