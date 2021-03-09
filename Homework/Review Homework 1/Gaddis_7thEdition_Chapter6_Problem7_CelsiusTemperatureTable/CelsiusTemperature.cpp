/* 
 * File:   CelsiusTemperature.cpp
 * Author: Juan Enriquez
 * Project: Celsius Temperature Table
 *
 * Created on March 7, 2021, 5:33 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

/**************************************
 * The purpose of this project is to
 * make a calculator that converts
 * temperature in Fahrenheit to Celsius
 * in a separate function.
 **************************************/

double Celsius(double); // Prototype for the function Celsius

int main() 
{
    // Datatypes and Values
    const int min_temp = 0, // Minimum temperature
              max_temp = 20; // Maximum temperature
    double C;
    
    // OUTPUT
    cout << setprecision(2) << fixed;
    cout << "Fahrenheit      |Celsius \n";
    cout << "--------------------------\n";
    // For loop that lists conversions
    for (int F = min_temp; F <= max_temp; F++)
    {
        C = Celsius(F);
        cout << "F : " << F << "        |C : " << C << endl;

    }
     
    return 0;
}

/************************************
 * Function that carries the equation
 * for Celsius
 ************************************/
double Celsius(double num)
{
    double c_temp;
    c_temp = (5.0 / 9.0) * (num - 32.0);
    
    return c_temp;
}