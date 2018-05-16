//
//  Card.hpp
//  cards02
//
//  Created by Dave Burchill on 2016-04-28.
//  Copyright © 2016 Dave Burchill. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp

#include <string>
#include <set>
#include <map>
#include <iostream>


enum class Suit {CLUB, DIAMOND, HEART, SPADE};
enum class Face {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum class CardColor {Black, Red};
class Card
{
public:
    Card(Face f, Suit s) : suit(s), face(f) {}
    const Suit suit;
    const Face face;
    CardColor getCardColor() const;
    std::string toString() const;
    
private:
    bool isMatched() const {return _matched;}
    bool isFlipped() const {return _flipped;}
    bool _matched;
    bool _flipped;
public:
    // class members ///////////////////////////////////
    static const std::set<Suit> suits;
    static const std::set<Face> faces;
    
    static const std::map<Face, std::string>  faceNames;
    static const std::map<Suit, std::string>  suitNames;
    ////////////////////////////////////////////////////
};

//
// comparison operator overloads
//
inline bool operator==(const Card& lhs, const Card& rhs){
    return ((lhs.face == rhs.face)&&(lhs.suit == rhs.suit));
}
inline bool operator< (const Card& lhs, const Card& rhs){
    if (lhs.face < rhs.face) return true;
    if ((lhs.face == rhs.face) && (lhs.suit < rhs.suit)) return true;
    return false;
}
inline bool operator!=(const Card& lhs, const Card& rhs){return !operator==(lhs,rhs);}
inline bool operator> (const Card& lhs, const Card& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const Card& lhs, const Card& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const Card& lhs, const Card& rhs){return !operator< (lhs,rhs);}

std::ostream& operator<<(std::ostream& os, Card& c);

#endif /* Card_hpp */
