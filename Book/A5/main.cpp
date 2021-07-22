/* 
 * File:   main.cpp
 * Author: Juan Enriquez
 * Created on June 29, 12:00 PM
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int [],int);
int stat(const int [],int,int &,int &);
void print(const int [],int,int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    // print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}

/******************************
 * read Function:
 * The purpose of this function
 * is to read values in an 
 * array.
 * ****************************/
 void read(int array[], int sizeIn)
 {

     for(int i=0; i < sizeIn; i++)
     {
         cin >> array[i];
     }
     
 }
 
 /***************************************
  * stat Function:
  * Purpose of this function is to find
  * max and min.
  * *************************************/
 int stat(const int array[],int sizeIn,int &max,int &min)
 {
    min = array[0];
    max = array[0];
    
    // lowest interger
    for (int i = 1; i < sizeIn; i++)
    {        
        if (array[i] > min)
        {
            min = array[i];
        }
    }
    // return min;
    
    // check for highest interger
    for (int i = 1; i < sizeIn ; i++)
    {
       if (array[i] < max)
       {
           max = array[i];
       }
 
    }
    // return max;
     
    // sum    
    double total = 0;
    
    for (int i=0 ; i < sizeIn ; i++)
    {
        total += array[i];
    }
    //return total;
    print(array,sizeIn,max,min,total);
 }
 
 void print(const int array[],int sizeIn, int max,int min,int total){
   
     for (int i=0; i < sizeIn; i++)
     {
         cout << "a[" << i << "] = " <<array[i] << endl;
     }

    cout << "Min  = " << max << endl;
    cout << "Max  = " << min << endl;
    cout << "Sum  = " << total << endl;
 }
