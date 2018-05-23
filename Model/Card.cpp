//
//  Card.cpp
//  cards02
//
//  Created by Dave Burchill on 2016-04-28.
//  Copyright © 2016 Dave Burchill. All rights reserved.
//

#include "Card.h"


CardColor Card::getColor()const{
    if(suit == Suit::DIAMOND || suit == Suit::HEART)
        return CardColor::Red;
    else
        return CardColor::Black;
}

Suit Card::getSuit() const
{
    return suit;

}

Face Card::getFace() const
{
    return face;
}

void Card::flip()
{
    _flipped = _flipped ? false : true;
}



void Card::setMatched(bool matched)
{
    _matched = matched;
}

int Card::getMatchValue(Card otherCard)
{
    if(face == otherCard.getFace()){
        return 4;
    }
    else if(suit == otherCard.getSuit()){
        return 2;
    }
    else{
        return -2;
    }

}

std::string Card::toString() const
{
    return  faceNames.at(face) +   suitNames.at(suit);
}

std::ostream& operator<<(std::ostream& os, Card& c)
{
    os << c.toString();
    return os;
}

const std::set<Suit> Card::suits {
    Suit::CLUB,
    Suit::DIAMOND,
    Suit::HEART,
    Suit::SPADE};

const std::set<Face> Card::faces {
    Face::ACE,
    Face::TWO,
    Face::THREE,
    Face::FOUR,
    Face::FIVE,
    Face::SIX,
    Face::SEVEN,
    Face::EIGHT,
    Face::NINE,
    Face::TEN,
    Face::JACK,
    Face::QUEEN,
    Face::KING};

const std::map<Face, std::string> Card::faceNames {
    {Face::ACE, " A"},
    {Face::TWO," 2"},
    {Face::THREE," 3"},
    {Face::FOUR, " 4"},
    {Face::FIVE, " 5"},
    {Face::SIX," 6"},
    {Face::SEVEN," 7"},
    {Face::EIGHT," 8"},
    {Face::NINE," 9"},
    {Face::TEN,"10"},
    {Face::JACK," J"},
    {Face::QUEEN," Q"},
    {Face::KING," K"}
};

const std::map<Suit, std::string> Card::suitNames {
    {Suit::HEART,"♥️"},
    {Suit::DIAMOND,"♦️"},
    {Suit::CLUB,"♣️"},
    {Suit::SPADE,"♠️"}};

