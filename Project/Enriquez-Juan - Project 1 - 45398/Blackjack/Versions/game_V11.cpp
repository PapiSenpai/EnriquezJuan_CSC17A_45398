 
/* 
 * File:   game.cpp
 * Author: Juan Enriquez
 * Purpose: To create a program that plays the 21 card game
 * Version: 9
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
*Card Structure
*******************************************************************************/
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
};

/******************************************************************************
* Player Structure
******************************************************************************/
struct Player{
    string name;
    Card hand[20];
    int total;
};

//User Libraries - Post Here

//Function Prototypes - Post Here
void PrintCard(Card);
void PrintValue(Card);
void PrintSuit(Card);
void shuffle(Deck &);
void PrintAll(Deck);
void SetupCards(Deck &);
Card draw(Deck &, int &); //returns drawn card
void Dealer(Deck &, Player *,int ,int &, int &, int &, int &, int &);
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
    Deck deck;
    Player *p; // struct array of 4 to hold 4 players
    //
    // Variables
    fstream rules; // set up to open file for da rules
    char *fileName="Rules.txt"; // c-string thing
    string readLine;
    int numOfP; // Number of players
    int i; //counter
    int j; //counter
    int a=2,b=2,c=2,d=2; 
    int index=51;
    //
    // Actions
    //
    rules.open(fileName, ios::in); // opens a file and put it into input mode
    while(getline(rules, readLine)) // while loop used to print out contents
    {
        cout << readLine <<endl;
    }
    rules.close(); //closes file
    //
    cout << "How many players are playing? Only 3 can play at the " 
         << "same time including the dealer." << endl;
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
    // Create a dynamic struct for people
    p = new Player[4];
    
    cout << "Enter name for the players." << endl;    
    for(i=1;i<=numOfP;i++) //for loop used to enter name to each Player 
    {                     //structure array
        cin >> p[i].name;
    }
    //
    //function call to set the deck of cards
    SetupCards(deck);
    //
    // for loop that draws cards for each player until there are 2 cards
    for(i=0;i<=numOfP;i++)
    {
        for(j=0;j<2;j++)
        {
          p[i].hand[j] = draw(deck, index); 
        }
    }
    //
    // Function call so that players can draw more cards
    Dealer(deck,p,numOfP,index,a,b,c,d);
    cout <<p[0].total<<endl;
    //   
    CheckSum(p,numOfP,b,c,d);
    CheckWin(p,numOfP);
    cout <<p[0].total<<endl;

    //delete allocated data here
    delete []p;
    // Exit stage right
    return 0;
}


/*****************************************************************************
* Shuffle Function:
*   Will shuffle the deck of cards
*****************************************************************************/
void PrintCard(Card c)
{
    PrintValue(c);
    cout << " of ";
    PrintSuit(c);
    cout << endl;
}

/*****************************************************************************
* PrintValue Function:
*   Prints out the value
*****************************************************************************/
void PrintValue(Card c)
{
    if(c.name==CardName::Ace)
    {
        cout<<"Ace";
        c.value=11;
    }
    else if(c.name==CardName::Jack)
    {
        cout<<"Jack";
        c.value=10;
    }

    else if(c.name==CardName::Queen)
    {
        cout<<"Queen";
        c.value=10;
    }
    else if(c.name==CardName::King)
    {
        cout<<"King";
        c.value=10;
    }
    else
    {
        cout << c.value;
    }
}

/*****************************************************************************
* PrintSuit Function:
*   Prints out the suit to each respective card
*****************************************************************************/
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
    Card temp=d.arrCards[0]; // makes temp start at the first Card struct
    for (n=0;n<52;n++)
    {
        m=rand()%52; // gives a random number 
        temp=d.arrCards[n]; // switches the contents of d.arrCards[n] with what
                            // is in d.arrCards[m]
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
            d.arrCards[index]; // Prints contents in a card struct 
        }
    }
    //PrintCard(d.arrCards[0]); // this can call each individually
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
 * Draw Structure Function:
 *   This function allows to draw a card from the deck of cards
 ******************************************************************************/
Card draw(Deck &d, int &index) 
{   
    
    cout<<index<<endl; // erase later
    return d.arrCards[index--]; //returns whole struct array
}

/*******************************************************************************
 * Dealer Function:
 *   This function allows player to draw additional cards from the deck.
 ******************************************************************************/
void Dealer(Deck &deck, Player *p,int numOfP, int &index,int &a, int &b, int &c, int &d)
{
    int choice,i,j;
    
    cout << "Do you want to draw more cards?"<<endl;//add more to fit menu description
    cin >> choice;
    //
    while(choice!=4){
        //        
        if(choice==1)
        {
            p[1].hand[b] = draw(deck, index);
            b++;
        }
        else if(choice==2)
        {
            p[2].hand[c] = draw(deck, index);
            c++;
        }
        else if(choice==3)
        {
            p[3].hand[d] = draw(deck, index);
            d++;
        }
        else
        {
            cout<<"That is not a valid choice! Try again." << endl;
        }
        //
        //Output the contents of each players hand
        if(numOfP>=1)
        {    
            cout<<p[1].name << endl;
            for(j=0;j<b;j++)
            {
              PrintCard(p[1].hand[j]);
            }
        }
        if(numOfP>=2)
        {
            cout<<p[2].name << endl;
            for(j=0;j<c;j++)
            {
                PrintCard(p[2].hand[j]);
            }
        }
        if(numOfP>=3)
        {
            cout<<p[3].name << endl;
            for(j=0;j<d;j++)
            {
                PrintCard(p[3].hand[j]);
            }
        }
        //
        cout << "Do you want to draw more cards?"<<endl;
        cin >> choice;
    }
    int total=0;
    // calculates total for dealer
    for(i=0;i<a;i++)
        {
            total+=p[0].hand[i].value;
            cout << "This is a value " << total << endl;
        }
    p[0].total=total;
    while(p[0].total<17) // should draw until busts or wins
    {      
        p[0].hand[a] = draw(deck, index); //draws card
        total+=p[0].hand[a].value;
        p[0].total=total;
        a++;
    }
}

/*******************************************************************************
 * CheckSum Function:
 *   After the player(s) are done drawing cards form the Dealer function, this
 * function gets called to sum up the contents of each players hand.
 ******************************************************************************/
void CheckSum(Player *p,int numOfP, int b, int c, int d)
{
    int *sum; // holds the sum of each players hand
    int i;
    int total=0;
    sum = new int[4];
    // if statement
    if(numOfP>=1)
    {
        for(i=0;i<b;i++)
        {
            total+=p[1].hand[i].value;
            cout << "This is a value " << total << endl;
            sum[1]= total; // i dont need
        }
        p[1].total=total;
        total=0;
        cout<<sum[1]<<endl;
    }
    if(numOfP>=2)
    {
        for(i=0;i<b;i++)
        {
            total+=p[2].hand[i].value;
            cout << "This is a value " << total << endl;
            sum[2]= total;
        }
        p[2].total=total;
        total=0;    
        cout<<sum[2]<<endl;
    }
    if(numOfP>=3)
    {
        for(i=0;i<c;i++)
        {
            total+=p[3].hand[i].value;
            cout << "This is a value " << total << endl;
            sum[3]= total;
        }
        p[3].total=total;
        total=0;
        cout<<sum[2] <<endl;
    }
    
}

/*******************************************************************************
 * CheckWin Function:
 *   After the CheckSum function is called, this function gets called to see who
 * won. If sum is over 21, the function will say who busted.
 ******************************************************************************/
void CheckWin(Player *p,int numOfP)
{
    int i,j;
    
    for(i=1;i<=numOfP;i++)
    {
        if(p[i].total<=21)
        {  
            if(p[0].total<p[i].total || p[0].total>21)
            {
                cout << p[i].name <<" wins!";//player wins
            }
            else if(p[0].total==p[i].total)
            {
                cout << "Its a tie with the dealer with " << p[i].name <<"."
                        <<endl;//tie
            }
            else
            {
                cout <<"The dealer wins against "<<p[i].name << "."
                        << endl;//Dealer Wins
            }
        }
        else
        {
            cout<<"Your hand busted! " <<p[i].name[i]<< " is out of the game."
                << endl;
        }
    }

}