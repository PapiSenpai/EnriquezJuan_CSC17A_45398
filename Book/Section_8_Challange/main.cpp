#include <iostream>
using namespace std;
/*
int main()
{
    // Variables
    float cents {0.0};
    const float dollar_value {1.0};
    const float quarter_value {.25};
    const float dime_value  {.10};
    const float nickle_value {.05};
    const float pennie_value {.01};
    
    float balance {0};
    
    // Ask user to type in cent amount
    cout << "Type in the amount of cents \n";
    cin >> cents;
    
    // Calculations
    int dollar = cents / dollar_value;
    balance = cents - (dollar * dollar_value);
    
    int quarter = balance / quarter_value;
    balance -= (quarter * quarter_value);

    int dime = balance / dime_value;
    balance -= (dime * dime_value);

    int nickle = balance / nickle_value;
    balance -= (nickle * nickle_value);

    int pennie = balance / pennie_value;

    
    // OUTPUT
    cout << "You can provide change as follows" << endl;
    cout << "Dollars : " << dollar << endl << "Quarters : " << quarter << endl;
    cout << "Dimes : "<< dime << endl << "Nickle : " << nickle << endl;
    cout << "Pennies : " << pennie << endl;
    
	return 0;
}
*/
/* Psudocode:
 * Ask user for cent amount
 * compare cents to other currency amount
 * DIV entered amount into dollars
 * get result of dollars and plug it into quarters
 * get result of quarters and plug it into dimes
 * get result of dimes and plug it into nickle
 * etc...
 * 
 * Output result
 * */


int main()
{
    // Variables
    int cents {0};
    const int dollar_value {100};
    const int quarter_value {25};
    const int dime_value  {10};
    const int nickle_value {5};
    const int pennie_value {1};
    
    int balance {0};
    
    // Ask user to type in cent amount
    cout << "Type in the amount of cents \n";
    cin >> cents;
    
    // Using the Modulo Operator *We cant use Modulo Operator with floats
    int dollar = cents / dollar_value;
    balance = cents % dollar_value;
    
    int quarter = balance / quarter_value;
    balance %= quarter_value;
    
    int dime = balance / dime_value;
    balance %= dime_value;

    int nickle = balance / nickle_value;
    balance %= nickle_value;

    int pennie = balance / pennie_value;
     
       
    // OUTPUT
    cout << "You can provide change as follows" << endl;
    cout << "Dollars : " << dollar << endl << "Quarters : " << quarter << endl;
    cout << "Dimes : "<< dime << endl << "Nickle : " << nickle << endl;
    cout << "Pennies : " << pennie << endl; 
 
    return 0;
}
