#ifndef MATCHINGGAME_H
#define MATCHINGGAME_H
#include "Model/Card.h"
#include "Model/Deck.h"
#include "View/cardqpushbutton.h"
#include <vector>

class MatchingGame
{
public:
    MatchingGame();

    CardPtr getSquareN(int i);          //
    void flipCard(int i);               //

private:
    std::vector<CardPtr> cards;

};

#endif // MATCHINGGAME_H
