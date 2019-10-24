#ifndef BLINDMANSBLUFF_CARD_H
#define BLINDMANSBLUFF_CARD_H
#include <string>
using namespace std;

// ranks are ordered Ace-low and Queen-high
const string ranks[] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","King","Queen"};
// suits are ordered alphabetically
const string suits[] = {"Clubs","Diamonds","Hearts","Spades"};

class Card {
public:
    //default constructor
    Card();
    //alternate constructor
    Card(int rank, int suit);
    //overloaded comparision operator that allows for comparison of ranks and suits
    bool operator<(Card c);
    //returns a string value of the card name for example "Ace of Clubs"
    string cardValue();

private:
    //declares private variables to be used within card.pp but not the main
    int rankNum;
    int suitType;
    string value;

};



#endif //BLINDMANSBLUFF_CARD_H
