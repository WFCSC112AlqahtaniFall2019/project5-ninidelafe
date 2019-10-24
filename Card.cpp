#include "Card.h"
#include <string>
#include <iostream>
using namespace std;

//default constructor- assigns rankNum and suitType = 0
Card::Card() {
rankNum=0;
suitType=0;
}

//alternate constructor- assigns rankNum and suitType with the parameters inputted when called
Card::Card(int rank, int suit) {
   rankNum=rank;
    suitType=suit;
}

//overload comparison operator- creates the operator to allow the cards to be checked in regards to the game instructions
//Checks rank first because rank is more important than suit, if the rank is the same then the suit is checked
bool Card::operator<(Card c){
    //cout<<"rankNum: "<<rankNum<<" c.rankNum: "<<c.rankNum<<endl;
    if (this->rankNum<c.rankNum){
    return true;
} else if (this->rankNum>c.rankNum){
    return false;
} else if (this->rankNum==c.rankNum){
    if(this->suitType<c.suitType){
        return true;
    } else{
        return false;
    }
}
}

//one member function that returns the value of the card using the rank and suit; for example it would print "Ace of Clubs"
string Card::cardValue(){
    value= ranks[rankNum]+ " of "+ suits[suitType];
    return value;
}
