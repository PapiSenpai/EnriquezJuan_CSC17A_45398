#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct mData{
    string mName;
    float totalRain;
    float hTemp;
    float lTemp;
    float avgTemp;
};

int main(){
	//your code here
	mData data[12];
	
	float total=0;
	float AverageHigh=0;
	float AverageLow=0;
	float average=0;
	for (int i=0; i<12; i++){
	    cin >> data[i].mName >> data[i].totalRain >> data[i].lTemp >> data[i].hTemp;
	    total += data[i].totalRain;
	    AverageHigh += data[i].hTemp;
	    AverageLow += data[i].lTemp;
	}
    total = total/12; // gives total average Rainfall
    average = (AverageLow+AverageHigh)/24;

    cout<< fixed << setprecision(1);
	cout<<"Average Rainfall "<< total << " inches/month" <<endl;
	// for loop that gives highest temp
	float highest=data[0].hTemp;
	float lowest=data[0].lTemp;
	string highestMonth = data[0].mName;
	string lowestMonth = data[0].mName;
	
	for(int i=0; i<12; i++){
	    if(highest < data[i].hTemp){
	        highest=data[i].hTemp;
	        highestMonth = data[i].mName;
	    }
	    if(lowest > data[i].lTemp){
	        lowest=data[i].lTemp;
	        lowestMonth=data[i].mName;
	    }
	   
	}
	cout << setprecision(0);
	cout << "Lowest  Temperature "<< lowestMonth << "  " << lowest << " Degrees Fahrenheit" << endl;
    cout << "Highest Temperature " << highestMonth << "  " << highest << " Degrees Fahrenheit"<< endl;
	cout << "Average Temperature for the year " << average << " Degrees Fahrenheit"<< endl;
	
	return 0;
}