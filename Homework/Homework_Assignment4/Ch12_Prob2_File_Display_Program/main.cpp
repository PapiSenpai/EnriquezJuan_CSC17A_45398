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


//Execution Begins Here
int main(int argc, char** argv) {
   
    // Variables
    string file, lineRead;
    int i,j;
    cout << "What is the name of the file?" << endl;
    cin >> file;
    
    fstream inFile(file, ios::in); // declared fstream and opens into input mode
    // checks if file exists
    if(!inFile)
        cout << "Error opening file, or file doesn't exist!";
        
        
    cin.ignore();

    for(int i=1; !inFile.eof(); i++){
        // if statement used to pause the program
        if(i%25==0){
            cout << "Paused, press enter to continue..." << endl;
            cin.get();
        }
        
        getline(inFile, lineRead);
        cout<< lineRead << endl;
    }
    
    //Exit stage left
    inFile.close();
    return 0;
}