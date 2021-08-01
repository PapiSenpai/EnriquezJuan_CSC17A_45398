/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bet.h
 * Author: MSOS
 *
 * Created on July 28, 2021, 11:31 PM
 */

#ifndef BET_H
#define BET_H

//class derived form player
template <typename T>//do more on this in a 
class Bet: public Player
{
    private:
        float bet;      //ask how much the player wants to bet
        float amount;   //amount left over
        float lost;     //amount lost
    public:
        //default constructor
        Bet()
        {
            bet=0;
            amount=0;
            lost=0;
        }
        //Paramerterized constructor
        Bet(float b,float a,float l)
        {
            bet=b;
            amount=a;
            lost=l;
        }
        //
        //Accessors
        void setBet(float b)
        {
            bet+=b;
        }
        void setAmount(float a)
        {
            amount=a;
        }
        void setLost(float l)
        {
            lost=l;
        }
        //
        //Mutators
        float getBet()
        {
            return bet;
        }
        
};

#endif /* BET_H */