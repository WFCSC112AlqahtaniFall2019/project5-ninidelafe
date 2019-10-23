#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"
#include <string>

using namespace std;

class Deck {
public:
    //default constructor
    Deck();
    //destructor
    ~Deck();
    //copy constructor
    Deck (const Deck& C );
    //copy assignment operator
    Deck& operator= (const Deck& rhs );
    //populates the deck with cards
    void populateDeck();
    //shuffles the cards in the deck
    void shuffleCards();
    //deals a card in the deck
    Card dealCard();
    //adds a card to the discard pile
    bool addCard(Card v);
    //prints out the discard pile
    void discardPrint();


private:
    Card* cards;
    int arraySize;
    int cardsLeft;
    int currentCard;
};



#endif //BLINDMANSBLUFF_DECK_H
