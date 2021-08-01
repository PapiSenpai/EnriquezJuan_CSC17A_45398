 
/* 
 * File:   game.cpp
 * Author: Juan Enriquez
 * Purpose: To create a program that plays the Uno card game
 * Version: 3
 * Created on July 13, 2021, 6:03 PM
 */

//System Libraries - Post Here
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Player{
    string name;
    char hand;
};

enum class Suits{ 
    Clubs, 
    Diamonds, 
    Hearts, 
    Spades, 
};

enum class CardName{
    Ace=1, // makes ace start at one in the enum
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

/******************************************************************************
//Card Structure
 ******************************************************************************/
struct Card {
  CardName name;
  Suits suit;
  int value;
  
  void PrintCard()
    {
        PrintValue();
        cout << " of ";
        PrintSuit();
        cout << endl;
    }
    
    void PrintValue()
    {
        if(name==CardName::Jack)
        {
            cout<<"Jack";
        }
        
        else if(name==CardName::Queen)
        {
            cout<<"Queen";
        }
        else if(name==CardName::King)
        {
            cout<<"King";
        }
        else
        {
            cout << value;
        }
    }
  
  void PrintSuit()
  {
      if (suit==Suits::Clubs)
      {
          cout << "clubs";
      }
      else if(suit==Suits::Diamonds)
      {
          cout << "diamonds";
      }
      else if(suit==Suits::Hearts)
      {
          cout << "hearts";
      }
      else if(suit==Suits::Spades)
      {
          cout << "spades";
      }
  }
};

/******************************************************************************
//Deck Structure
 ******************************************************************************/
struct Deck{
    Card arrCards[52];
    
    //member function
    void PrintAll()
    {
        for(int col=(int)Suits::Clubs; col<=(int)Suits::Spades; col++)
        {
            for(int row=(int)CardName::Ace; row <= (int)CardName::King; row++)
            {
                int index=(13*col)+row-1;
                
                arrCards[index].PrintCard();
            }
        }
    }
    
    // member function
    void SetupCards(){
        for(int col=(int)Suits::Clubs; col<=(int)Suits::Spades; col++){
            for(int row=(int)CardName::Ace; row <= (int)CardName::King; row++){
                Card c;
                c.suit = (Suits)col; // what does this mean?
                c.name = (CardName)row; // Guess this accesses the enum class

                // This gives each name its value
                if (c.name==CardName::Jack){
                    c.value=10;
                }
                else if(c.name==CardName::Queen){
                    c.value=10;
                }
                else if(c.name==CardName::King){
                    c.value=10;
                }
                else
                {
                    c.value = (int)c.name;
                }
                
                int index = (13*col)+row-1;
                
                arrCards[index]=c;
            }
        }
    }
};

void shuffle()
{
    
}
//User Libraries - Post Here

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    Deck deck;
    deck.SetupCards();
    cout << endl;
    deck.PrintAll();
    
    return 0;
}