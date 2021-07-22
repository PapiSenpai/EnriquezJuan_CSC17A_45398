/* 
 * File:   main.cpp
 * Author: Juan Enriquez
 * Purpose: 
 * Version: 1
 * Created on July 13, 2021, 2:41 PM
 */

//System Libraries - Post Here
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
   
    // Variables
    string file, lineRead;
    int i,j;
    cout << "What is the name of the file?" << endl;
    cin >> file;
    
     
    fstream inFile(file, ios::in);
    
    // checks if file exists
    if(!inFile)
        cout << "Error opening file, or file doesn't exist!";
        
        
    cin.ignore(); // used to get rid of buffer

    for(int i=1; i<10; i++){
        // If statement used to stop the program if there are
        // more than ten lines
        if(inFile.eof()){
            cout << "End of file reached!\n" << endl;
            break;
        }
        
        getline(inFile, lineRead);
        cout<< lineRead << endl;
    }
    
    //Exit stage left
    inFile.close(); //close file
    return 0;
}