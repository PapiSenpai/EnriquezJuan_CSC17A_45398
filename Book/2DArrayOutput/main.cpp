/* 
 * File:   main.cpp
 * Author: Juan Enriquez
 * Created: 9/13/20 12:29 AM
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int);//Sort by row
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    
    //Input the size of the array you are sorting
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
     if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
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
 int read(char array[][COLMAX],int &rowDet) 
 {
     
    rowDet = 0;
    while(cin >> array[rowDet++]) // to get the input
    {

    }
    
     
    int length [rowDet];
    for(int k=0;k<rowDet;k++){      // loop to record the array with 
        
        length[k] = strlen(array[k]);
        
// ask why (strcmp(length[0],length[k]); ) does not work
    
    if(length[0] < length[k]) // A way to get max or min
        length[0] = length[k];
    
     }
    return length[0];
 }
 
 /******************************
 * sort Function:
 * The porpose of this function
 * is to sort the array.
 * ****************************/
 void sort(char array[][COLMAX],int row,int col)
 {
     // FIX!!

   for(int i=0;i<=row;i++)
       for(int k=0;k<=col;k++){      //Loop for each position in List
        for(int j=i+1;j<row;j++){  //Loop to swap with first in List
            if(array[i][k]>array[j][k]){       //Put the smallest at top of List
                array[i][k]=array[i][k]^array[j][k];  //In place Swap
                array[j][k]=array[i][k]^array[j][k];  //In place Swap
                array[i][k]=array[i][k]^array[j][k];  //In place Swap
            }
        }
    }
    cout << array[2] << endl;
 }
 
 /******************************
 * print Function:
 * The purpose of this function
 * is to output the contents of
 * the array.
 * ****************************/
 void print(const char array[][COLMAX],int row,int col)
 {
     
     for(int i = 0; i <= row; i++)
     {
         cout << "array " << i << array[i] << endl;
     }
         
 }
 