#include <iostream>
using namespace std;

int main(){
	int n, num =1;
	cin >> n;
	
	for(int i=0; i<n; i++){
		for(int j=1; j<n-i; j++){
			cout << " ";
		}
		for(int k=0; k<=i; k++){
			if(i==0 || k==0){
				num = 1;
			} else{
				num = num*(i-k+1)/k;
			}
			cout << num << " ";
		}
		cout << endl;
	}
	return 0;
}
