#ifndef GAME_H
#define GAME_H
#include "Model/Card.h"
#include <vector>
#include <memory>

using CardPtr = std::shared_ptr<Card>;
class Game
{
public:
    Game();
    void setCard(CardPtr card) { _board.push_back(card);}
    void setCard(int i, CardPtr card) { _board[i] = card;}
    CardPtr getCard(int i) { return _board[i];}
    void flipCard(int i) { _board[i]->flip();}
    bool isFlipped(int i) {return _board[i]->isFlipped();}
    bool isMatched(int i) {return _board[i]->isMatched();}
    void setMatched(int i) {_board[i]->setMatched();}
    Suit getSuit(int i) {return _board[i]->suit;}
    Face getFace(int i) {return _board[i]->face;}
    CardColor getCardColor(int i) {return _board[i]->getColor();}
    std::string getText(int i) {return _board[i]->toString();}
    void addPoints(int point){ _points+= point;}
    int getPoints() const {return _points;}
private:
    std::vector<CardPtr> _board;
    int _points{0};
};

#endif // GAME_H
