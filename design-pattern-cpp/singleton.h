#include <iostream>
using namespace std;

class Singleton {
    int data;
    static Singleton *instance;

    Singleton() {
        int data = 10;
        cout << "Initiate constructor" << endl;
    }

    ~Singleton(){ cout << "Initiate destructor" << endl; }
};