#include "matchinggame.h"
#include "Model/Deck.h"

MatchingGame::MatchingGame(int numberOfCards, Deck &deck)
{
    cards.reserve(numberOfCards);

    for (int i=0;i<numberOfCards;++i)
    {
        if (! deck.isEmpty())
            cards.push_back(deck.drawCard());
    }
}

CardPtr MatchingGame::getSquareN(int i)
{
    return cards.at(i);
}

void MatchingGame::selectCardN(int index)
{

    for(int i=0;i<cards.size();i++){
        if(index != i){
            if(cards[i]->isFlipped() && !(cards[i]->isMatched())){
                cards[i]->flip();
                if(getSuit(i) == getSuit(index)){
                    cards[i]->setMatched(true);
                    cards[index]->setMatched(true);
                }
                if(getFace(i) == getFace(index)){
                    cards[i]->setMatched(true);
                    cards[index]->setMatched(true);
                }
            }
        }
    }

    if (index < cards.size()){
        cards[index]->flip();
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
