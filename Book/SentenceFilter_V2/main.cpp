
/* 
 * File:   main.cpp
 * Author: Juan Enriquez
 * Purpose: 
 * Version: 2
 * Created on July 12, 2021, 12:23 AM
 */

//System Libraries - Post Here
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// For this version, use vector notation

//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here when needed

    //Declare variables or constants here
    //7 characters or less
    string out;
    string in;
    string sentence;
    
    //Initialize or input data here
    cout << "Enter two file names, one for input, the other for output." << endl;
    cin >> in >> out;
    
    ifstream inFile; //open file
    ofstream outFile; // open file
    outFile.open(out);
    inFile.open(in);          
    //Display initial conditions, headings here
    cin.ignore(); // to get rid of buffer(/n)
        while (getline(inFile, sentence));

        //if statement which is used to check if there are contents in file
        if(inFile){
            // Make first letter to uppercase
            sentence[0] = toupper(sentence[0]);
            // The rest of the character array becomes lower case
            for (int i=1; i<sentence.length();i++){
                sentence[i]=tolower(sentence[i]);
            }
            // enter the contents of sentence into File
            outFile << sentence;
        }
        else
            cout << "Error reading file" << endl;
    
    inFile.close(); // close files
    outFile.close();
    //Exit stage left
    return 0;
}