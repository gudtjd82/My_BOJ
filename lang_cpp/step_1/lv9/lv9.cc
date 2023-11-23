#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if (!(a >= 2 && a <= 10000 && b >= 2 && b <= 10000 && c >= 2 && c <= 10000))
    {
        return -1;
    }
    int out1 = (a+b)%c;
    int out2 = ((a%c)+(b%c))%c;
    int out3 = (a*b)%c;
    int out4 = ((a%c)*(b%c))%c;
    cout << out1 << endl;
    cout << out2 << endl;
    cout << out3 << endl;
    cout << out4 << endl;
    return 0;
}