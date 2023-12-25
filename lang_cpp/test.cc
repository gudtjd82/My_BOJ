#include <iostream>
#include <string>

using namespace std;

int main(){
    int* p;
    int a = 2;

    p = &a;

    int b = *p;

    b = 4;

    cout << a << endl;
    
    return 0;
}