/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Problem1.h
 * Author: MSOS
 *
 * Created on July 16, 2021, 2:37 PM
 */

#ifndef PROBLEM1_H
#define PROBLEM1_H

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
//Structures
struct Customer{
    int accNum;
    char *name;
    char *address;
    float balance;
    float *totChecks;
    float *totDepo;
};

//Execution Begins Here
void prbm1() {
    
    // Variables
    float totalSumC=0; // sum of all checks
    float totalSumD=0; // sum of all deposits
    float oldBal; // Holds balance that was inputted at the beginning
    int i,j,k; // counters
    int total=0;
    int number = 5;
    char exit;
    //
    // User Input
    cout << "Enter the Info of the Employee." << endl;
    Customer *info = new Customer; // Makes structure dynamically allocatable
        //
        cout << "Enter account number." << endl;
        cin >> info->accNum; 
        //        
        // Do-while statement used to confirm that the Account has five digits         
        do{
            number=info->accNum;
        // nested while statement used to check if there are five digits
        /* Why its used: If number = 1000 the number is divided by 
        * 10, what would be left over is 100, 
        * then because of the while loop's argument being 
        * (number != 0), the loop will continue until 
        * number=0.
        * Each time the while loop loops, increment total
        * by one.
        */
            while(number != 0){         
                total++;
                number /= 10; // divides whats in number by 10   
            }
            // if total results to anything else than 5, pass this
            // to pass conditions to the next iteration of the loop
            if(total!=5){ 
                    cout << "Enter a number the amounts to 5 digits..." << endl;
                    cin >>info->accNum;
                    total=0;
                } 
        }while(total != 5);
        //
        info->name=new char[20]; // You set size here
        cout << "Enter the Name that is less than 20 characters." << endl;
        cin.ignore();
        cin.getline(info->name, sizeof(char[20]));
        //
        info->address=new char[30];
        cout << "Enter your Address that is less that 30 characters." << endl;
        cin.ignore();
        cin.getline(info->address, sizeof(char[30]));
        //
        //info[i].balance=new float;
        cout << "Enter your account balance." << endl;
        cin >> info->balance;
        oldBal = info->balance;
        //
        // Input checks that the person
        i=0;
        info->totChecks=new float[100]; // dynamically allocating totDepo
        while(exit != 'e' && exit != 'E'){
            cout << "Enter the amount of checks used this month." << endl;
            cin >> info->totChecks[i];
            cout << "Press E to continue or C to enter more checks..." << endl;
            cin >> exit;
            // while(exit != 'c' && exit != 'C'); Get help from aid 
            totalSumC += info->totChecks[i];
            i++;
        }
        exit=0; // sets exit to zero so that is doesn't affect next while loop
        
        info->totDepo=new float[100]; // dynamically allocating totDepo
        while(exit != 'e' && exit != 'E'){
            cout << "Enter the amount of deposits made this month." << endl;
            cin >> info->totDepo[i];
            cout << "Press E to continue or C to enter more checks..." << endl;
            cin >> exit;
            totalSumD += info->totDepo[i];
            i++;
        }
    
    //
    info->balance += totalSumD - totalSumC; // sets the new balance
    //
    if(info->balance < 0){
        info->balance += 50;
        cout << "Your account is negative! Overdraft fee of $50 added."<< endl;
    }

    // Output of contents within used Structure
    cout << fixed << setprecision(2);
    cout << "Account Number: " << info->accNum << endl;
    cout << "Name: " << info->name << endl;
    cout << "Address: " << info->address << endl;
    cout << "Beginning Balance: $" << oldBal <<endl;
    cout << "Current Balance: $" << info->balance << endl;
    
    //Clean up allocated memory here
    delete []info; // resets the contents of new Customer[i]
    
    //Exit stage left
}

#endif /* PROBLEM1_H */

