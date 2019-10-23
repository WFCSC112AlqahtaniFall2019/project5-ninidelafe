/*Alexa (Nini) de la Fe
 * Project 5
 * */

#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    //declares variables needed for the program
    bool play;
    bool invalid;
    bool guessedHigher;
    string response;
    Card compValue;
    Card userValue;
    int nWin = 0;
    int nLoss = 0;
    int nTie = 0;
    int count =0;
    srand(time(NULL));

    //Welcomes the user to the game and gives them instructions and tells them the rankings so that they understand how the game works
    cout << "Welcome to Blind Man's Bluff!" << endl << endl;
    cout << "Instructions: You will be shown your opponent's (the computer) card and you will be asked to guess if your card is lower or"<<endl;
    cout << "higher. To see which card is higher the rank/ number will be compared then the suit will be checked. The ranks/numbers are ruled"<<endl;
    cout << "in this order(from lowest to highest): Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, King, Queen. The suits are ruled in alphabetical"<<endl;
    cout << "order: Clubs, Diamonds, Hearts, Spades. You can play up to 26 times (or stop at any time) and your record will be shown at the end."<<endl<<endl;

    Deck D1; //creates the deck
    Deck discard; //creates the discard pile
    D1.populateDeck();//populates the deck
    D1.shuffleCards();//shuffles the deck

    //while loop- allows the user to continue playing if they choose to and insures they do not play more than 26 times
    play = true;
    while(play && count<26) {
        // assign cards to computer and user
        compValue = D1.dealCard();
        userValue = D1.dealCard();
        //adds cards to the discard pile so they will not be chosen again
        discard.addCard(compValue);
        discard.addCard(userValue);

        // prints out the computers card
        cout << "Computer's card: " << compValue.cardValue() << endl;
        invalid = true;
        //while loop- asks the user if they think their own card is higher or lower and will repeat until a valid response of
        // H/L is entered
        while(invalid) {
            cout << "Do you think your card is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determines the outcome based on the user's input and the ranking system
        if((compValue < userValue && guessedHigher) || (userValue < compValue && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if((userValue < compValue && guessedHigher) || (compValue < userValue && !guessedHigher)) {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {
            cout << "It's a tie:" << endl;
            nTie++;
        }
        cout << "\tyour card is: " << userValue.cardValue() << endl<<endl;

        // while loop- asks the user if they want to play again and will repeat until a valid response of Y/N is entered
        invalid = true;
        while(invalid) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            cout<<endl;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response. Please enter a 'Y' for yes or 'N' for no." << endl;
                invalid = true;
            }
        }
        count++;
    }
    //prints a statement to let the user know that they cannot play anymore games because there are no cards left in the deck
    if (count==26){
        cout<<"There are no cards left to keep playing!"<<endl;
    }
    //discard.discardPrint();

    // outputs the statistics and thanks the user for playing
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;


    return 0;
}