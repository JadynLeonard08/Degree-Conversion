/*
Author: Jadyn Leonard
Assignment Title: In Class Problem 5
Assignment Description: a C++ program that can 
read all of the temperature records, convert each 
Celsius reading to Fahrenheit, and report the average 
temperature in both Celsius and Fahrenheit.
Due Date: 11/08/2026
Date Created: 11/08/2026
Date Last Modified: 11/08/2026
*/

#include "tempFunctions.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main() {
    
//Data Abstraction
    ifstream inFile;
    string fileName;
    
    const int MAX_NUMBER = 30;
    int count = 0;
    
    string dayNames[MAX_NUMBER];
    double cTemp[MAX_NUMBER];
    double fTemp[MAX_NUMBER];
    
    double fAvg;
    double cAvg;
    
    
//Input
    do {
        cout << "Enter the name of the temperature file: ";
        cin >> fileName;
        
        inFile.open(fileName);
        
        if (!inFile.is_open()){
            cout << "Error: File Did Not Open!" << endl;
        }
    } while (!inFile);
    
//Process
    //Names and Days are read into their respective files
    while (count < MAX_NUMBER && inFile >> dayNames[count] >> cTemp[count]){
        ++count;
    }
    inFile.close();
    
    //fTemp stores the converted temperatures
    for (int i = 0; i < count; ++i){
        fTemp[i] = celsiusToFahrenheit(cTemp[i]);
    }
    //average of cTemp and fTemp
    if (count > 0){
        fAvg = avgTemp(fTemp, count);
        cAvg = avgTemp(cTemp, count);
    }
     
//Output
    cout << left;
    cout << fixed << setprecision(2);
    for (int i = 0; i < count; ++i){
        cout << setw(15) << dayNames[i] << 
        setw(10) << cTemp[i] << " C is " <<
        setw(10) << fTemp[i] << " F" << endl;
    }
    cout << endl;
    cout << "Average Temperature in Celcius: " << cAvg << endl;
    cout << "Average Temperature in Fahrenheit: " << fAvg << endl;
    
  return 0;
}
