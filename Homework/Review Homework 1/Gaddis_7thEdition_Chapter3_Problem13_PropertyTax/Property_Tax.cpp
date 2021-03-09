
/* 
 * File:   Property_Tax.cpp
 * Author: Juan Enriquez
 *
 * Created on March 5, 2021, 8:51 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;


int main() {

    // Varibles
    double property;    // this is the value of property
    double taxA = .6;   // this is the assessment value tax
    double taxP = .64;  // this is the tax for property if assessment value
                        // is above $6000
    
    // Input
    cout << "What is the price of the house?" << endl;
    cin >> property;
    
    // Calculations
    double assessment_Value = property * taxA; 
    double property_tax = (assessment_Value * taxP) / 100;
         
   
    // Set precision to 2 so it is only two decimals back
    cout << setprecision(2) << fixed;
    
    //Output
    cout << "Assessment Value of Property: $ " <<  assessment_Value << endl;
    cout << "Property Tax: $ " << property_tax << endl;
    
    return 0;
}

