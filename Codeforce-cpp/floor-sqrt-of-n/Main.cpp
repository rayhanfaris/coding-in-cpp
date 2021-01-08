#include <iostream>
using namespace std;

int main(){
    int a, result = 0;
    a = 961;
    if (a == 1){
        result = 1;
    }
    else if (a > 1){
        int j = 2;
        while (j * j <= a){
            j++;
        }
        result = --j;
    }

    cout << result;
    return 0;
}
