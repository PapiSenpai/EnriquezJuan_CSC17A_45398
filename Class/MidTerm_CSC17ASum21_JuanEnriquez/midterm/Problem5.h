/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Problem5.h
 * Author: MSOS
 *
 * Created on July 16, 2021, 2:39 PM
 */

#ifndef PROBLEM5_H
#define PROBLEM5_H

#include <iostream>
#include <string>
using namespace std;

//for byte type
char factorial_byte()
{
   // use instead of char since short int holds numbers
   char num;
   int n=1;
   int f=1;
   int pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before 
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<127) continue;//when out of range 127 which is the size of char, 
                          //stop the loop
       else break;
   }
   num = 0+pf;
    //return the largest factorial n, ie., pf
   return pf;
}

//for signed byte type
signed char factorial_signed_byte()
{
   // use instead of char since short int holds numbers
   signed char num;
   int n=1;
   int f=1;
   int pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before 
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<127) continue;//when out of range 127 which is the size of char, 
                          //stop the loop
       else break;
   }
   num = pf;
    //return the largest factorial n, ie., pf
   return pf;
}

//for unsigned byte type
unsigned char factorial_unsigned_byte()
{
   // use instead of char since short int holds numbers
   signed char num;
   int n=1;
   int f=1;
   int pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before 
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<255) continue;//when out of range 127 which is the size of char, 
                          //stop the loop
       else break;
   }
   num = pf;
    //return the largest factorial n, ie., pf
   return pf;
}


//for short type
short factorial_short()
{
  
   short n=1;
   unsigned short f=1;
   unsigned short pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<32767) continue;//when out of range 127, stop the loop
       else break;
   }
   
   return pf; //return the largest factorial n, ie., pf
}

//for signed short type
signed short factorial_signed_short()
{
  
   short n=1;
   unsigned short f=1;
   unsigned short pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<32767) continue;//when out of range 127, stop the loop
       else break;
   }
   
   return pf; //return the largest factorial n, ie., pf
}
//for unsigned short type
unsigned short factorial_unsigned_short()
{
  
   int n=1;
   int f=1;
   unsigned short pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<65535) continue;//when out of range 127, stop the loop
       else break;
   }
   
   return pf; //return the largest factorial n, ie., pf
}

//for int type
int factorial_int()
{
  
   long n=1;
   long f=1;
   int pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before 
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<2147483647) continue;//when out of range, stop the loop
       else break;
   }
   return pf; //return the largest factorial n, ie., pf
}

//for signed int type
signed int factorial_signed_int()
{
  
   long n=1;
   long f=1;
   signed int pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before 
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<2147483647) continue;//when out of range, stop the loop
       else break;
   }
   return pf; //return the largest factorial n, ie., pf
}

//for unsigned int type
unsigned int factorial_unsigned_int()
{
  
   float n=1;
   float f=1;
   unsigned int pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before 
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<4294967295) continue;//when out of range, stop the loop
       else break;
   }
   return pf; //return the largest factorial n, ie., pf
}

//for long type
long factorial_long()
{
  
   long n=1;
   long f=1;
   long pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before 
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<2147483647) continue;//when out of range 2147483647, stop the loop
       else break;
   }
   return pf; //return the largest factorial n, ie., pf
}

//for signed long type
signed long factorial_signed_long()
{
  
   long n=1;
   long f=1;
   signed long pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before 
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<2147483647) continue;//when out of range 2147483647, stop the loop
       else break;
   }
   return pf; //return the largest factorial n, ie., pf
}

//for signed long int type
unsigned long factorial_unsigned_long()
{
  
   float n=1;
   float f=1;
   unsigned long pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before 
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<4294967295) continue;//when out of range 2147483647, stop the loop
       else break;
   }
   return pf; //return the largest factorial n, ie., pf
}

//for unsigned float type
float factorial_float()
{
  
   float n=1;
   float f=1;
   float pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before 
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<9999999) continue;//when out of range maximum 7 digit value
       else break;
   }
   return pf; //return the largest factorial n, ie., pf
}


//for double type
double factorial_double()
{
  
   double n=1;
   double f=1;
   double pf;
   while(1) //repeat true enter loop
   {
       pf=f;//get previous factorial to pf, pf follows f previous value before 
            //range of f
       f=f*n;
       n++;//decrement n
       if(f<999999999999999) continue;//when out of range maximum 15 digit value
       else break;
   }
   return pf; //return the largest factorial n, ie., pf
}


//main program here  
void prbm5()
{
   cout<<"\nLargest factorial from byte type: "
           <<static_cast<signed>(factorial_byte());
   cout<<"\nLargest factorial from signed byte type: "
           <<static_cast<signed>(factorial_signed_byte());
   cout<<"\nLargest factorial from unsigned byte type: "
           <<static_cast<unsigned>(factorial_unsigned_byte());
   cout<<"\nLargest factorial from short type: "<<factorial_short();
   cout<<"\nLargest factorial from signed short type: "
           <<factorial_signed_short();
   cout<<"\nLargest factorial from unsigned short type: "
           <<factorial_unsigned_short();
   cout<<"\nLargest factorial from int type: "<<factorial_int();
   cout<<"\nLargest factorial from signed int type: "<<factorial_signed_int();
   cout<<"\nLargest factorial from unsigned int type: "
           <<factorial_unsigned_int();
   cout<<"\nLargest factorial from long type: "<<factorial_long();
   cout<<"\nLargest factorial from signed long type: "<<factorial_signed_long();
   cout<<"\nLargest factorial from unsigned long type: "
           <<factorial_unsigned_long();
   cout<<"\nLargest factorial from float type: "<<factorial_float();
   cout<<"\nLargest factorial from double type: "<<factorial_double();

  
}

#endif /* PROBLEM5_H */

