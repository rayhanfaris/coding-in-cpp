/*
 * Name: Rayhan Faris Jufahri
 * NIM: 19/444315/PA/19377
 * Non-linear regression
 */

#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

float f(int x, float a, float b){
	return a*pow(x, b);
}

// y = ax^b
void NonLinearRegression(float data[], int mins[], int arraySize, string name){
	float sumX = 0;
	float sumY = 0;
	float sumQ = 0;
	float sumP = 0;
	float sumPQ = 0;
	float sumQSquared = 0;
	float sumPSquared = 0;
	float tempP = 0;
	float tempQ = 0;
	
	float a = 0;
	float b = 0;
	float c = 0;
	
	for(int i=0; i<arraySize; i++){
		if(mins[i] % 2 == 1){ // regression data
			sumX += mins[i];
			sumY += data[i];
			tempP = log10(data[i]);
			tempQ = log10(mins[i]);
			sumP += tempP;
			sumQ += tempQ;
			sumPQ += tempP * tempQ;
			sumQSquared += tempQ * tempQ;
			sumPSquared += tempP * tempP;
		}
	}
	
	b = (((arraySize/2)*sumPQ)-(sumP*sumQ))/(((arraySize/2)*sumQSquared)-(sumQ*sumQ));
	c = (sumP/(arraySize/2))-(b*(sumQ/(arraySize/2)));
	a = pow(10, c);
	cout << name << "\ty = " << setw(5) << a << "x^" << setw(5) << b << endl;

	float error = 0;
	float calcError;
	for(int i=0; i<arraySize; i++){
		if(mins[i] % 2 == 0){ // testing data
			calcError = fabs((data[i]-f(mins[i], a, b))/data[i])*100;
			error += calcError;
			cout << "f(" << mins[i] << ") = "<< f(mins[i], a, b) << "\terror: " << calcError << "%" << endl;
		}
	}
	cout << "Average error: " << error/(arraySize/2) << endl;
	
	cout << endl;
}

int main(){
	int arraySize;
	
	float dayOne[] = {34,37,28,16,44,36,37,43,50,22,13,28,41,10,14,27,41,27,23,37,12,19,18,30,33,31,13,24,18,36}; // y
	float dayTwo[] = {12,21,40,36,34,33,17,29.5,28,13,11.5,12,23,27,17,22.5,30.5,26,22,19,13,3,2,49,10,28,43,20,9,30}; // y
	int mins[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30}; // x
	
	arraySize = sizeof(dayOne) / sizeof(dayOne[0]);
	
	NonLinearRegression(dayOne, mins, arraySize, "Day One");
	NonLinearRegression(dayTwo, mins, arraySize, "Day Two");
	
}

