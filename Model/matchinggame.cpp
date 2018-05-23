#include "matchinggame.h"
#include <algorithm>


MatchingGame::MatchingGame(int numberOfCards, Deck &deck)
{
    cards.reserve(numberOfCards);

    for (int i=0;i<numberOfCards;++i)
    {
        if (! deck.isEmpty())
            cards.push_back(deck.drawCard());
    }
}

CardPtr MatchingGame::getCardN(int index)
{
    return cards.at(index);
}

void MatchingGame::selectCardN(int index)
{
    if (index < cards.size() )
    {
    //std::find_if (cards.begin(), cards.end(), isFlipped());
    //use find if to find if an object is flipped(have isFlipped as a predicate)

    //if card(index) is flipped()
    if(cards[index]->isFlipped())
    {
        //flip back and return
        cards[index]->flip();
        return;//breaks out of ifs
    }
    else if(cards[index]->isMatched())//if isMatched then return
    {
        return;
    }

        //auto it = std::find_if (cards.begin(), cards.end(), isFlipped());

       //std::vector<CardPtr>::iterator it = std::find_if (cards.begin(), cards.end(), isFlipped);

//        CardPtr tmp = nullptr;
//        for (int i=0;i<cards.size();++i)
//              {
//                  if (cards[i]->isFlipped() && i != index)
//                      tmp = cards[i];
//              }

        std::vector<CardPtr>::iterator it = std::find_if (cards.begin(), cards.end(), [](CardPtr &c){return c->isFlipped();});

            if(it != cards.end())//is there a card already flipped
            {
                (*it)->flip();
                cards[index]->flip();
                //if((*it)->isFlipped())
                //if there is does it match the new card at index
                //if(it->get()->getColor() == cards[index]->getColor() || it->get()->toString().substr(0,1) == cards[index]->toString().substr(0,1))//if the two cards match
                if((*it)->suit == cards[index]->suit || (*it)->face == cards[index]->face)//if the two cards match
                {
                    //set both to matched
                    cards[index]->setMatched(true);
                    //set other card to matched
                    //it->get()->setMatched(true);
                    (*it)->setMatched(true);
                    //score some points
                    cards[index]->flip();
                }
                else//if it doesn't
                {
                     //deduct points
                }
             }
            else{
                cards[index]->flip();
            }



}












//    //std::find_if (cards.begin(), cards.end(), isFlipped());
//    //use find if to find if an object is flipped(have isFlipped as a predicate)

//    //if card(index) is flipped()
//    if(cards[index]->isFlipped())
//    {
//        //flip back and return
//        cards[index]->flip();
//    }
//    else if(cards[index]->isMatched())//if isMatched then return
//    {}
//    else//else
//    {
//        //auto it = std::find_if (cards.begin(), cards.end(), isFlipped());

//       //std::vector<CardPtr>::iterator it = std::find_if (cards.begin(), cards.end(), isFlipped);

////        CardPtr tmp = nullptr;
////        for (int i=0;i<cards.size();++i)
////              {
////                  if (cards[i]->isFlipped() && i != index)
////                      tmp = cards[i];
////              }

//        std::vector<CardPtr>::iterator it = std::find_if (cards.begin(), cards.end(), [](CardPtr &c){return c->isFlipped();});

//            if(true)//is there a card already flipped
//            {
//                //if there is does it match the new card at index
//                if(it->get()->getColor() == cards[index]->getColor() || it->get()->toString().substr(0,1) == cards[index]->toString().substr(0,1))//if the two cards match
//                {
//                    //set both to matched
//                    cards[index]->setMatched(true);
//                    //set other card to matched
//                    it->get()->setMatched(true);
//                    //score some points
//                }
//                else//if it doesn't
//                {
//                     //deduct points
//                }
//            }
//    }



//    if (index < cards.size() )
//    {
//        cards[index]->flip();
////        for (int i=0;i<cards.size();++i)
////        {
////            if (cards[i]->isFlipped() && i != index)
////                cards[i]->flip();
////        }
//    }
}
