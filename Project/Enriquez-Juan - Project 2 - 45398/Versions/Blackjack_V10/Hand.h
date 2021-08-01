/* 
 * File:   Hand.h
 * Author: MSOS
 *
 * Created on July 31, 2021, 1:52 PM
 */

#ifndef HAND_H
#define HAND_H

/******************************************************************************
* Hand Class
******************************************************************************/
class Hand
{
    private:
        Card hand[20]; 
    public:
        // Destructor
        ~Hand()
        {
            delete []hand;
        }
        // Accessor
        void setHand(Deck &d, int i)
        {
            hand[i]=(d.draw());
        }
        //mutator
        Card getHand(int x)
        {
            return hand[x];            
        }
};
#endif /* HAND_H */