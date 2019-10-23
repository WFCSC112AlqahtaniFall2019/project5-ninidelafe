#include "Card.h"
#include <string>
#include <iostream>
using namespace std;

//default constructor
Card::Card() {
rankNum=0;
suitType=0;
}

//alternate constructor
Card::Card(int rank, int suit) {
   rankNum=rank;
    suitType=suit;
}

//overload comparison operators
//Checks rank first because rank is more important than suit then proceeds to check the suit if the rank is the same
bool Card::operator<(Card c){
    //cout<<"rankNum: "<<rankNum<<" c.rankNum: "<<c.rankNum<<endl;
if (this->rankNum<c.rankNum){
    //cout<<"1"<<endl;
    return true;
} else if (this->rankNum>c.rankNum){
    //cout<<"2"<<endl;
    return false;
} else if (this->rankNum==c.rankNum){
    if(this->suitType<c.suitType){
        //cout<<"3"<<endl;
        return true;
    } else{
        //cout<<"4"<<endl;
        return false;
    }
}
}

//one member function that returns the value of the card
string Card::cardValue(){
    value= ranks[rankNum]+ " of "+ suits[suitType];
    return value;
}
