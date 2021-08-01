 
/* 
 * File:   game.cpp
 * Author: Juan Enriquez
 * Purpose: To create a program that plays the Blackjack card game
 * Version: 5
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
// after done with project, redo and put structs/enums into seperate files
//User Libraries - Post Here
#include "Suits.h"
#include "CardName.h"
#include "Card.h"
#include "Deck.h"
#include "Player.h"


//Function Prototypes - Post Here
//void PrintCard(Card);
//void PrintValue(Card);
//void PrintSuit(Card);
//void shuffle(Deck &);
//void PrintAll(Deck);
//void SetupCards(Deck &);
//Card draw(Deck &, int &); //returns drawn card
void Dealer(Deck &, Player *,int, int &, int &, int &, int &);
void CheckSum(Player *,int,int,int,int);
void CheckWin(Player *,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //
    // random generator seed
    srand(time(0)); // required to make the random operator work
    //
    // Structure Variables
    Card cards;
    Deck deck; //
    //
    // Variables
    fstream rules; // set up to open file for da rules
    string fileName="Rules.txt"; // c-string thing
    string readLine;
    int numOfP; // Number of players
    int i; //counter
    int j; //counter
    int a=2,b=2,c=2,d=2; 
    int index=52;
    //
    // Open file to print out rules
    rules.open(fileName, ios::in | ios::out); // opens a file and put it into input mode
    while(getline(rules, readLine)) // while loop used to print out contents
    {
        cout << readLine <<endl;
    }
    rules.close(); //closes file
    //
    cout << "How many players are playing? Only 3 can play at the " 
         << "same time plus the dealer." << endl;
    cin >> numOfP;
    //
    //While statement tests user input for amount of players
    while(numOfP<1 || numOfP>3){ // add more later so that it only accepts ints
        if(numOfP==0)
        {
        cout <<"There's no one to play with! Try again." << endl;
        cin>>numOfP;
        }
        else if(numOfP<0)
        {
            cout<<"Cannot enter negative numbers, try again."<<endl;
            cin>>numOfP;
        }
        else if(numOfP>3)
        {
            cout <<"That's too many people! Try again." << endl;
            cin>>numOfP;
        }
    }
    //
    // Create a dynamic class for people
    Player *p = new Player[4]; // object array of 4 to hold 4 players
    string name;
    //
    // Input name for players
    cout << "Enter name for the players." << endl;    
    for(i=1;i<=numOfP;i++) //for loop used to enter name to each Player 
    {                      //structure array
        cin >> name; 
        p[i].setName(name); //make an exception here
    }
    cout << endl;
    p[0].setName("Dealer");  // Sets the name for the Dealer  
    //
    // for loop that draws cards for each player until there are 2 cards
    for(i=0;i<=numOfP;i++)
    {
        for(j=0;j<2;j++)
        {
          p[i].setHand(deck,j);
        }
    }
    
    //
    //Output the contents of each players hand
    if(numOfP>=1)
    {    
        cout<<p[1].getName() << "'s hand" << endl;
        for(j=0;j<b;j++)
        {
          deck.PrintCard(p[1].getHand(j));
        }
        cout<<endl;
    }
    if(numOfP>=2)
    {
        cout<<endl<<p[2].getName() << "'s hand" << endl;
        for(j=0;j<c;j++)
        {
            deck.PrintCard(p[2].getHand(j));
        }
        cout<<endl;
    }
    if(numOfP>=3)
    {
        cout<<endl<<p[3].getName() << "'s hand" << endl;
        for(j=0;j<d;j++)
        {
            deck.PrintCard(p[3].getHand(j));
        }
        cout<<endl;
    }
    //
    // Function call so that players can draw more cards
    Dealer(deck,p,numOfP,a,b,c,d);
    //
    // Function call to check the sum and win conditions
    CheckSum(p,numOfP,b,c,d);
    CheckWin(p,numOfP);

    //delete allocated data here
    delete []p;
    // Exit stage right
    return 0;
}


/*******************************************************************************
 * Dealer Function:
 *   This function allows player to draw additional cards from the deck.
 ******************************************************************************/
void Dealer(Deck &deck, Player *p,int numOfP,int &a,
                                                    int &b, int &c, int &d)
{
    int choice,i,j;
    
    cout << "\nDo you want to draw more cards?"<<endl;
    // if statement used to control what should be outputted
    if (numOfP>=1)
    {
        cout << "Press 1 to let player one draw."<<endl;
    }
    if (numOfP>=2)
    {
        cout << "Press 2 to let player two draw."<<endl;        
    }
    if (numOfP==3)
    {
        cout << "Press 3 to let player three draw."<<endl;        
    }
    cout <<"Press 4 to continue."<<endl;
    cin >> choice;
    //
    while(choice!=4){
        //        
        if(choice==1)
        {
            p[1].setHand(deck, b);
            b++;
        }
        else if(choice==2)
        {
            p[2].setHand(deck, c);
            c++;
        }
        else if(choice==3)
        {
            p[3].setHand(deck, d);
            d++;
        }
        else
        {
            cout<<"That is not a valid choice! Try again." << endl;
        }
        //
        //Output the contents of each players hand with the if statement
        if(numOfP>=1)
        {    
        cout<<endl<<p[1].getName()<< "'s hand" << endl;
            for(j=0;j<b;j++)
            {
                deck.PrintCard(p[1].getHand(j));
            }
        cout<<endl;
        }
        if(numOfP>=2)
        {
        cout<<endl<<p[2].getName() << "'s hand" << endl;
            for(j=0;j<c;j++)
            {
                deck.PrintCard(p[2].getHand(j));
            }
        cout<<endl;
        }
        if(numOfP>=3)
        {
        cout<<endl<<p[3].getName() << "'s hand" << endl;
            for(j=0;j<d;j++)
            {
                deck.PrintCard(p[3].getHand(j));
            }
        cout<<endl;
        }
        //
        cout << "Do you want to draw more cards?"<<endl;
        if (numOfP>=1)
        {
            cout << "Press 1 to let player one draw."<<endl;
        }
        if (numOfP>=2)
        {
            cout << "Press 2 to let player two draw."<<endl;        
        }
        if (numOfP==3)
        {
            cout << "Press 3 to let player three draw."<<endl;        
        }
        cout <<"Press 4 to continue."<<endl;
        cin >> choice;
    }
    //
    int total=0;
    // calculates total for dealer
    cout<<endl<<endl<<p[0].getName()<<endl;
    // outputs the dealers hand
    for(int i=0;i<a;i++){
        deck.PrintCard(p[0].getHand(i)); 
        p[0].setTotal(i);
    }
    
    //Maybe delete later
    // p[0].total=total
    while(p[0].getTotal()<17) // should draw until busts or wins
    {      
        p[0].setHand(deck, a);
        deck.PrintCard(p[0].getHand(a));
        p[0].setTotal(a);
        // check other version if this gives weird output
        a++;
    }
    cout << p[0].getName() <<" has a value of " << p[0].getTotal() << endl;
}

/*******************************************************************************
 * CheckSum Function:
 *   After the player(s) are done drawing cards form the Dealer function, this
 * function gets called to sum up the contents of each players hand.
 ******************************************************************************/
void CheckSum(Player *p,int numOfP, int b, int c, int d)
{
    int i;
    // if statement
    if(numOfP>=1)
    {
        for(i=0;i<b;i++)
        {
            p[1].setTotal(i);
        }
        cout <<endl<< p[1].getName() <<" has a value of " << p[1].getTotal() 
             <<endl<<endl;
//      p[1].total=total;
    }
    if(numOfP>=2)
    {
        for(i=0;i<c;i++)
        {
            p[2].setTotal(i); 
        }
        cout << p[2].getName() <<" has a value of " << p[2].getTotal() 
             << endl<<endl;
//        p[2].total=total;
    }
    if(numOfP>=3)
    {
        for(i=0;i<d;i++)
        {
            p[3].setTotal(i);
        }
        cout << p[3].getName() <<" has a value of " << p[3].getTotal() 
             << endl<<endl;
//        p[3].total=total;
    }   
}

/*******************************************************************************
 * CheckWin Function:
 *   After the CheckSum function is called, this function gets called to see who
 * won. If sum is over 21, the function will say who busted.
 ******************************************************************************/
void CheckWin(Player *p,int numOfP)
{   
    for(int i=1;i<=numOfP;i++)
    {
        if(p[i].getTotal()<=21)
        {  
            if(p[0].getTotal()<p[i].getTotal() || p[0].getTotal()>21)
            {
                cout << p[i].getName() <<" wins!" << endl;//player wins
            }
            else if(p[0].getTotal()==p[i].getTotal())
            {
                cout << "Its a tie with the dealer with " << p[i].getName() 
                     <<"."<< " Play Again!"<<endl;//tie
            }
            else
            {
                cout <<"The dealer wins against "<<p[i].getName() << "."
                        << endl;//Dealer Wins
            }
        }
        else
        {
            cout<< p[i].getName() <<"'s hand busted! " <<p[i].getName()
                    << " is out of the game."<< endl;
        }
    }
}