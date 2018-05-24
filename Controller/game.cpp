#include "game.h"
#include <vector>
#include "Model/Card.h"
Game::Game()
{

}

void Game::setCard(CardPtr card)
{
    _gamecards.push_back(card);

}

void Game::setFlip(int flipped)
{
    for(int i=0;i<_gamecards.size();i++)
    {
        if(i!= flipped)
        {
            if(_gamecards[i]->isFlipped()&&!(_gamecards[i]->isMatcher()))
            {
                if(_gamecards[i]->suit==_gamecards[flipped]->suit)
                {
                    _gamecards[i]->setMatched(true);
                    _gamecards[flipped]->setMatched(true);
                    _score=_score +1;
                }
                else if(_gamecards[i]->face==_gamecards[flipped]->face)
                {
                    _gamecards[i]->setMatched(true);
                    _gamecards[flipped]->setMatched(true);
                     _score=_score+4;
                }
                else
                {
                _gamecards[i]->flip();//homework
                _score= _score-1;
                    if(_score<0)
                    {
                        _score=0;
                    }

                }
            }

        }

    }
    _gamecards[flipped]->flip();

}

CardColor Game::getColor(int color)
{
    return _gamecards[color]->getColor();
}

std::string Game::getText(int text)
{
    return _gamecards[text]->toString();
}

bool Game::isFlipped(int flipped)
{
    return _gamecards[flipped]->isFlipped();
}

bool Game::isMatched(int flipped)
{
    return _gamecards[flipped]->isMatcher();
}

int Game::getScore()
{
    return _score;
}
/*void shuffle()
{
    std::for_each(_deck.begin(),
                  _deck.end(),
                  [](CardPtr e)
        {if (e->isFlipped())
        {
            e->flip();
        }
        e->setMatched(false);

        });

    for (size_t i=0;i<_deck.size();++i)
    {
        swap(_deck[i],  _deck[i + (rand() % (_deck.size()-i))]);
    }
    _topOfDeck = (_deck.size()-1);

}
*/
