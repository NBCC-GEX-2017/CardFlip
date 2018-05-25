#ifndef MATCHINGGAME_H
#define MATCHINGGAME_H

#include "Model/Card.h"
#include "Model/Deck.h"
#include <vector>

class matchingGame
{
public:
    matchingGame(int numberOfCards, Deck& deck);

    CardPtr getCardN(int index);
    void selectCardN(int index);

private:
    std::vector<CardPtr> cards;

};

#endif // MATCHINGGAME_H
