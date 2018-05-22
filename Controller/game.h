#ifndef GAME_H
#define GAME_H
#include "Model/Card.h"
#include <vector>
#include <memory>
#include <map>
#include <algorithm>
#include <QDebug>

using CardPtr = std::shared_ptr<Card>;
class Game
{
public:
    Game();
    void setCard(CardPtr card) { _board.push_back(card); _SuitMap[card->suit]++; _FaceMap[card->face]++;}
    void setCard(int i, CardPtr card) { _board[i] = card;}
    CardPtr getCard(int i) { return _board[i];}
    void flipCard(int i) { _board[i]->flip();}
    bool isFlipped(int i) {return _board[i]->isFlipped();}
    bool isMatched(int i) {return _board[i]->isMatched();}
    void setMatched(int i) {_board[i]->setMatched();}
    Suit getSuit(int i) const {return _board[i]->suit;}
    Face getFace(int i) const {return _board[i]->face;}
    CardColor getCardColor(int i) const {return _board[i]->getColor();}
    std::string getText(int i) const {return _board[i]->toString();}
    void addPoints(int point){ _points+= point;}
    int getPoints() const {return _points;}
    void clickCard(int cardID);
    bool moveAvailable();
    int  countAvailableMoves() const;
    void reset();
    void flipAll();
    int getHighScore() const {return _highScore;}
    void setHighScore();
private:
    std::vector<CardPtr> _board;
    std::map<Suit, int> _SuitMap;
    std::map<Face, int> _FaceMap;
    int _points{0};
    int _highScore{0};
};

#endif // GAME_H
