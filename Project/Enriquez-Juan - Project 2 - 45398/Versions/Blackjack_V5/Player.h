
/* 
 * File:   Player.h
 * Author: MSOS
 *
 * Created on July 27, 2021, 4:15 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "Card.h"


/******************************************************************************
* Player Structure
******************************************************************************/
//template <typename T>
class Player{
private:
    string name;
    Card hand[20];
    int total;
public:
    //defualt constructor
    Player(){
        name="";
        total=0;
    }
    
    //accessor
    void setName(string n){
        name=n;
    }
    void setHand(Deck &d, int i)
    {
        hand[i]=(d.draw());
    }
    void setTotal(int x)
    {
        total+=hand[x].value;        
    }
    //mutator
    string getName()
    {
        return name;
    }
    Card getHand(int x)
    {
        return hand[x];            
    }
    int getTotal()
    {
        return total;
    }
};

#endif /* PLAYER_H */