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

/******************************************************************************
* Deck Class
******************************************************************************/
class Deck:public Card{ //inheritence and aggregation
public:
    Card arrCards[52]; // make into a dynamically allocated structure array
    
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
};
#endif /* DECK_H */