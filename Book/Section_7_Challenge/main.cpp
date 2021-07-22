#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    vector <int> vector1 {};
    vector <int> vector2 {};
    
    // Demonstrating how to use .push_back() on vector1
    vector1.push_back(10);
    vector1.push_back(20);
    
    cout << "The size of the array is " << vector1.size() << " And the contents are";
    cout << endl << vector1.at(0) << endl << vector1.at(1) << endl;
        
    // Demonstrating how to use .push_back() on vector2

    vector2.push_back(100);
    vector2.push_back(200);
    
    cout << "The size of the array is " << vector2.size() << " And the contents are";
    cout << endl << vector2.at(0) << endl << vector2.at(1) << endl;
        
    // Creating a 2D vector array with the already establised vectors
    vector <vector<int>> vector_2d {}; // (IMPORTANT) we intialize like this whenever there are more than one demensions
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "The size of the array is " << vector_2d.size() << " And the contents are";
    cout << endl << vector_2d.at(0).at(0) << endl << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << endl << vector_2d.at(1).at(1) << endl;
        
    // We change one component inside of vector1
    vector1.at(0) = 1000;
    
    cout << " the contents are " << endl << vector_2d.at(0).at(0) << endl << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << endl << vector_2d.at(1).at(1) << endl;
        
    cout << "The size of the array is " << vector1.size() << " And the contents are";
    cout << endl << vector1.at(0) << endl << vector1.at(1) << endl;
        

	return 0;
}

/* End Notes:
 * So at the end, there when we changed vector1 to 1000, it 
 * */
