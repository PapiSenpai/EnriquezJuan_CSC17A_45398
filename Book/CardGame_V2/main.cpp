
/* 
 * File:   game.cpp
 * Author: Juan Enriquez
 * Purpose: To create a program that plays the Uno card game
 * Version: 1
 * Created on July 13, 2021, 6:03 PM
 */

//System Libraries - Post Here
#include <iostream>
#include <string>

using namespace std;

struct Player{
    string name;
    char hand;
};

enum Color{ Red, Blue, Yellow, Green };

struct Card{
    char *number;
    enum Color colorAt;
};

struct Card cardDeck[52];

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here
void initializeDeck(Card &);
//Execution Begins Here

int main(int argc, char** argv) {
    //Set random number seed here when needed

    //Declare variables or constants here
    //7 characters or less
    Card cardFace;
    cardFace.number[12] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '10', 'J', 'Q', 'K'};
    
    initializeDeck(cardFace);
    

    //Clean up allocated memory here

    //Exit stage left
    return 0;
}

/****************************************************************************
 * Function initializeDeck: Purpose is to put the contents of each card into 
 * an 2D array where it is determined its color and number
 ***************************************************************************/
void initializeDeck(Card &cards){
    int i,j,k; // counters
    
    for(i=0; i<4; i++){
        for(j=0 ; j<13 ; j++){
            
        }
    }
}
