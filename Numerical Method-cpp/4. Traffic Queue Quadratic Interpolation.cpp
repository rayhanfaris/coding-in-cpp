/*
 * Name: Rayhan Faris Jufahri
 * NIM: 19/444315/PA/19377
 * Quadratic interpolation from linear and non-linear
 * function regressions
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

// Constants are set to global variable
float b0, b1, b2;

// this is hardcoded from the calculation
// done on linear and non linear regression
// changes to these functions are required to
// when changing the x and y data


// Linear regression equation
float f1(float x){ // Day One
	return -0.7625 * x + 39.3708;
}

float f2(float x){ // Day Two
	return -0.35625 * x + 26.1437;
}

// non linear regression
float f3(float x){ // Day One
	return 44.8257 * pow(x, -0.241525);
}

float f4(float x){ // Day Two
	return 27.1735* pow(x, -0.198812);
}

// quadratic interpolation function for 2nd order
float fQ(float x, float x1, float x2, float x3){
	return b0+(b1*(x-x1))+(b2*(x-x1)*(x-x2));
}

// y = b= + b1(x-x0) + b2(x-x1)(x-x0)
void quadraticInterpolation(float data[], int mins[], int arraySize, int x, float x1, float x2, float x3, string name){
	// Day One linear and nonlinear interpolation
	float error = 0;
	if(name == "Day One" && x > x1 && x2 > x1 && x3 > x2 && binary_search(mins, mins + arraySize, x1) && binary_search(mins, mins + arraySize, x2) && binary_search(mins, mins + arraySize, x3)){
		b0 = f1(x1);
		b1 = (f1(x2)-f1(x1))/(x2-x1);
		b2 = (((f1(x3)-f1(x2))/(x3-x2))-((f1(x2)-f1(x1))/(x2-x1)))/(x3-x1);
		if(b2 < 1.e-7){
			b2 = 0;
		}
		cout << "=== Day One Quadratic interpolation ===\nf(x): " << b0 << "+" << b1 << "(x-" << x1 << ")+" << b2 << "(x-" << x1 << ")(x-" << x2 << ") using linear regression equation" << endl;
		cout << "f(" << x << ") = " << fQ(x, x1, x2, x3) << endl;
		cout << "Error: " << (fabs(fQ(x, x1, x2, x3)-data[x-1])/data[x-1])*100 << "%" << endl;
		
		// Average error finding
		for(int i=0; i<arraySize; i++){
			if(mins[i] % 2 == 0){
				error += (fabs(fQ(x, x1, x2, x3)-data[i])/data[i])*100;
			}
		}
		
		error /= (arraySize/2);
		cout << "Average error: " << error << endl;
		
		// Quadratic Interpolation from non linear regression
		b0 = f3(x1);
		b1 = (f3(x2)-f3(x1))/(x2-x1);
		b2 = (((f3(x3)-f3(x2))/(x3-x2))-((f3(x2)-f3(x1))/(x2-x1)))/(x3-x1);
		if(b2 < 1.e-7){
			b2 = 0;
		}
		cout << "f(x): " << b0 << "+" << b1 << "(x-" << x1 << ")+" << b2 << "(x-" << x1 << ")(x-" << x2 << ") using non linear regression equation" << endl;
		cout << "f(" << x << ") = " << fQ(x, x1, x2, x3) << endl;
		cout << "Error: " << (fabs(fQ(x, x1, x2, x3)-data[x-1])/data[x-1])*100 << "%" << endl;
		
		// Average error finding
		for(int i=0; i<arraySize; i++){
			if(mins[i] % 2 == 0){
				error += (fabs(fQ(x, x1, x2, x3)-data[i])/data[i])*100;
			}
		}
		
		error /= (arraySize/2);
		cout << "Average error: " << error << endl;
	} else if(name == "Day Two" && x > x1 && x2 > x1 && x3 > x2 && binary_search(mins, mins + arraySize, x1) && binary_search(mins, mins + arraySize, x2) && binary_search(mins, mins + arraySize, x3)){
		// Day two linear and nonlinear interpolation
		b0 = f2(x1);
		b1 = (f2(x2)-f2(x1))/(x2-x1);
		b2 = (((f2(x3)-f2(x2))/(x3-x2))-((f2(x2)-f2(x1))/(x2-x1)))/(x3-x1);
		if(b2 < 1.e-7){
			b2 = 0;
		}
		cout << "=== Day Two Quadratic interpolation ===\nf(x): " << b0 << "+" << b1 << "(x-" << x1 << ")+" << b2 << "(x-" << x1 << ")(x-" << x2 << ") using linear regression equation" << endl;
		cout << "f(" << x << ") = " << fQ(x, x1, x2, x3) << endl;
		cout << "Error: " << (fabs(fQ(x, x1, x2, x3)-data[x-1])/data[x-1])*100 << "%" << endl;
		
		// Average Error finding
		for(int i=0; i<arraySize; i++){
			if(mins[i] % 2 == 0){
				error += (fabs(fQ(x, x1, x2, x3)-data[i])/data[i])*100;
			}
		}
		
		error /= (arraySize/2);
		cout << "Average error: " << error << endl;
		
		// Quadratic Interpolation from non linear regression
		b0 = f4(x1);
		b1 = (f4(x2)-f4(x1))/(x2-x1);
		b2 = (((f4(x3)-f4(x2))/(x3-x2))-((f4(x2)-f4(x1))/(x2-x1)))/(x3-x1);
		if(b2 < 1.e-7){
			b2 = 0;
		}
		cout << "f(x): " << b0 << "+" << b1 << "(x-" << x1 << ")+" << b2 << "(x-" << x1 << ")(x-" << x2 << ") using non linear regression equation" << endl;
		cout << "f(" << x << ") = " << fQ(x, x1, x2, x3) << endl;
		cout << "Error: " << (fabs(fQ(x, x1, x2, x3)-data[x-1])/data[x-1])*100 << "%" << endl;
		
		// Average error finding
		for(int i=0; i<arraySize; i++){
			if(mins[i] % 2 == 0){
				error += (fabs(fQ(x, x1, x2, x3)-data[i])/data[i])*100;
			}
		}
		
		error /= (arraySize/2);
		cout << "Average error: " << error << endl;
	} else {
		cout << "\nMake sure the x value in f(x) is within the interval of x1, x2 & x3" << endl;
		return;
	}
	cout << endl;
}

int main(){
	int arraySize;
	float x1, x2, x3;
	int x;
	
	float dayOne[] = {34,37,28,16,44,36,37,43,50,22,13,28,41,10,14,27,41,27,23,37,12,19,18,30,33,31,13,24,18,36}; // y
	float dayTwo[] = {12,21,40,36,34,33,17,29.5,28,13,11.5,12,23,27,17,22.5,30.5,26,22,19,13,3,2,49,10,28,43,20,9,30}; // y
	int mins[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30}; // x
	
	cout << "Enter X, X1, X2 and X3:\n";
	cin >> x >> x1 >> x2 >> x3;
	
	arraySize = sizeof(dayOne) / sizeof(dayOne[0]);
	
	quadraticInterpolation(dayOne, mins, arraySize, x, x1, x2, x3, "Day One");
	quadraticInterpolation(dayTwo, mins, arraySize, x, x1, x2, x3, "Day Two");
}

