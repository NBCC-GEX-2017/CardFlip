//
//  Deck.hpp
//  cards02
//
//  Created by Dave Burchill on 2016-04-29.
//  Copyright © 2016 Dave Burchill. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp

#include <vector>
#include <memory>

// forward declaration
class Card;
using CardPtr = std::shared_ptr<Card>;

class Deck
{
public:
    Deck();
    
    bool isEmpty() const;
    CardPtr drawCard();
    void shuffle();
    
private:
    std::vector<CardPtr> _deck;
    int _topOfDeck;
};


#endif /* Deck_hpp */
