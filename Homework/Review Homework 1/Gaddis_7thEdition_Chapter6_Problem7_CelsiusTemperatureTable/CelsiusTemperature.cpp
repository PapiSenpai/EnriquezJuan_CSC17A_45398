/* 
 * File:   CelsiusTemperature.cpp
 * Author: Juan Enriquez
 * Project: Celsius Temperature Table
 *
 * Created on June 26, 2021, 10:33 AM
 */

/**************************************
 * Description:
 *  The purpose of this project is to
 * make a calculator that converts
 * temperature in Fahrenheit to Celsius
 * in a separate function.
 **************************************/

#include <iostream>
#include <iomanip>
using namespace std;

float Celsius(float); // Prototype for the function Celsius

int main() 
{
    // Datatypes and Values
    const int min_temp = 0, // Minimum temperature
              max_temp = 20; // Maximum temperature
    float C;
    
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
float Celsius(float num)
{
    float c_temp;
    c_temp = (5.0 / 9.0) * (num - 32.0);
    
    return c_temp;
}