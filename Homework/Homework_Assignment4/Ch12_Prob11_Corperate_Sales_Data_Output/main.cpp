
/* 
 * File:   main.cpp
 * Author: Juan Enriquez
 * Purpose: 
 * Version: 1
 * Created on July 12, 2021, 1:06 PM
 */

//System Libraries - Post Here
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here
struct Divison{
    string name[4] = {"North Division", "South Division", "East Division", 
                        "West Division"};
    int quarter[4] = {1,2,3,4};
    float qtSales[4];
};

//Function Prototypes - Post Here
void getSales(Divison &);
//Execution Begins Here
int main(int argc, char** argv) {

    //Declare variables or constants here
    //7 characters or less
    //Initialize Variables
    Divison output; // Structure var
    int i,j,k; //counters
    
    //Format and display outputs here
    cout << "Enter the sales for the 4 quarters." << endl;
    getSales(output);
    
    //Exit stage left
    
    return 0;
}

void getSales(Divison &output){ //passes the whole structure
    
    fstream out("Output.txt", ios:: out); // opens in output 
                                                             // then binary mode
    float amount=0; // To type in sales
    float total=0;
    for(int i=0; i<4; i++){
        cout << "Enter quarterly sales for " << output.name[i] << endl;
        out << output.name[i] << endl;
        for (int j=0; j<4; j++){
            cin >> amount;
            
            // while loop used to accept only non negative values
            while (amount<=0){
                cout << "Enter a value that is not negative." << endl;
                cin >> amount;
            }
            
            out<< "Quarter " << output.quarter[j] << endl;
            out<< fixed << setprecision(2) << "$" << amount; 
            out << endl;
            total += amount; // adds up amount
        }
        output.qtSales[i] = total; // 
        out << "Total Sales of Quarter: $" << output.qtSales[i] << endl << endl;
        total = 0; // reset total to 0
    }
    out.close(); //close file
}//ctrl + /

void writeToFile(Divison output){
    
    fstream out;
    
    
}