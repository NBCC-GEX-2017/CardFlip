#ifndef MATCHINGGAME_H
#define MATCHINGGAME_H

#include<vector>
#include "Model/Card.h"
#include "Model/Deck.h"

class MatchingGame
{
public:
    MatchingGame(int numberOfCards, Deck& deck);

    void selectCard(int index);
    CardPtr getCard(int index);

private:
    std::vector<CardPtr> cards;
};

#endif // MATCHINGGAME_H
