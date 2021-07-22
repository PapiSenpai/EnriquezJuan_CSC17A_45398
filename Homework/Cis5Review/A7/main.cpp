/* 
 * File:   main.cpp
 * Author: Juan Enriquez
 * Created on June 30, 1:00 PM
 * Purpose:  Sum Rows, Sum Columns, Grand Sum of an integer array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <iomanip> //setw(10)
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;  //Max Columns much larger than needed.

//Function Prototypes Here
void read(int [][COLMAX],int &,int &);//Prompt for size then table
void sum(const int [][COLMAX],int,int,int[][COLMAX]);//Sum rows,col,grand total
void print(const int [][COLMAX],int,int,int);//Either table can be printed

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //Max Rows much larger than needed
    int array[ROW][COLMAX]={};  //Declare original array
    int augAry[ROW][COLMAX]={}; //Actual augmented table row+1, col+1
    int row,col;                
    
    //Input the original table
    read(array,row,col);
    
    //Augment the original table by the sums
    sum(array,row,col,augAry);
    
    //Output the original array
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);//setw(10)
    
    //Output the augmented array
    cout<<endl<<"The Augmented Array"<<endl;
    print(augAry,row+1,col+1,10);//setw(10)
    
    //Exit
    return 0;
}

void read(int array[][COLMAX], int &row, int &col){
    cout << "Input a table and output the Augment row,col and total sums." << endl;
    cout << "First input the number of rows and cols. <20 for each" << endl;
    
    cin >> row >> col;
    cout << "Now input the table." << endl;
    // for loop initailized to enter values
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cin >> array[i][j];
        }
    }
}

void sum(const int array[][COLMAX],int row,int col,int augAry[][COLMAX]){
    for(int i = 0; i < col; i++){
        augAry[row][i] = 0;     // This sets what is at the ends of the rows to zero
    }
    for(int i = 0; i < row; i++){
        augAry[i][col]  = 0;      // This sets what is at the ends of the cols to zero
        for(int j = 0; j < col; j++){
            augAry[i][j] = array[i][j];      // copies values
            augAry[i][col] += array[i][j];   // adds values of the row
            augAry[row][j] += array[i][j];   // adds values of the col
            augAry[row][col] += array[i][j]; // adds the values left over
        }
    }
}

void print(const int array[][COLMAX], int row, int col, int width){
for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
        cout << setw(width) << array[i][j] ;
        }
    cout << "\n";
    }
}