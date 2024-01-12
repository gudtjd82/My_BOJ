#include <iostream>
#include <string>

using namespace std;

int main(){
    int a = 3;
    int c = 4;
    int d = 8;
    int e = 0;
    double b = 2.0;

    cout << a / b << endl;
    cout << (a / (d-c) > e) << endl;
    cout << (a / double(d-c) > e) << endl;
    cout << (a / double(d-c) > double(e)) << endl;
    return 0;
}