#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Model/Card.h"
#include "Model/Deck.h"

class Game
{
public:
    Game(int numberOfCards, Deck& deck);

    CardPtr getCard(int index);
    void selectCard(int index);

private:
    std::vector<CardPtr> cards;
};

#endif // GAME_H
