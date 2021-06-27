/* 
 * Author: Juan Enriquez
 * 7th Edition
 * Chapter :5
 * Problem: 5.11 Population
 * Created on June 26, 2021, 1:00 PM
 */

/*************************************
 * Description: 
 * The purpose of this program is to
 * predict the rapid incline of our
 * population.
 *************************************/

#include <iostream>
using namespace std;

int main() {

    // Data types and Value
    int organism;
    float daily_increase;
    int days;
    
    // Input
    cout << "What will be the number if starting organisms?" << endl;
    cin >> organism;
    while (organism < 2) // While statements used to catch invalid errors
    {
        cout << "Enter Value greater than 2." << endl;
        cin >> organism;
    }
    
    cout << "How much will the population increase?" << endl;
    cin >> daily_increase;
    while (daily_increase <= 1)
    {
        cout << "Enter Value greater than 0." << endl;
        cin >> daily_increase;
    }
    
    cout << "How many days will the simulation last?" << endl;
    cin >> days;
    while (days <= 1)
    {
        cout << "Enter Value greater than 1." << endl;
        cin >> days;
    }
    
    // Output
    cout << "Original Population : " << organism << endl;
    cout << "Expected growth : " << daily_increase << "%" << endl << endl;

    // If statement to catch any invalid answers
    if (organism > 2 && daily_increase > 0 && days > 1)
    {
        float percentage = daily_increase / 100; // what the equation will use
                                                 // as the percent increase
        
        //for loop to log the days
        for (int counter = 1; counter <= days ; counter++ )
        {                           
            organism += (organism * percentage); // outputs the new population
            
            cout << "Day :" << counter << endl;
            cout << "New Population: " << organism << endl;
            
        }
    }

    return 0;
}
