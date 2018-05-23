#include "game.h"
#include "Model/Card.h"
#include "Model/Deck.h"


Game::Game()
{

}



void Game::setFlipped(int index)
{
    _cards.at(index)->flip();
}

void Game::setCardAtN(CardPtr card){

    _cards.push_back(card);
}

std::string Game::getText(int index)
{
    return _cards[index]->toString();
}

CardColor Game::getCardColor(int index)
{
    return _cards[index]->getColor();
}

CardPtr Game::getCardN(int index)
{
    return _cards.at(index);
}

void Game::selectCardN(int index)
{

_cards.at(index)->setMatched(false); ///
    if (index < _cards.size() )
    {
        _cards.at(index)->flip(); //flip selected card (index)

        for (int i=0;i<_cards.size();++i)
        {
            if (_cards.at(i)->isFlipped() && i != index && !_cards.at(i)->isMatched()){ //flip back the last card (i) that was flipped

                /////
                if(_cards.at(index)->getMatchValue(*_cards.at(i)) > 0){  // find out if two cards match
                    _cards.at(index)->setMatched(true); // set both matched value to true if they match
                    _cards.at(i)->setMatched(true);
                }
                else{
                    _cards.at(i)->flip(); //if already flipped, and no match, flip it back
                }
                score += _cards.at(index)->getMatchValue(*_cards.at(i));
            }
        }
    }
}

int Game::getScore()
{
    return score;
}



