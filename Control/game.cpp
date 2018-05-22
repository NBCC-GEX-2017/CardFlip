#include "game.h"
#include "Model/Card.h"
#include "Model/Deck.h"


Game::Game()
{

}



void Game::setFlipped(int index)
{
    _cards[index]->flip();
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


    if (index < _cards.size() )
    {
        _cards.at(index)->flip(); //flip
        for (int i=0;i<_cards.size();++i)
        {
            if (_cards.at(i)->isFlipped() && i != index)  //if already flipped, flip it back
                _cards.at(i)->flip();
        }
    }


    //isMatched() -> ignore and return

    //is there already a card flipped

        // no -> flip it and return

        // yes ->

        // does it match card at index
            // yes
                // set both matched
                // score some points

            // no
                // deduct points
                // flip both


}



