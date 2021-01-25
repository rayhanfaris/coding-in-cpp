#include <iostream>
#include "singleton.h"

using namespace std;

Singleton *Singleton::instance = nullptr; //or nullptr

int main(){
    Singleton* s = s->getInstance();
    cout << s->getData() << endl;
    s->setData(50);
    cout << s->getData() << endl;
    return 0;
}