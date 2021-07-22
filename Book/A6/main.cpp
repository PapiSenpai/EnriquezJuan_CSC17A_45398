/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}

/****************************************
* read Function:
* The purpose of this function input data
*****************************************/
void read(vector<int> &even, vector<int> &odd)
{
    
    int num {0};
    int EO {0};
    
    cout << "Input the number of integers to input." << endl;
    cin >> num;
    cout << "Input each number." << endl;
    
    // for loop to input numbers but seperate to diffenent vectors whether they are even or odd
    for(int i=0; i<num; i++){

            cin >> EO;
            if(EO % 2 == 0){
                 even.push_back(EO);
            }
            else{
                odd.push_back(EO);
            }  
    }

}

/************************************************
* copy Funtion:
* The purpose of this funtion is to copy the 
* contents of 2 seperate vectors into a 2D array.
**************************************************/
void copy(vector<int> even, vector<int> odd,int array[][COLMAX])
{
    int i = 0,j = 0; // counters
    int evenSize=even.size();
    int oddSize=odd.size();
    
    while(i<evenSize) // if even vector is large than odd vector then some even values will be remaining and to check that
    {
        array[i][0]=even[i];
        i++; //increasing even counter
    }
    while(j<oddSize) // if odd vector is large than even vector then some odd values will be remaining and to check that
    {
        array[j][1]=odd[j];
        j++; //increasing odd counter
    }
    
}

/******************************************
 * prntVec Function:
 * The purpose of this function is to print
 * the contents of vectors odd and even
 ******************/
void prntVec(vector<int> even, vector<int> odd,int n)//int n is the format setw(n)
{
    int i = 0,j = 0; // counters
    int evenSize=even.size();
    int oddSize=odd.size();
    cout << setw(n) << "Vector" << setw(n) << "Even" << setw(n) << "Odd" << endl;
    
    while(i < evenSize && j < oddSize) // while counters reach either all odd values or all even values
    {
        cout<<setw(n*2)<<even[i]<<setw(n)<<odd[j]<<endl; // output even and odd value
        i++; // increasing even counter
        j++; // increasing odd counter
    }
    while(i<evenSize) // if even vector is large than odd vector then some even values will be remaining and to check that
    {
        cout<<setw(n*2)<<even[i]<<endl; // output even vector values
        i++; //increasing even counter
    }
    while(j<oddSize) // if odd vector is large than even vector then some odd values will be remaining and to check that
    {
        cout<<setw(n*3)<<odd[j]<<endl; // output odd vector values
        j++; //increasing odd counter
    }
    
}

void prntAry(const int array[][COLMAX],int evenSize,int oddSize,int n)
{
    int i = 0,j = 0; // counters
    cout << setw(n) << "Array" << setw(n) << "Even" << setw(n) << "Odd" << endl;
    
    while(i < evenSize && j < oddSize) // while counters reach either all odd values or all even values
    {
        cout<<setw(n*2)<<array[i][0]<<setw(n)<<array[j][1]<<endl; // output even and odd value
        i++; // increasing even counter
        j++; // increasing odd counter
    }
    while(i<evenSize) // if even vector is large than odd vector then some even values will be remaining and to check that
    {
        cout<<setw(n*2)<<array[i][0]<<endl; // output even vector values
        i++; //increasing even counter
    }
    while(j<oddSize) // if odd vector is large than even vector then some odd values will be remaining and to check that
    {
        cout<<setw(n*3)<<array[j][1]<<endl; // output odd vector values
        j++; //increasing odd counter
    }
    
}
