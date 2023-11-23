#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b;
    int b_1, b_10, b_100;
    int num3, num4, num5, num6;
    cin >> a >> b;
    b_1 = b%10;
    b_10 = (b%100)/10;
    b_100 = b/100;
    
    num3 = a * b_1;
    num4 = a * b_10;
    num5 = a * b_100;
    num6 = num3 + num4*10 + num5*100;

    cout << num3 << endl;
    cout << num4 << endl;
    cout << num5 << endl;
    cout << num6 << endl;
}