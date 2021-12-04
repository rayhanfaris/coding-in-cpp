/*
 * Name: Rayhan Faris Jufahri
 * NIM: 19/444315/PA/19377
 * Linear Regression for Day One and Day Two
 */

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int f(int x, float a, float b){
	return a*x + b;
}

// Linear function y=mx+b
void LinearRegression(float data[], int mins[], int arraySize, string name){
	float sumX = 0;
	float sumY = 0;
	float sumXY = 0;
	float sumXSquared = 0;
	
	float a = 0;
	float b = 0;
	
	for(int i=0; i<arraySize; i++){
		if(mins[i] % 2 == 1){	// regression data
			sumX += mins[i];
			sumY += data[i];
			sumXY += mins[i]*data[i];
			sumXSquared += mins[i]*mins[i];
		}
	}
	
	// find a and b constants
	a = (((arraySize/2)*sumXY)-(sumX*sumY))/(((arraySize/2)*sumXSquared)-(sumX*sumX));
	b = (sumY/(arraySize/2))-(a*(sumX/(arraySize/2)));
	
	// formatting output
	if(b < 0){
		cout << name << "\ty = " << setw(5) << a << "x " << setw(5) << b;
	} else {
		cout << name << "\ty = " << setw(5) << a << "x + " << setw(5) << b;	
	}
	
	// calculating error with Et and E
	float E = 0;
	for(int i=0; i<arraySize; i++){
		if(mins[i] % 2 == 0){ // testing data
			E += pow((data[i] - (sumY/(arraySize/2))),2);	
		}
	}
	
	// Correlation Coefficient calculation
	float Et = 0;
	for(int i=0; i<arraySize; i++){
		if(mins[i] % 2 == 0){ //testing data
			Et += pow(data[i] - f(data[i], a, b),2);	
		}
	}

	// substitute to the R^2 error formula
	float r = 1 - sqrt(E/Et);
	
	cout << " with r = " <<  r << " where ";
	
	// Correlation coefficient relationship with the data
	// source from https://keisan.casio.com/exec/system/14059931777261		
	if(r > 0.7 && r <=1) {
		cout << "the function has a strong correlation with the data";
	} else if(r > 0.4 && r <= 0.7){
		cout << "the function has a moderate correlation with the data";
	} else if(r > 0.2 && r <= 0.4){
		cout << "the function has a weak correlation with the data";
	} else {
		cout << "the function has no correlation with the data";
	}
	cout << "\n\n";
}

int main(){
	int arraySize;

	float dayOne[] = {34,37,28,16,44,36,37,43,50,22,13,28,41,10,14,27,41,27,23,37,12,19,18,30,33,31,13,24,18,36}; // y
	float dayTwo[] = {12,21,40,36,34,33,17,29.5,28,13,11.5,12,23,27,17,22.5,30.5,26,22,19,13,3,2,49,10,28,43,20,9,30}; // y
	int mins[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30}; // x

	
	arraySize = sizeof(dayOne) / sizeof(dayOne[0]);
	
	LinearRegression(dayOne, mins, arraySize, "Day One");
	LinearRegression(dayTwo, mins, arraySize, "Day Two");
	
	return 0;
}


