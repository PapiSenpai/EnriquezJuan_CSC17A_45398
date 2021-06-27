
/* 
 * File:   MonthlySalesTax.cpp
 * Author: Juan Enriquez
 *
 * Created on June 24, 2021, 4:03 PM
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/***********************************************
 * Description: This program asks for the 
 * month, and the amount of sales tax collected.
 * It then calculates the tax.
 ***********************************************/
int main() {

    // Variables 
    string month;
    int year;
    int day;
    float total; // total amount that was earned
    float state_Tax = .04;
    float county_Tax = .02;
    float tax_Total = 1.06; // Var for both county and state tax
    
    // Ask input from user
    cout << "What month is it?" << endl;
    cin >> month;
    cout << "What year is it?" << endl;
    cin >> year;
    cout << "What was the total collected?" << endl;
    cin >> total;
    
    // calculations
    float sales = total / tax_Total; // gets calculation for sales 
    float TaxC = sales * county_Tax; // the amount taxed by the county
    float TaxS = sales * state_Tax;  // the amount taxed by the state
    float TotalTax = TaxC + TaxS;
    
    cout << setprecision(2) << fixed;
    
    //output
    cout << "Month: " << month << "\n";
    cout << "Year:   " << year << endl;
    cout << "----------------" << endl;
    cout << "Total Collected:" << setw(5) << "$ " << total << endl;
    cout << "Sales:" << setw(15) << "$ " << sales << endl;
    cout << "County Sales Tax:" << setw(4) << "$ " << TaxC << endl;
    cout << "State Sales Tax:" << setw(5) << "$ " << TaxS << endl;
    cout << "Total Sales Tax:" << setw(5) << "$ " << TotalTax << endl;
           
    return 0;
}

