
/* 
 * File:   game.cpp
 * Author: Juan Enriquez
 * Purpose: To create a program that plays the Uno card game
 * Version: 2
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

enum Colors{ 
    Red, 
    Blue, 
    Yellow, 
    Green 
};

enum CardName{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King
};

struct Card {
  CardName name;
  Colors color;
  int value;
};

struct Deck{
    Card arrCards[52];
    
    void SetupCards(){
        for(int col=(int)Colors.Red; col<= (int)Colors.Green; col++){
            for(int row=(int)CardName.Ace; row <= (int)CardName.King; row++){
                Card c;
                c.color = (Colors)col;
                c.name = (CardName)row;
                
                if (c.name==CardName.Jack){
                    c.value=10;
                }
                else if(c.name==CardName.Queen){
                    c.value=10;
                }
            }
        }
    }
};
//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here
//Execution Begins Here

int main(int argc, char** argv) {
    //Set random number seed here when needed

    //Declare variables or constants here
    //7 characters or less
        
    //Clean up allocated memory here

    //Exit stage left
    return 0;
}

/****************************************************************************
 * Function initializeDeck: Purpose is to put the contents of each card into 
 * an 2D array where it is determined its color and number
 ***************************************************************************/
