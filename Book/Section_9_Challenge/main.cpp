/*
* Author: Juan Enriquez
* 
* 
* 
*/

/*********************************************
 * Purpose: The purpose of this project is to
 * create a menu that will have options to do
 * a variety of tasks.
 * *******************************************/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> vec {2, 4, 8, 1, 7};
    
    // varibles
    char letter;
    int add_num {0};
    int i {0}; //counter
    int mean {0};
    int max {0};
    int min {0};
    int size = vec.size(); // did this to prevent warning

    
    // create a menu
    
    do{
        cout << "Hi, please select an option." << endl;
        cout << "P - Print numbers\n";
        cout << "A - Add a number\n";
        cout << "M - Display mean of the numbers\n";
        cout << "S - Display the smallest number\n";
        cout << "L - Display the largest number\n";
        cout << "Q - Quit\n";
        cin >> letter;
   
        // switch statement that leads to different options
        switch (letter){
            case 'P':
            case 'p': { 
                for ( auto v : vec){ // for loop that diplay contents of a vector
                    cout << v << " ";
                }
                cout << endl;
            }
                break;
            case 'A':
            case 'a': {
                cout << "Enter number that you want to add to Vector\n";
                cin >> add_num;
                vec.push_back(add_num); // dynamically adds number to the back of the vector
            }
                break;
            case 'M':
            case 'm': {
                for (i = 0; i < size; ++i){
                    mean += vec.at(i);
                }
                cout << "The mean of the numbers is " << mean << endl;
            }
                break;        
            case 'S':
            case 's': {
                min = vec.at(0); // set a var for min first before comparing
                for (i=0; i < size; ++i){
                    if (vec.at(i) < min)
                        min = vec.at(i);
                }
                cout << "The min of the array is " << min << endl;
            }
                break;        
            case 'L':
            case 'l': {
                max = vec.at(0); // set a var for max first before comparing
                for (i=0; i < size; ++i){
                    if (vec.at(i) > max)
                        max = vec.at(i);
                }
                cout << "The max of the array is " << max << endl;                
            }
                break;
            case 'Q':
            case 'q': cout << "Goodbye\n";
                break;
            default: cout << "Thats the wrong key! Try again.\n";
        }
    } while ((letter != 'Q' && letter != 'q')); // we use && since it will result to false
                                                // if 'q' or 'Q' was choosen 
	return 0;
}
