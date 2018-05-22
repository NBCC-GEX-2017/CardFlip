#include "game.h"

Game::Game()
{

}

void Game::clickCard(int cardID)
{
    if(!moveAvailable()){
        return;
    }
    if(isMatched(cardID)){
        return;
    }
    bool match = false;
    bool hasFlipped = false;
    for(int i =0; i < _board.size(); i++){
        if(i != cardID){
            if(isFlipped(i) && !isMatched(i)) {
                hasFlipped = true;
                if(getSuit(i) == getSuit(cardID))
                {
                    setMatched(i);
                    setMatched(cardID);
                    addPoints(3);
                    match = true;
                    _SuitMap[getSuit(i)]-=2;
                    _FaceMap[getFace(i)]--;
                    _FaceMap[getFace(cardID)]--;
                }
                else if(getFace(i) == getFace(cardID))
                {
                    setMatched(i);
                    setMatched(cardID);
                    addPoints(5);
                    match = true;
                    _FaceMap[getFace(i)]-=2;
                    _SuitMap[getSuit(i)]--;
                    _SuitMap[getSuit(cardID)]--;
                }
                flipCard(i);
            }
        }
    }
    if(!match && hasFlipped){
        addPoints(-1);
    }
    flipCard(cardID);
}

bool Game::moveAvailable()
{
    bool tmp = (
                std::any_of(
                _SuitMap.begin(),
                _SuitMap.end(),
                [](auto e){ return (e.second > 1);}
                )
                ||
                std::any_of(
                _FaceMap.begin(),
                _FaceMap.end(),
                [](auto e){ return (e.second > 1);}
                )
                );
    if(!tmp){
        setHighScore();
    }
    return tmp;
}

int Game::countAvailableMoves() const
{
    return  std::count_if(
            _SuitMap.begin(),
            _SuitMap.end(),
            [](auto e){ return (e.second > 1);}
            ) +
            std::count_if(
            _FaceMap.begin(),
            _FaceMap.end(),
            [](auto e){ return (e.second > 1);}
            );
}

void Game::reset()
{
    _SuitMap.clear();
    _FaceMap.clear();
    _board.clear();
    _points = 0;
}

void Game::flipAll()
{
    if(!moveAvailable()){
        for(int i =0; i < _board.size(); i++){
            if(!isFlipped(i)){
                flipCard(i);
            }
        }
    }
}

void Game::setHighScore()
{
    if(_highScore < _points){
        _highScore = _points;
    }
}
