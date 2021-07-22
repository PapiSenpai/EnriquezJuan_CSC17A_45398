/* 
 * File:   menu.cpp
 * Author: Juan Enriquez
 * Purpose:  Menu using Functions, each option containing a solved problem
 */

//System Libraries
#include <iostream>


using namespace std;

//User Libraries
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"
#include "Problem5.h"
#include "Problem6.h"
#include "Problem7.h"

//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            case '8':{ cout<<"Exiting Menu"<<endl;
            break;
            }
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}

/*******************************************************************************
//                         Menu
//Input:  -> Parameters in Argument List, Description/Range/Units
//Output: -> Return, Description/Range/Units
*******************************************************************************/
void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl;
    cout<<"Type 8 to exit" <<endl;
}

/*******************************************************************************
//                         Problem 1
*******************************************************************************/
void prblm1(){
   prbm1();
}

/*******************************************************************************
//                         Problem 2
*******************************************************************************/
void prblm2(){
    prbm2();
}

/*******************************************************************************
//                         Problem 3
*******************************************************************************/
void prblm3(){
    cout<<"Included in another project."<<endl;
}

/*******************************************************************************
//                         Problem 4
*******************************************************************************/
void prblm4(){
    prbm4();
/*******************************************************************************
//                         Problem 5
*******************************************************************************/}
void prblm5(){
    prbm5();
    cout << endl;
}

/*******************************************************************************
//                         Problem 6
*******************************************************************************/
void prblm6(){
    prbm6();
}

/*******************************************************************************
//                         Problem 7
*******************************************************************************/
void prblm7(){
    cout<<"problem 7 incomplete"<<endl;
}
