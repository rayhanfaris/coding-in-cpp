#include <iostream>
using namespace std;

int main(){
	// * start ascii = 42
	// ? end ascii = 63
	// # pemisah ascii = 35
	string a;
	cin >> a;
	string arr[20];
	int size = sizeof(arr) / sizeof(arr[0]);
	int i=0, j=0, k=0;
	
	while(a.at(i)!=42){
		i++;
	}
	if(a.at(i)==42){
		k=i+1;
		while(true){
			arr[j].push_back(a.at(k));
			k++;
			if(a.at(k)==35){
				j++;
				k++;
			}
			if(a.at(k)==63){
				break;
			}
		}
	}
	for(int j=0; i<size; j++){
		if(arr[j]==""){
			break;
		}
		cout << "data[" << j << "]" << " = " << arr[j] + " " << endl;
	}
	return 0;
}

