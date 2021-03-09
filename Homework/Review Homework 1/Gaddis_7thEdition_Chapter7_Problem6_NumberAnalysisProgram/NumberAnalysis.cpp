/* 
 * File:   NumberAnalysis.cpp
 * Author: Juan Enriquez
 * Created on March 8, 2021, 2:33 PM
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// function prototypes
double LowestNum(double array[], int count);
double HighestNum(double array[], int count);
double TotalSum(double array[], int count); 
double AverageSum(double array[], int count);


/**********************************
 * The purpose of this project is
 * to get numbers from a file and 
 * insert them into an array where
 * it will then display according 
 * to the problems instructions.
 **********************************/
int main()
{
    // constants
    const int SIZE = 100; // size of array
    
    // Variables
    ifstream infile;
    double array[SIZE];
    int count = 0;
    int i; // counter
    

    // Open The file
    infile.open("Numbers.txt");
    
    //Exit program if there is no file that exists
    if (!infile)
    {
        cout << "File did not read.";
        exit(1);
    }
    
    // read the numbers that are in the file and insert to
    // to an array
    while (count < SIZE && infile >> array[count]) //as
    {
       count++;                   
    }
    
    // close the file
    infile.close();
    
    // OUTPUT
    cout << "The lowest number in the file is: " << LowestNum(array, count) << endl;
    cout << "The highest number in the file is: " << HighestNum(array, count) << endl;
    cout << "The total Sum is: " << TotalSum(array, count) << endl;
    cout << setprecision(2) << fixed;
    cout << "The Average Sum is: " << AverageSum(array, count) << endl;
    
    return 0;
}

/***************************
 * Function: LowestNum 
 * Finds the lowest number
 ***************************/
double LowestNum(double array[], int count)
{
    
    double lowest = array[0];
    
    for (int i = 1; i < count; i++)
    {        
        if (array[i] < lowest)
        {
            lowest = array[i];
        }
    }
    return lowest;
}

/***************************
 * Function: HighestNum 
 * Finds the highest number
 ***************************/
double HighestNum(double array[], int count)
{
    double highest = array[0];
    
    for (int i = 1; i < count ; i++)
    {
       if (array[i] > highest)
       {
           highest = array[i];
       }
 
    }
    return highest;
}


/***************************
 * Function: TotalSum
 * Finds the total sum of 
 * numbers in the file 
 ***************************/
double TotalSum (double array[], int count)
{
    double total = 0;
    
    for (int i=0 ; i < count ; i++)
    {
        total += array[i];
    }
    return total;
}

/***************************
 * Function: AverageSum 
 * Finds the average of the 
 * numbers within the file
 ***************************/
double AverageSum (double array[], int count)
{
    double sum = 0;
    
    for (int i=0 ; i < count ; i++)
    {
        sum += array[i];                
    }
    
    double average = sum / count;
    
    return average;
}