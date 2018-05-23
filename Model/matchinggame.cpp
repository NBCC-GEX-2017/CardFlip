#include "matchinggame.h"
#include "Model/Deck.h"

MatchingGame::MatchingGame(int numberOfCards, Deck &deck) : _score(0)
{
    _cards.reserve(numberOfCards);

    for (int i=0;i<numberOfCards;++i)
    {
        if (! deck.isEmpty())
            _cards.push_back(deck.drawCard());
            _count[_cards[i]] = 0;
    }
}

CardPtr MatchingGame::getSquareN(int i)
{
    return _cards.at(i);
}

void MatchingGame::selectCardN(int index)
{

    for(int i=0;i<_cards.size();i++){
        if(index != i){
            if(_cards[i]->isSelected() && !(_cards[i]->isMatched())){
                _cards[i]->flip();
                if(getSuit(i) == getSuit(index)){
                    _cards[i]->setMatched(true);
                    _cards[index]->setMatched(true);
                    _score += 2;
                }
                if(getFace(i) == getFace(index)){
                    _cards[i]->setMatched(true);
                    _cards[index]->setMatched(true);
                    _score += 4;
                }
                if ((getSuit(i) != getSuit(index)) && (getFace(i) != getFace(index))){
                    _score -= 1;
                }
            }
        }
    }

    if (index < _cards.size()){
        _cards[index]->flip();
        _count[_cards[index]]++;
        if((_cards[index]->isSelected()) && !(_cards[index]->isMatched()) && (_count[_cards[index]] > 1)){
            _score -= 1;
        }
    }

    // card(index)
        // if isFlipped() -> flip and return
        // isMatched()    -> return

    // is there a card already flipped
     // no -> flip it

     // yes ->
        // does it match card at index
           // yes
              // set both matched
              // score some pointes
           // no
              // deduct points
              // flip both

}

int MatchingGame::getScore()
{
    return _score;
}

