/* 
 * File:   main.cpp
 * Author: Juan Enriquez
 * Created on June 27, 5:00 PM
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char [], int sizeIn);
void sort(char [],int);
void print(const char [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array,SIZE);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same   
    //Else output different size to sort
    if(sizeDet==sizeIn){
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}

/******************************
 * read Function:
 * The purpose of this function
 * is to read values in an 
 * array.
 * ****************************/
 int read(char array[], int SIZE) 
 {

     for(int i=0; i < SIZE; i++)
     {
         cin >> array[i];
     }
     
     int length;
     length = strlen(array);
     
     return length;
 }
 
 /******************************
 * sort Function:
 * The porpose of this function
 * is to sort the array.
 * ****************************/
 void sort(char array[], int sizeIn)
 {
     bool swap;
     int temp;
     
     do
     {
         swap = false;
         for(int count = 0; count < (sizeIn - 1); count++)
         {
             if(array[count] > array[count + 1])
             {
                 temp = array[count];
                 array[count] = array[count + 1];
                 array[count + 1] = temp;
                 swap = true;
             }
         }
     }while(swap);
    
 }
 
 /******************************
 * print Function:
 * The purpose of this function
 * is to output the contents of
 * the array.
 * ****************************/
 void print(const char array[], int sizeIn)
 {
     for(int i=0; i < sizeIn; i++)
     {
         cout << array[i];
     }
     cout << endl;
 }
 