
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
#include "Hand.h"


/******************************************************************************
* Player Class
******************************************************************************/
//template <typename T>
class Player
{
private:
    string name;
    int total;
    float credit;
public:
    //defualt constructor
    Player()
    {
        name="";
        total=0;
        credit=0;
    }
    // constructor 
    Player(string n){//poly??
        name=n;
        total=0;
        credit=0;
    }
    //accessor
    void setName(string n)
    {
        name=n;
    }
    
    void setTotal(Hand *l,int x)
    {
        total+=l->getHand(x).value;        
    }
    void setCredit(float c)
    {
        credit=c;
    }
    //mutator
    string getName()
    {
        return name;
    }
    
    int getTotal()
    {
        return total;
    }
    float getCredit()
    {
        return credit;  
    }
    
    friend Player operator+=(Player &p,float c){ //operator overloading+Freind thing
        p.credit+=c;
        return p;
    }
    // Member functions
};

#endif /* PLAYER_H */