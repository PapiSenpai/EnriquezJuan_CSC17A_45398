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
#include "Bet.h"

//Function Prototypes - Post Here
void Dealer(Deck &, Player *,int, int &, int &, int &, int &);
void CheckSum(Player *,int,int,int,int);
void CheckWin(Player *,Bet &,int);

//Execution Begins Here
int main(int argc, char** argv) {
    //
    // random generator seed
    srand(time(0)); // required to make the random operator work
    //
    // Object Variables
    Card cards;
    Bet put;
    // Create a dynamic class for people
    Deck deck; //makes object for the deck
    Player *p; //makes object for players
    //
    // Variables
    fstream rules; // set up to open file for da rules
    string fileName="Rules.txt"; // c-string thing
    string readLine;
    string answer=""; //used to ask user if they want to play
    string restart="";
    float defCredit=500.00; //Gives the default credit to each player
    int numOfP; // Number of players
    int i; //counter
    int j; //counter
    int round; //counter to distingish rounds
    int a=2,b=2,c=2,d=2; // gives the correct size of each hand
    int index=52; // index of the deck
    //
    // Open file to print out rules
    rules.open(fileName, ios::in | ios::out); // opens a file and put it into input mode
    while(getline(rules, readLine)) // while loop used to print out contents
    {
        cout << readLine <<endl;
    }
    rules.close(); //closes file
    //
    // restart set to y so that you can enter while loop for the first time
    //(use do-while loop instead)
    restart="y";
    // while statement used to loop again if user wants to do another round
    while(answer!="N" && answer!="n"){
        //
        // make an if statement here if user wanted to restart game
        if(restart=="y" || restart=="Y")
        {
            // set restart to nothing
            restart="";
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
            // object for player needs to stay here in order to create an object
            // each time the round restarts since the object is deleted after a 
            // reset
            p = new Player[4]; // object array of 4 to hold 4 players
            string name;       // name used to enter new names in Player class
            //
            // Input name for players
            cout << "Enter name for the players." << endl;    
            for(i=1;i<=numOfP;i++) //for loop used to enter name to each Player 
            {                      //class array
                cin >> name; 
                p[i].setName(name); //make an exception here
            }
            cout << endl;
            p[0].setName("Dealer");  // Sets the name for the Dealer  
            //
            // Put the default amount of credits for eacj player
            for(i=1;i<numOfP+1;i++)
            {
                p[i]+=defCredit; // gives each plater 500 coin
            } 
        }//end of if statement
        //
        // Call the PlaceBets function so that we can place bets
        put.PlaceBets(p,numOfP);
        //
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
        cout<<endl;
        //Output the contents of each players hand
        if(numOfP>=1)
        {    
            cout<<p[1].getName() << "'s hand" << endl;
            cout<<p[1].getName() << "'s Coin : " <<p[1].getCredit()<< endl;
            for(j=0;j<b;j++)
            {
              deck.PrintCard(p[1].getHand(j));
            }
            cout<<endl;
        }
        if(numOfP>=2)
        {
            cout<<endl<<p[2].getName() << "'s hand" << endl;
            cout<<p[2].getName() << "'s Coin : " <<p[2].getCredit()<< endl;

            for(j=0;j<c;j++)
            {
                deck.PrintCard(p[2].getHand(j));
            }
            cout<<endl;
        }
        if(numOfP>=3)
        {
            cout<<endl<<p[3].getName() << "'s hand" << endl;
            cout<<p[3].getName() << "'s Coin : " <<p[3].getCredit()<< endl;

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
        CheckWin(p,put,numOfP);
        // count round
        round++;
        //
        cout<<"Round "<<round<<"Ended. Play another?"<<endl;
        cout<<"'Y' for yes 'N' for no."<<endl;
        cin>>answer;
        //while statement used for input validation
        while(answer!="N" && answer!="n" && answer!="Y" && answer!="y")
        {
            cout<<"Wrong input detected, only 'Y' for yes, or 'N' for no is"
                <<"accepted. Try again."<<endl;
            cin>>answer;
        }
        //
        //delete allocated data here
        cout<<"Would you like to reset game or continue?"<<endl;
        cout<<"'Y' for yes 'N' for no."<<endl;
        cin>>restart;
        //while statement used for input validation
        while(restart!="N" && restart!="n" && restart!="Y" && restart!="y")
        {
            cout<<"Wrong input detected, only 'Y' for yes, or 'N' for no is"
                <<"accepted. Try again."<<endl;
            cin>>restart;
        }
        if(restart=="y" || restart=="Y")
        {
            delete []p;
        }
        else if(restart=="n" || restart=="N")
        {
            cout<<"OK! Round " << round+1 << " starts now!"<<endl<<endl;
        }
        deck.~Deck(); 
    }
    cout<<"\n\nExiting Program"<<endl;
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
        cout<<p[1].getName()<<" Coin : "<<p[1].getCredit()<<endl;
            for(j=0;j<b;j++)
            {
                deck.PrintCard(p[1].getHand(j));
            }
        cout<<endl;
        }
        if(numOfP>=2)
        {
        cout<<endl<<p[2].getName() << "'s hand" << endl;
        cout<<p[2].getName()<<" Coin : "<<p[2].getCredit()<<endl;
            for(j=0;j<c;j++)
            {
                deck.PrintCard(p[2].getHand(j));
            }
        cout<<endl;
        }
        if(numOfP>=3)
        {
        cout<<endl<<p[3].getName() << "'s hand" << endl;
        cout<<p[3].getName()<<" Coin : "<<p[3].getCredit()<<endl;
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
    }
    if(numOfP>=2)
    {
        for(i=0;i<c;i++)
        {
            p[2].setTotal(i); 
        }
        cout << p[2].getName() <<" has a value of " << p[2].getTotal() 
             << endl<<endl;
    }
    if(numOfP>=3)
    {
        for(i=0;i<d;i++)
        {
            p[3].setTotal(i);
        }
        cout << p[3].getName() <<" has a value of " << p[3].getTotal() 
             << endl<<endl;
    }   
}

/*******************************************************************************
 * CheckWin Function:
 *   After the CheckSum function is called, this function gets called to see who
 * won. If sum is over 21, the function will say who busted.
 ******************************************************************************/
void CheckWin(Player *p,Bet &b , int numOfP)
{   
    
    //Variables to get max score
    int max;
    int score;
    string winner;
    int j;//counter
    
    for(int i=1;i<=numOfP;i++)
    {
    if(p[i].getTotal()<=21)
    {  
        if(p[0].getTotal()<p[i].getTotal() || p[0].getTotal()>21)
        {
            score=p[0].getTotal();
            max=score;
            //while loop statement used to check every players score to see who won
            //Checks for max total
            if(max<p[i].getTotal())// fiqure something out lol
            {
                score=p[i].getTotal();
                max=score;
                winner=p[i].getName();
            }
            j++; //counts one loop
            cout<<"This is the J counter... "<<j<<endl;
            //if statement executes one j = numOfP
            if(j<numOfP)
            {
            cout << winner <<" wins!" << endl;//player wins
            cout<<"Your " << winner << "'s new score is "<<p[i].getCredit()<<endl;
            p[i]+=(b.getLost(i))*2;//make this so that it can get the losses
                                   //of the player that bet           
            }
        }
        else if(p[0].getTotal()==p[i].getTotal())
        {
            cout << "Its a tie with the dealer with " << p[i].getName() 
                 <<" and since its house rules, you lose your bet!"
                 << " Play Again!"<<endl;//tie
            cout <<p[i].getName()<< " lost $" << b.getLost(i)<<"."<<endl;
            p[0]+=b.getLost(i);
        }
        else
        {
            cout <<"The dealer wins against "<<p[i].getName() << "."
                 << endl;//Dealer Wins
            cout <<p[i].getName()<< " lost $" << b.getLost(i)<<"."<<endl;
            p[0]+=b.getLost(i);
        }
    }
    else
    {
        cout<< p[i].getName() <<"'s hand busted! " <<p[i].getName()
                << " is out of the game."<< endl;
    }
    }//end of for loop
    // Output
    cout<<endl<<"Dealer's Coin :"<<endl;
    cout<<p[0].getCredit()<<endl;
    cout<<p[1].getName()<<"'s Coin :"<<endl;
    cout<<p[1].getCredit()<<endl;
    cout<<p[2].getName()<<"'s Coin :"<<endl;
    cout<<p[2].getCredit()<<endl;
    cout<<p[3].getName()<<"'s Coin :"<<endl;
    cout<<p[3].getCredit()<<endl;
}