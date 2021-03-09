
/* 
 * File:   MonthlySalesTax.cpp
 * Author: Juan Enriquez
 *
 * Created on February 21, 2021, 6:03 PM
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/******************************
 * Description:
 ******************************/
int main() {

    // Variables 
    string month;
    int year;
    int day;
    double total; // total amount that was earned
    double state_Tax = .04;
    double county_Tax = .02;
    double tax_Total = 1.06; // Var for both county and state tax
    
    // Ask input from user
    cout << "What month is it?" << endl;
    cin >> month;
    cout << "What year is it?" << endl;
    cin >> year;
    cout << "What was the total collected?" << endl;
    cin >> total;
    
    // calculations
    double sales = total / tax_Total; // gets calculation for sales 
    double TaxC = sales * county_Tax; // the amount taxed by the county
    double TaxS = sales * state_Tax;  // the amount taxed by the state
    double TotalTax = TaxC + TaxS;
    
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

