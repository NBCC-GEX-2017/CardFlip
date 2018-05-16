//
//  Deck.cpp
//  cards02
//
//  Created by Dave Burchill on 2016-04-29.
//  Copyright © 2016 Dave Burchill. All rights reserved.
//

#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <stdexcept>

Deck::Deck()
{
    if (_deck.size() != 0)
        _deck.clear();
    
    for (auto f : Card::faces)
        for (auto s : Card::suits)
            _deck.push_back(std::make_shared<Card>(Card(f,s)));
    
    //_isFlipped = false;
    _topOfDeck = _deck.size()-1;
}

//CardColor Deck::getCardColor()
//{
//    if (_deck[_topOfDeck]->suit == Suit::DIAMOND || _deck[_topOfDeck]->suit == Suit::HEART)
//        return CardColor::Red;
//    else
//        return CardColor::Black;
//}

bool Deck::isEmpty() const
{
    return (_topOfDeck < 0);
}

CardPtr Deck::drawCard()
{
    if(isEmpty())
    {
        return nullptr;
    }
    else
    {
        return _deck[_topOfDeck--];//top of deck is decreaced after it returns the first card
    }
}

//void Deck::sort()
//{
//    std::sort(_deck.begin(), _deck.end(),  [](CardPtr lhs, CardPtr rhs) { return (*lhs < *rhs);});
//    _isFlipped = false;
//     _topOfDeck = static_cast<int>(_deck.size()-1);
//}
//
//void Deck::nextCard()
//{
//    if (_isFlipped)
//         _topOfDeck = _topOfDeck ? _topOfDeck - 1 : 0;
//    else
//        _isFlipped = true;
//}
//
//std::string Deck::topCardToString() const
//{
//    return _deck[_topOfDeck]->toString();
//}

void Deck::shuffle()
{
    std::for_each(_deck.begin(),
                  _deck.end(),
                  [](CardPtr e)
    {
        if(e->isFlipped())
        {
            e->flip();
        }
        e->setMatched(false);
    }
    );
    for (size_t i=0;i<_deck.size();++i)
    {
        swap(_deck[i],  _deck[i + (rand() % (_deck.size()-i))]);
    }
    _topOfDeck = _deck.size()-1;
    //_isFlipped = false;
}
