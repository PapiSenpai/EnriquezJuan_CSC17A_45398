/* 
 * Project: Binary String Search
 * Author: Juan Enriquez 
 * Created on March 6, 2022, 12:29 PM
 */

 #include <iostream>
 #include <string>
 #include <iomanip>
 using namespace std;
 
 void selectionSort (string names[], const int size);
 int binarySearch (string names[], const int size, string employeeName);
 
 int main ()
 {
     //
     // Array Variables
     const int size = 20;
     string names [size] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                            "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                            "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
                            "Loony, Joe", "Wolfe, Bill", "James, Jean",
                            "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
                            "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
                            "Pike, Gordon", "Holland, Beth"};
    //
    // Variables
    string employeeName;
    int results;
 
    cout << "Enter the name of the Employee you want to search.\n";
    getline(cin, employeeName);
 
    selectionSort (names, size); // call function
    results = binarySearch (names, size, employeeName);
    
    if  (results == -1)
    {
        cout << employeeName << "name is doesn't exist in the array." << endl;
    }
    else
    cout << "Element name " << employeeName << " found at the " <<
            results + 1 << " in the array." << endl;
    cout << "Element name list is:\n";
 
    for (int index = 0; index < size; index++)
    {
        cout << index + 1 << right << setw(15) << names[index] << endl;
    }
     return 0;
 }
 
 /*************************************
  * Definition of selectionSort
  * The purpose of the function is to
  * sort the string characters.
  ************************************/
   void selectionSort (string names[], const int size)
   {
       int startScan, minIndex;
       string minValue;
 
       for (startScan = 0; startScan < (size -1); startScan++)
       {
           minIndex = startScan;
           minValue = names[startScan];
           for (int index = startScan + 1; index < size; index++)
           {
               if (names[index] < minValue)
               {
                   minValue = names[index];
                   minIndex = index;
               }
           }
           names[minIndex] = names[startScan];
           names[startScan] = minValue;
       }
   }
 
 /*************************************
  * Definition of binarySearch
  * The purpose of the function is to
  * search for an element.
  ************************************/
int binarySearch (string names[], const int size, string employeeName)
{
    int first = 0,
        last = size - 1,
        middle,
        position = -1;
    bool found = false;
 
        while (!found && first <= last)
        {
            middle = (first + last) / 2;
            if (names[middle].compare (employeeName) == 0)
            {
                found = true;
                position = middle;
            }
            else if (names[middle] > employeeName)
                last = middle - 1;
            else
                first = middle + 1;
        }
        return position;
}