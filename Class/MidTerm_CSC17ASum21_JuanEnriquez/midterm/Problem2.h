/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Problem2.h
 * Author: MSOS
 *
 * Created on July 16, 2021, 2:39 PM
 */

#ifndef PROBLEM2_H
#define PROBLEM2_H

//System Libraries - Post Here
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
// Comeback to annotate and add descriptions

//Structures
struct Customer2{
    char *name;
    int hours;
    float rateOfPay;
};

// Function prototypes
void Time(Customer2 *,int , int &);
void IntergerToEnglish(Customer2 *c, int);

//Execution Begins Here
void prbm2() {
    
    // Variables
    int i; // counters
    int custIn=0;    //
    int number=0;
    // User Input
    cout << "Enter the number of employees being inputted." << endl;
    cin >> custIn;
            
    Customer2 *info = new Customer2[custIn]; // Makes structure array
    for(i=0; i<custIn; i++){ //                                       
        // 
        info[i].name=new char[20]; // You set size here
        cout << "Enter the Name that is less than 20 characters." << endl;
        cin.ignore(); // get rid of buffer
        cin.getline(info[i].name, sizeof(char[20]));
        //cin.ignore(); // get rid of buffer        
        //
        // 
        cout << "Input the amount of hours worked." << endl;
        cin >> info[i].hours;
        //
        cout << "Enter the rate of pay for " << info[i].name << "." << endl;
        cin >> info[i].rateOfPay;
        //
        // Function Calls and Output
        Time(info,i ,number);
        cout << "PetCo." << endl;
        cout << "6301 Pats Ranch Rd, Jurupa Valley, CA"<<endl;
        cout << "Name: " << info[i].name << "   Amount: " << number << endl;
        cout << "Amount: "; 
        IntergerToEnglish(info, number);
        cout << endl;
        cout << "Signature Line:___________________________" << endl;

        //Clean up allocated memory here
        // delete []info; // deletes all the contents of new Customer[i]
    }
    
    //Exit stage left
}
 
//
void Time(Customer2 *c, int i, int &n){
    if((c+i)->hours>=0 && (c+i)->hours<=20){
        cout << "You get straight-time" << endl;
        n = (c+i)->rateOfPay * 1 *(c+i)->hours;
    }
    else if((c+i)->hours>=21 && (c+i)->hours<=40){
        cout << "You get double-time pay!" << endl;
        n = (c+i)->rateOfPay * 2 * (c+i)->hours;
    }
    else if((c+i)->hours>=41){
        cout << "You get triple-time pay!" << endl;
        n = (c+i)->rateOfPay * 3 *(c+i)->hours;
    }
    else if((c+i)->hours<0){
        cout << "You entered a negative number, try again." << endl;
    }
}

void IntergerToEnglish(Customer2 *c, int n){

if(n>=1 && n<=9000){
    //Process or map Inputs to Outputs  
    //Determine 1000's, 100's, 10's, 1's
        unsigned char n1000s,n100s,n10s,n1s;
        n1000s=n/1000;   //Shift 3 places to the left
        n100s=n%1000/100;//Remainder of division of 1000 then shift 2 left
        n10s=n%100/10;   //Remainder of division of 100 then shift 1 left
        n1s=n%10;        //Remainder of division by 10
        
        //Output the number of 1000's in Roman Numerals
        //Using the Switch Statement
        switch(n1000s){
            case 9:cout<<"Nine-Thousand";
            break;
            case 8:cout<<"Eight-Thousand";
            break;
            case 7:cout<<"Seven-Thousand";
            break;
            case 6:cout<<"Six-Thousand";
            break;
            case 5:cout<<"Five-Thousand";
            break;
            case 4:cout<<"Four-Thousand";
            break;
            case 3:cout<<"Three-Thousand";
            break;
            case 2:cout<<"Two-Thousand";
            break;
            case 1:cout<<"One-Thousand";
            break;
        }
        
        //Output the number of 100's
        //Using the Ternary Operator
        cout<<(n100s==9?"Nine-Hundred":
               n100s==8?"Eight-Hundred":
               n100s==7?"Seven-Hundred":
               n100s==6?"Six-Hundred":
               n100s==5?"Five-Hundred":
               n100s==4?"Four-Hundred":
               n100s==3?"Three-Hundred":
               n100s==2?"Two-Hundred":
               n100s==1?"One-Hundred": "");
        
        //Output the number of 10's
        //Using Independent If Statements
        if(n10s==9)cout<<" Ninety";
        if(n10s==8)cout<<" Eighty";
        if(n10s==7)cout<<" Seventy";
        if(n10s==6)cout<<" Sixty";
        if(n10s==5)cout<<" Fifty";
        if(n10s==4)cout<<" Fourty";
        if(n10s==3)cout<<" Thirty";
        if(n10s==2)cout<<" Twenty";
        if(n10s==1)cout<<" Eleventy";
        
        //Output the number of 1's
        //Using Dependent If Statements
        if(n1s==9)cout<<"Nine";
        else if(n1s==8)cout<<"Eight";
        else if(n1s==7)cout<<"Seven";
        else if(n1s==6)cout<<"Six";
        else if(n1s==5)cout<<"Five";
        else if(n1s==4)cout<<"Four";
        else if(n1s==3)cout<<"Three";
        else if(n1s==2)cout<<"Two";
        else if(n1s==1)cout<<"One";
        
        //Reiterate the input value
        // cout<<" = "<<n<<endl;
                
    //The Path to Exit
    }else{
        cout<<"You have problems following Directions"<<endl;
        cout<<"Come back when you decide to comply"<<endl;
    }    
}

#endif /* PROBLEM2_H */

