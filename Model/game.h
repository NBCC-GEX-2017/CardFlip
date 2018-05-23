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
    bool isMatched(int index);

    CardPtr getCardN(int index);
    void    selectCardN(int index);
    int getScore();
private:

    std::vector<CardPtr> _cards;
    int score = 0;
};

using CardPtr = std::shared_ptr<Card>;

#endif // GAME_H
