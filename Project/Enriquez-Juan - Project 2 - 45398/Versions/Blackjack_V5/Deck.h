/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Deck.h
 * Author: MSOS
 *
 * Created on July 27, 2021, 4:14 PM
 */

#ifndef DECK_H
#define DECK_H

#include "Suits.h"
#include "CardName.h"
/******************************************************************************
* Deck Class
******************************************************************************/
class Deck:public Card{ //inheritence and aggregation
private:
    Card arrCards[52]; // make into a dynamically allocated structure array
    int index;
public:
    // Constructor
    Deck(){
        index=0;
        for(int col=(int)Suits::Clubs; col<=(int)Suits::Spades; col++)
        {
            for(int row=(int)CardName::Ace; row <= (int)CardName::King; row++)
            {
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
                arrCards[index++]=c;
            }
        }index--;
        shuffle(); //call shuffle function
    }
    //accessor Function
    void setArrayOfCards(Card c){
        for(int i=0;i<52;i++){
            arrCards[i]=c;
        }
    }
    //mutator Function
    Card getArrayOfCards() const{
        for(int i=0;i<52;i++){
            return arrCards[i];
        }
    }
//member functions (methods)
/*****************************************************************************
* PrintCard Function:
*   Will print out the card that is called.
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
    

/*****************************************************************************
* Shuffle Function:
*   Will shuffle the deck of cards
*****************************************************************************/
    void shuffle()
    {
        int n,m;
        Card temp=arrCards[0]; // makes temp start at the first Card struct
        for (n=0;n<52;n++)
        {
            m=rand()%52; // gives a random number 
            temp=arrCards[n]; // switches the contents of d.arrCards[n] with what
                                // is in d.arrCards[m]
            arrCards[n]=arrCards[m];
            arrCards[m]=temp;
        }
    }
/*****************************************************************************
* PrintAll Function:
*   This function will print the cards of the deck(just a test case)
*****************************************************************************/
    void PrintAll()
    {
        for(int col=(int)Suits::Clubs; col<=(int)Suits::Spades; col++)
        {
            for(int row=(int)CardName::Ace; row <= (int)CardName::King; row++)
            {
                int index=(13*col)+row-1;     // accesses the contents of arrCards
                PrintCard(arrCards[index]); // Prints contents in a card struct 
            }
        }
        //PrintCard(d.arrCards[0]); // this can call each individually
    }
/*******************************************************************************
 * Draw Structure Function:
 *   This function allows to draw a card from the deck of cards
 ******************************************************************************/
    Card draw() 
    {   
        return arrCards[index--]; //returns whole struct array
    }
    
};
#endif /* DECK_H */