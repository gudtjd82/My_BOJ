#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b, c;
    int prize;

    cin >> a >> b >> c;

    if(a == b)
    {
        if( a == c)
        {
            prize = 10000 + a*1000;
        }
        else
            prize = 1000 + a*100;
    }
    else
    {
        if(a == c)
            prize = 1000 + a*100;
        else if (b == c)
            prize = 1000 + b*100;
        else
        {   
            int max = (a > b) ? a : b;
            max = (max > c) ? max : c;
            prize = max * 100;
        }
    }

    cout << prize << endl;

    return 0;
}