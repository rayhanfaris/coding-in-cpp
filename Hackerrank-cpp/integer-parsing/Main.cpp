#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> integerParse(string a){
    stringstream ss(a);
    int temp;
    char ch;
    vector<int> vect;
    while(ss >> temp){
        vect.push_back(temp);
        ss >> ch;
    }
    return vect;
}

int main(){
    string a;
    cin >> a;
    vector<int> integer = integerParse(a);
    
    // for(auto i=integer.begin(); i!=integer.end(); ++i){
    //     cout << *i << "\n";
    // }
    for (int i = 0; i != integer.size(); i++){
        cout << integer[i] << "\n";
    }

    cout << endl;
    return 0;
}