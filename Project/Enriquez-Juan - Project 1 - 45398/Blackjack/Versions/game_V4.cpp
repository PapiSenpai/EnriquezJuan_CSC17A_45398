 
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
#include <ctime>

using namespace std;

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
};

/******************************************************************************
* Deck Structure
******************************************************************************/
struct Deck{
    Card arrCards[52]; // make into a dynamically allocated structure array
    //int index =
};

/******************************************************************************
* Player Structure
******************************************************************************/
struct Player{
    string name;
    Card hand[20];
};

//User Libraries - Post Here

//Function Prototypes - Post Here
void PrintCard(Card);
void PrintValue(Card);
void PrintSuit(Card);
void shuffle(Deck &);
void PrintAll(Deck);
void SetupCards(Deck &);
Card draw(Deck &, int &);

//Execution Begins Here
int main(int argc, char** argv) {
    //
    // random generator seed
    srand(time(0)); // required to make the random operator work
    //
    // Structure Variables
    Card c;
    Deck d;
    Player p[4]; // struct array of 4 to hold 4 players
    //
    // Variables
    fstream rules; // set up to open file for da rules
    string readLine;
    int numOfP; // Number of players
    int i; //counter
    int j; //counter
    int index;
    //
    // Actions
//    rules.open("Rules.txt", ios::out);
//    for(i=0;!rules.eof();i++) // for loop is used to output contents of file 
//    {
//        getline(rules, readLine);
//        cout<<readLine<<endl;
//    }
//    rules.close();
//    
    cout << "How many players are playing? Only 4 can play at the " 
         << "same time." << endl;
    cin >> numOfP;
    //While statement tests user input for amount of players
    while(numOfP<1 || numOfP>4){ // add more later so that it only accepts nums
        if(numOfP==0)
        {
        cout <<"That's too few people! Try again." << endl;
        cin>>numOfP;
        }
        else if(numOfP<0)
        {
            cout<<"Cannot enter negative numbers, try again."<<endl;
            cin>>numOfP;
        }
        else if(numOfP>4)
        {
            cout <<"That's too many people! Try again." << endl;
            cin>>numOfP;
        }
    }
    //
    cout << "Enter name for the players." << endl;    
    for(i=0;i<numOfP;i++)
    {
        cin >> p[i].name;
    }
    //
    //function call
    SetupCards(d);
    cout << endl;
    PrintAll(d); // erase later
    //
    // draw cards for each player until there are 6 cards
    for(i=0;i<numOfP;i++)
    {
        for(j=0;j<6;j++)
        {
          p[i].hand[j] = draw(d, index); 
        }
    }
    for(i=0;i<numOfP;i++)
    {
        for(j=0;j<6;j++)
        {
          cout << p[i].hand[j]; 
        }
    }
    return 0;
}

// Member Functions
void PrintCard(Card c)
{
    PrintValue(c);
    cout << " of ";
    PrintSuit(c);
    cout << endl;
}


void PrintValue(Card c)
{
    if(c.name==CardName::Jack)
    {
        cout<<"Jack";
    }

    else if(c.name==CardName::Queen)
    {
        cout<<"Queen";
    }
    else if(c.name==CardName::King)
    {
        cout<<"King";
    }
    else
    {
        cout << c.value;
    }
}

void PrintSuit(Card c)
{
  if (c.suit==Suits::Clubs)
  {
      cout << "clubs";
  }
  else if(c.suit==Suits::Diamonds)
  {
      cout << "diamonds";
  }
  else if(c.suit==Suits::Hearts)
  {
      cout << "hearts";
  }
  else if(c.suit==Suits::Spades)
  {
      cout << "spades";
  }
}
//
/*****************************************************************************
* Shuffle Function:
*   Will shuffle the deck of cards
*****************************************************************************/
void shuffle(Deck &d)
{
    int n,m;
    Card temp=d.arrCards[0]; // makes 
    for (n=0;n<52;n++)
    {
        m=rand()%52; // gives a random number 
        temp=d.arrCards[n]; // switches the contents of d.arrCards[n] with the
                            // 
        d.arrCards[n]=d.arrCards[m];
        d.arrCards[m]=temp;
    }
}
    
    
/*****************************************************************************
* PrintAll Function:
*   This function will print the cards of the deck
*****************************************************************************/
void PrintAll(Deck d)
{
    for(int col=(int)Suits::Clubs; col<=(int)Suits::Spades; col++)
    {
        for(int row=(int)CardName::Ace; row <= (int)CardName::King; row++)
        {
            int index=(13*col)+row-1;     // accesses the contents of arrCards
            PrintCard(d.arrCards[index]); // Prints contents in a card struct 
        }
    }
}

/*****************************************************************************
* SetupCards Function:
*   This function will initialize the each card
*****************************************************************************/
void SetupCards(Deck &d){
    for(int col=(int)Suits::Clubs; col<=(int)Suits::Spades; col++){
        for(int row=(int)CardName::Ace; row <= (int)CardName::King; row++){
            Card c;
            c.suit = (Suits)col;    // same as Suits[col]
            c.name = (CardName)row; // these two access the enum class

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

            int index = (13*col)+row-1; // gives position in deck

            d.arrCards[index]=c;

        }
    }
    shuffle(d); //call shuffle function
}

/*******************************************************************************
 * Draw Function:
 *   This function allows to draw a card form the deck of cards
 ******************************************************************************/
Card draw(Deck &d, int &index)
{   
    return d.arrCards[index++];
}