/*
 * Name: Rayhan Faris Jufahri
 * NIM: 19/444315/PA/19377
 * Linear interpolation using linear and non-linear
 * function from regressions
 */


#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>

using namespace std;

// Below are the equations with its constance
// this is hardcoded from the calculation
// done on linear and non linear regression
// changes to these functions are required to
// when changing the x and y data

// Linear regression
float f1(float x){
	return -0.7625 * x + 39.3708;
}

float f2(float x){
	return -0.35625 * x + 26.1437;
}

// non linear regression
float f3(float x){
	return 44.8257 * pow(x, -0.241525);
}

float f4(float x){
	return 27.1735* pow(x, -0.198812);
}

void linearInterpolation(float data[], int mins[], int arraySize, int x, float x1, float x2, string name){
	float ypLinearReg1, ypNonLinearReg1;
	float ypLinearReg2, ypNonLinearReg2;
	float calcErrorF1, calcErrorF2, calcErrorF3, calcErrorF4;
	float error = 0;
	
	if(name == "Day One" && x > x1 && x2 > x1 && binary_search(mins, mins + arraySize, x1) && binary_search(mins, mins + arraySize, x2)){
		ypLinearReg1 = ((f1(x2)-f1(x1))/(x2-x1)*(x-x1))+f1(x1);
		ypNonLinearReg1 = ((f3(x2)-f3(x1))/(x2-x1)*(x-x1))+f3(x1);
		cout << "=== "<< name << " Linear Regression with linear interpolation ===\n" << "f(x) = -0.7625x + 39.3708\nfind f(" << x << ") where x1 = " << x1 << " and x2 = " << x2 << " using linear interpolation is " << ypLinearReg1 << " with error: " << (fabs(data[x]-f1(x))/data[x])*100 << "%" << endl;
		
		// Average error finding
		for(int i=0; i<arraySize; i++){
			if(mins[i] % 2 == 0){
				error += (fabs(data[i]-f1(i))/data[i])*100;
			}
		}
		
		error /= (arraySize/2);
		cout << "Average error: " << error << endl;
		
		cout << "=== "<< name << " Non Linear Regression with linear interpolation ===\n" << "f(x) = 44.8257x^-0.241525\nfind f(" << x << ") where x1 = " << x1 << " and x2 = " << x2 << " using linear interpolation is " << ypNonLinearReg1 << " with error: " << (fabs(data[x]-f3(x))/data[x])*100 << "%" << endl;
		
		// Average error finding
		for(int i=0; i<arraySize; i++){
			if(mins[i] % 2 == 0){
				error += (fabs(data[i]-f3(i))/data[i])*100;
			}
		}
		
		error /= (arraySize/2);
		cout << "Average error: " << error << endl;
	} else if(name == "Day Two" && x > x1 && x2 > x1 && binary_search(mins, mins + arraySize, x1) && binary_search(mins, mins + arraySize, x2)){
		ypLinearReg2 = ((f2(x2)-f2(x1))/(x2-x1)*(x-x1))+f2(x1);
		ypNonLinearReg2 = ((f4(x2)-f4(x1))/(x2-x1)*(x-x1))+f4(x1);	
		cout << "\n=== " << name << " Linear Regression with linear interpolation ===\n" << "f(x) = -0.35625x + 26.1437\nfind f(" << x << ") where x1 = " << x1 << " and x2 = " << x2 << " using linear interpolation is " << ypLinearReg2 << " with error: " << (fabs(data[x]-f2(x))/data[x])*100 << "%" << endl;
		
		// Average error finding
		for(int i=0; i<arraySize; i++){
			if(mins[i] % 2 == 0){
				error += (fabs(data[i]-f2(i))/data[i])*100;
			}
		}
		
		error /= (arraySize/2);
		cout << "Average error: " << error << endl;
		
		cout << "=== " << name << " Non Linear Regression with linear interpolation ===\n" << "f(x) = 27.1735x^-0.198812\nfind f(" << x << ") where x1 = " << x1 << " and x2 = " << x2 << " using linear interpolation is " << ypNonLinearReg2 << " with error: " << (fabs(data[x]-f4(x))/data[x])*100 << "%" << endl;
		
		// Average error finding		
		for(int i=0; i<arraySize; i++){
			if(mins[i] % 2 == 0){
				error += (fabs(data[i]-f4(i))/data[i])*100;
			}
		}
		
		error /= (arraySize/2);
		cout << "Average error: " << error << endl;
	} else {
		cout << "\nMake sure the x value in f(x) is within the interval of x1 and x2" << endl;
		return;
	}
	cout << endl;
}

int main(){
	int arraySize, arraySize2;
	float x1, x2;
	int x;
	
	float dayOne[] = {34,37,28,16,44,36,37,43,50,22,13,28,41,10,14,27,41,27,23,37,12,19,18,30,33,31,13,24,18,36}; // y
	float dayTwo[] = {12,21,40,36,34,33,17,29.5,28,13,11.5,12,23,27,17,22.5,30.5,26,22,19,13,3,2,49,10,28,43,20,9,30}; // y
	int mins[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30}; // x
	
	cout << "Enter X, X1 and X2:\n";
	cin >> x >> x1 >> x2;
	
	arraySize = sizeof(dayOne) / sizeof(dayOne[0]);
	
	linearInterpolation(dayOne, mins, arraySize, x, x1, x2, "Day One");
	linearInterpolation(dayTwo, mins, arraySize, x, x1, x2, "Day Two");
}

