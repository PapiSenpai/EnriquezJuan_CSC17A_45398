/* 
 * File:   Bet.h
 * Author: MSOS
 *
 * Created on July 28, 2021, 11:31 PM
 */

#ifndef BET_H
#define BET_H

#include<string>
#include "Player.h"
using namespace std;

//class derived form player
//template <typename T>//do more on this in a 
class Bet: public Player
{
    private:
        float bet;      //ask how much the player wants to bet
        float amount;   //amount left over
        float *lost;     //amount lost
    public:
        //default constructor
        Bet()
        {
            bet=0;
            amount=0;
        }
        //Paramerterized constructor
        Bet(float b,float a) //poly
        {
            bet=b;
            amount=a;
        }
        //destructor to erase bets if another new game is started
        
        //Accessors(I dont think i need these...)
        void setBet(float b)
        {
            bet=b;
        }
        void setAmount(float a)
        {
            amount=a;
        }
        //Mutators
        float getBet()
        {
            return bet;
        }
        float getAmount()
        {
            return amount; //gives out new amount
        }
        float getLost(int index)
        {
            return lost[index];
        }
        //
        // Member functions
       /************************************************************************
        *PlaceBets Member Function:
        * This will ask player for 
        ***********************************************************************/
        void PlaceBets(Player *p, int numOP)
        {
            //Create array
            lost=new float[numOP];
            
            //Variables
            string answer;
            int pep;
            //lists each players credits
            for(int i=0;i<numOP+1;i++)
            {
                lost[i]=0; //sets all lost to zero
                cout<<p[i].getName()<<endl;
                cout<<p[i].getCredit()<<endl<<endl;
            }
            // Input
            cout<<"Would you like to place bets? Type 'Y' for yes, 'N' for no."
                <<endl;
            cin>>answer;
            // input validation
            while(answer!="N" && answer!="n" && answer!="Y" && answer!="y")
            {
                cout<<"Wrong input detected, only 'Y' for yes, or 'N' for no is"
                    <<"accepted. Try again."<<endl;
                cin>>answer;
            }
            //
            // if statement which will exit class if answer was No
            if(answer=="Y" || answer=="y")
            {
                answer="";//removes contents of answer.
                //while statement used so that it loops each time the answer is
                //yes
                while(answer!="N" && answer!="n")
                { 
                    //resets pep to zero so that the while statement is used
                    pep=0;
                    //use if statement to take bet from correct player
                    if(numOP==1)
                    {
                        while(pep!=1)
                        {
                            cout<<"Press 1 if player 1 wants to give a bet."
                                <<endl;
                            cin>>pep;
                        }
                    }
                    else if(numOP==2)
                    {
                        while(pep!=1 && pep!=2)
                        {
                            cout<<"Press 1 if player 1 wants to give a bet."
                                <<endl<<"Press 2 if player 2 wants to give a"
                                <<" bet."<<endl;
                            cin>>pep;
                        }
                    }
                    else if(numOP==3)
                    {
                        while(pep!=1 && pep!=2 && pep!=3)
                        {
                            cout<<"Press 1 if player 1 wants to give a bet."
                                <<endl<<"Press 2 if player 2 wants to give a"
                                <<" bet."<<endl<<"Press 3 if player 3 wants to"
                                <<" give a bet."<<endl;
                            cin>>pep;
                        }
                    }
                    //
                    //if statement to go to correct player
                    if(pep==1)
                    {
                        cout<<"How much do you want to bet? You only have "
                            <<p[1].getCredit()<<endl;
                        cin>>bet;
                        // checks if the bet is within range
                        while(p[1].getCredit()<bet)
                        {
                            cout<<"Woah buddy, you're too broke to bet that "
                                <<"much. Bet below "<<p[1].getCredit()<<endl;
                            cin>>bet;
                        }
                        amount=p[1].getCredit();
                        p[1].setCredit(amount-bet);
                        cout<< p[1].getName() <<" new amount is "
                            << p[1].getCredit() << endl << endl;
                        lost[1]+=bet;
                    }
                    else if(pep==2)
                    {
                        cout<<"How much do you want to bet? You only have "
                            <<p[2].getCredit()<<endl;
                        cin>>bet;
                        // checks if the bet is within range
                        while(p[2].getCredit()<bet)
                        {
                            cout<<"Woah buddy, you're too broke to bet that "
                                <<"much. Bet below "<<p[2].getCredit()<<endl;
                            cin>>bet;
                        }
                        amount=p[2].getCredit();
                        p[2].setCredit(amount-bet);
                        cout<< p[2].getName() <<" new amount is "
                            << p[2].getCredit() << endl<<endl;
                        lost[2]+=bet;  
                    }
                    else if(pep==3)
                    {
                        cout<<"How much do you want to bet? You only have "
                            <<p[3].getCredit()<<endl;
                        cin>>bet;
                        // checks if the bet is within range
                        while(p[3].getCredit()<bet)
                        {
                            cout<<"Woah buddy, you're too broke to bet that "
                                <<"much. Bet below "<<p[3].getCredit()<<endl;
                            cin>>bet;
                        }
                        amount=p[3].getCredit();
                        p[3].setCredit(amount-bet);
                        cout<< p[3].getName() <<" new amount is "
                            <<p[3].getCredit()<<endl << endl;
                        lost[3]+=bet;
                    }
                    // 
                    cout<<"Will any others bet as well? Type 'Y' for yes, 'N' for"
                        <<" no."<<endl;
                    cin>>answer;
                    // nested while statement for user input
                    while(answer!="N" && answer!="n" && answer!="Y" && answer!="y")
                    {
                        cout<<"Wrong input detected, only 'Y' for yes, or 'N' for no is"
                            <<"accepted. Try again."<<endl;
                        cin>>answer;
                    }
                }
            }
            else
            {
                cout<<"Continue on..."<<endl;
            }
        }  
};

#endif /* BET_H */