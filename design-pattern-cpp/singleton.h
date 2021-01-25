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

    public:
        static Singleton *getInstance(){
            if(!instance){
                instance = new Singleton;
            }
            return instance;
        }

        void setData(int data){
            this->data = data;
        }
        
        int getData(){
            return data;
        }
};