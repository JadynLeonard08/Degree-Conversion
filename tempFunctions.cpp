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
#include <cmath>
using namespace std;

double celsiusToFahrenheit(double c){
    double F;
    F = (c * (9.0 / 5.0)) + 32.0;
    
    return F;
}
double avgTemp(double tempArray[], double itemNum){
    double avg;
    double degTotal = 0.0;
    for (int i = 0; i < itemNum; ++i){
        degTotal += tempArray[i];
    }
    avg = degTotal/itemNum;
    
    return avg;
}