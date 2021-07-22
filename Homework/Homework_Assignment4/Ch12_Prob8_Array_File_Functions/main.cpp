

/* 
 * File:   main.cpp
 * Author: Juan Enriquez
 * Purpose: 
 * Version: 1
 * Created on July 12, 2021, 12:18 PM
 */

//System Libraries - Post Here
#include <iostream>
#include <string> //to work with strings
#include <fstream>
using namespace std;

//function prototypes
void arrayToFile(string, int *, int);
void fileToArray(string, int *, int);

int main()
{
    //declare constant array size
    const int ARRAY_SIZE = 5;

    //declare array and populate with values
    int arrayToWrite[ARRAY_SIZE] = {100, 172, 3, 4, 5};

    //declare array to display after reading from file
    int arrayFromFile[ARRAY_SIZE];

    //call arrayToFile function to write into file
    cout << "Now writing into file...\n";
    arrayToFile("array.dat", arrayToWrite, sizeof(arrayToWrite));
    cout << "Done!\n";

    //call fileToArray function to read from file
    cout << "Now reading from file...\n";
    fileToArray("array.dat", arrayFromFile, sizeof(arrayFromFile));
    cout << "Done!\n\n";

    //display the array that was just read
    cout << "This is what we read from the file:\n";
    for(int counter = 0; counter < ARRAY_SIZE; counter++)
        cout << arrayFromFile[counter] << ", ";

    return 0;
}

void arrayToFile(string fileName, int *inputArray, int arrSize){
    //define file stream object and open the file
    ofstream outputFile(fileName, ios::binary);

    //write into file
    outputFile.write(reinterpret_cast<char  *>(inputArray), arrSize);

    //close file
    outputFile.close();
}

void fileToArray(string fileName, int *outputArray, int arrSize){
    //define file stream object and open the file
    ifstream inputFile(fileName, ios::binary);

    //read from file
    inputFile.read(reinterpret_cast<char *>(outputArray), arrSize);

    //close file
    inputFile.close();
}