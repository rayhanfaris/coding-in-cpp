#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string toString(vector<int> vect){
    stringstream ss;
    char space = ' ';
    ss << "My numbers are ";
    for (int i = 0; i != vect.size(); i++){
        ss << vect[i] << space;
    }
    ss << '!';

    // ALT

    // for(auto i=integer.begin(); i!=integer.end(); ++i){
    //    cout << *i << "\n";
    // } 

    return ss.str();
}

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
    string a = "10,43,-12,50,60";
    vector<int> integers = integerParse(a);

    cout << toString(integers) << endl;

    return 0;
}