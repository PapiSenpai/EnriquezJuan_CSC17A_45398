
/* 
 * File:   Property_Tax.cpp
 * Author: Juan Enriquez
 *
 * Created on March 5, 2021, 8:51 PM
 */

/**************************************************
 * Description: This purpose for this program is to
 * calculate the amount of tax the county takes for
 * property.
 **************************************************/

#include <iostream>
#include <iomanip>

using namespace std;


int main() {

    // Varibles
    float property;    // this is the value of property
    float taxA  {.6};   // this is the assessment value tax
    float taxP {.64};  // this is the tax for property if assessment value
                        // is above $6000
    
    // Input
    cout << "What is the price of the house?" << endl;
    cin >> property;
    
    // Calculations
    float assessment_Value = property * taxA; 
    float property_tax = (assessment_Value * taxP) / 100;
         
   
    // Set precision to 2 so it is only two decimals back
    cout << setprecision(2) << fixed;
    
    //Output
    cout << "Assessment Value of Property: $ " <<  assessment_Value << endl;
    cout << "Property Tax: $ " << property_tax << endl;
    
    return 0;
}

