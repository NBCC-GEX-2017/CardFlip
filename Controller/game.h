#ifndef GAME_H
#define GAME_H
#include<Model/Card.h>
#include<memory>
#include<vector>
using CardPtr = std::shared_ptr<Card>;
class Game
{
public:
    Game();
    void setCard(CardPtr card);
    void setFlip(int flipped);// because
    CardColor getColor(int color);
    std::string getText(int text);
    bool isFlipped(int flipped);
    bool isMatched(int flipped);
    void shuffle();
    int getScore();
private:
    std::vector<CardPtr>_gamecards;
    int _score=0;
};

#endif // GAME_H
