/* 
 * File: Coperate Sales Data
 * Author: Juan Enriquez
 * Created on July 11, 5:00 PM
 * Purpose: The program uses a structure to store data in a company divison
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// structures
struct Divison{
    string name;
    float sales[4];
    float total;
    float avgSales;
};

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void DivisonCalculations(Divison &);
//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    
    //Initialize Variables
    Divison east = {"East"};
    Divison west = {"West"};
    Divison north = {"North"};
    Divison south = {"South"};
    //Process or map Inputs to Outputs
    cout << fixed << setprecision(2);
    //Display Outputs
    cout << north.name << endl;
    DivisonCalculations(north);
    cout << endl << west.name << endl;
    DivisonCalculations(west);
    cout << endl << east.name << endl;
    DivisonCalculations(east);
    cout << endl << south.name << endl;
    DivisonCalculations(south);
    //Exit stage right!
    return 0;
}

void DivisonCalculations(Divison & d){
    // string that holds the place in line
    string place[4] = {"first", "second", "third", "fourth"};
    
    //for loop used to input the sales for each quarter using a structure
    for (int i = 0; i < 4; i++){
        cout << "Enter " << place[i] <<"-quarter sales:" << endl;
        cin >> d.sales[i];
        d.total += d.sales[i]; // gives the total of all sales
        }
    d.avgSales = d.total/4; // gives Average of sales
    cout << "Total Annual sales:$" << d.total<<endl;
    cout << "Average Quarterly Sales:$" << d.avgSales;
}
