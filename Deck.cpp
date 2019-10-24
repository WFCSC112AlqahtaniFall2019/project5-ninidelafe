#include "Deck.h"
#include <string>
#include <iostream>

using namespace std;
//default constructor- assigns all the private variables with the correct values and creates an array with the correct size
Deck::Deck() {
    //cout<<"Default Constructor"<<endl;
    arraySize = 52;
    cards = new Card[arraySize];
    cardsLeft = 52;
    currentCard=0;
}

//Copy constructor- creates a copy of the private variables and the array
Deck :: Deck (const Deck& C ){
    //cout << "Copy Constructor called." << endl;
    arraySize = C.arraySize;
    cards = new Card[arraySize];
    for (int i=0; i<arraySize;i++){
        cards[i]=C.cards[i];
    }
    currentCard=C.currentCard;
    cardsLeft=C.cardsLeft;

}

//destructor- deletes the created arrays
Deck::~Deck() {
    //cout<<"Destructor called"<<endl;
    delete [] cards;
}

//Copy assignment operator- allows for the equal sign to be used as an operator
Deck& Deck::operator= (const Deck& D) {
    //cout<<"assignment operator called"<<endl;
    Deck temp(D); // copy constructor temp
    swap(cards, temp.cards); //built-in swap
    return *this;
}

//populates the deck with 52 cards; 13 of each suit
void Deck::populateDeck(){
   //cout<<"populate deck called"<<endl;
    int k = 0;
    //while (k<52){
    for (int i=0; i<4; i++) {
        for (int j=0; j<13; j++) {
            Card c = Card(j, i);
            //cards[k] = c;// Put card in position k
            cards[k] = Card(j, i);
            //cout<<"k: "<<k<<" i: "<<i<<" j: "<<j<<" cards[k] "<<cards[k].cardValue()<<" c: "<< c.cardValue()<<endl;
            k++;
        }
    }
    //}
}

//shuffles the cards in the deck
void Deck::shuffleCards() {
    //cout << "shuffle cards called" << endl;
    int shuffleAmount = cardsLeft * cardsLeft;
    for (int j = 0; j < shuffleAmount; j++) {
        int random1 = rand() % cardsLeft;
        int random2 = rand() % cardsLeft;
        Card temp = cards[random1];
        cards[random1] = cards[random2];
        cards[random2] = temp;
    }
}

//deals/ removes a card from the deck then decreases the cardsLeft while also giving the value of the card
Card Deck::dealCard() {
    //cout<<"deal cards called"<<endl;
    if (currentCard < arraySize) {
        cardsLeft--;
        return (cards[currentCard++]);
    } else{
        cout<<"There are no cards left."<<endl;
    }
}

// add card to the deck or return false if no physical space in deck while returning an error message
bool Deck::addCard(Card v){
   //cout<<"add card called"<<endl;
    if (cardsLeft == 0){
        cout<<"Error: There are no cards left."<<endl;
        return false;
    } else{
        cards[currentCard] = v;
        currentCard++;
        return true;
    }
}

//prints out the discard pile
void Deck::discardPrint(){
    //cout<<currentCard<<endl;
    cout<<"Discard Pile: ";
    for (int i = 0; i <currentCard; ++i) {
        cout<<cards[i].cardValue()<<", ";
    }
    cout<<endl;
}
