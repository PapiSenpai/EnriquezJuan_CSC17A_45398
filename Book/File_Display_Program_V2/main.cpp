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
    
    ifstream inFile;
    inFile.open(file);

    if(!inFile)
        cout << "Error opening file, or file doesn't exist!";
        
        
    cin.ignore();

    for(int i=0; !inFile.eof(); i++){
        
        if(i%5==0){
            system("Pause");
        }
        
        getline(inFile, lineRead);
        cout<< lineRead << endl;
    }
    
    //Exit stage left
    inFile.close();
    return 0;
}