
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
class Player
{
private:
    string name;
    Card hand[20];
    int total;
    float credit;
public:
    //defualt constructor
    Player(){
        name="";
        total=0;
        credit=0;
    }
    Player(string n){//poly??
        name=n;
        total=0;
        credit=0;
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
    void setCredit(float c)
    {
        credit=c;
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