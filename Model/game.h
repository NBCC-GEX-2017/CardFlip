#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Model/Card.h"
#include "Model/Deck.h"

class Game
{
public:
    Game(int numberOfCards, Deck& deck);

    CardPtr getCardI(int index);
    void selectCardI(int index);

private:
    std::vector<CardPtr> cards;
    int score;
};

#endif // GAME_H
