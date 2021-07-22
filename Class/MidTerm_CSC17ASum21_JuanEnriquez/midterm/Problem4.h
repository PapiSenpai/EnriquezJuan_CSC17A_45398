/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Problem4.h
 * Author: MSOS
 *
 * Created on July 16, 2021, 2:40 PM
 */

#ifndef PROBLEM4_H
#define PROBLEM4_H

#include<iostream>
using namespace std;


// prototypes
void encrypt(int);
void decrypt(int);

void prbm4(){
    int number;
    cout<<"Enter the number to be encrypted: ";
    cin>>number; //user entering number to be encrypted
    encrypt(number); //encrypting number
    cout<<"Enter the number to be decrypted: ";
    cin>>number; //user entering number to be decrypted
    decrypt(number); //decrypting number
}

void encrypt(int a)
{
    int first,second,third,fourth; //for storing respective digit of a
    fourth=a%10; //storing fourth digit of a
    a/=10; //dividing a by 10
    third=a%10; //storing third digit of a
    a/=10; //dividing a by 10
    second=a%10; //storing second digit of a
    a/=10; //dividing a by 10
    first=a; //storing first digit of a
    if(first==8||first==9||second==8||second==9||third==8||third==9||fourth==8||fourth==9)
    { //if any digit is 8 or 9 print error message and return
        cout<<"8 or 9 cannot be in the number\n\n";
        return;
    }
    //encrypting each digit
    first=(first+6)%8;
    second=(second+6)%8;
    third=(third+6)%8;
    fourth=(fourth+6)%8;

    //the number should be number=1000*first+100*second+10*third+fourth
    //but swapping first with third and second with fourth
    int number=1000*third+100*fourth+10*first+second;
    cout<<"Encrypted number is "<<number<<endl; //displaying the number
}
void decrypt(int a)
{
    int first,second,third,fourth; //for storing respective digit of a
    fourth=a%10; //storing fourth digit of a
    a/=10; //dividing a by 10
    third=a%10; //storing third digit of a
    a/=10; //dividing a by 10
    second=a%10; //storing second digit of a
    a/=10; //dividing a by 10
    first=a; //storing first digit of a
    if(first==8||first==9||second==8||second==9||third==8||third==9||fourth==8||fourth==9)
    { //if any digit is 8 or 9 print error message and return
        cout<<"8 or 9 cannot be in the number\n\n";
        return;
    }

    //For decrypting we have to decrement 6 but the digit can become
    //negative so also adding 8 so that digits remains positive
    first=(first-6+8)%8;
    second=(second+2)%8;
    third=(third+2)%8;
    fourth=(fourth+2)%8;

    //the number should be number=1000*first+100*second+10*third+fourth
    //but swapping first with third and second with fourth
    int number=1000*third+100*fourth+10*first+second;
    cout<<"Decrypted number is "<<number<<endl; //displaying decrypted number
}

#endif /* PROBLEM4_H */

