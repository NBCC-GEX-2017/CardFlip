#ifndef GAME_H
#define GAME_H
#include <memory>
#include "Model/Deck.h"
#include "Model/Card.h"

class Game
{
public:
    Game();


    void setFlipped(int index);
    void setCardAtN(CardPtr card);
    std::string getText(int index);
    CardColor getCardColor(int index);
    bool isFlipped(int index);
private:

    std::vector<CardPtr> _cards;
};

using CardPtr = std::shared_ptr<Card>;

#endif // GAME_H
