#include <iostream>
#include <string>

using namespace std;

int main(){
    int a0, a1, c, n0;

    cin >> a1 >> a0;
    cin >> c; 
    cin >> n0;

    if(a1 > c)
    {
        cout << 0 << endl;
        return 0;
    }
    else if(a1 == c)
    {
        if(a0 > 0)
        {
            cout << 0 << endl;
            return 0;
        }
    }

    if(a0 / double(c-a1) > n0)
    {
        cout << 0 << endl;
        return 0;
    }

    cout << 1 << endl;
    return 0;
}