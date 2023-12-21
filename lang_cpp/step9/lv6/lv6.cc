#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    
    cin >> n;

    if (n == 1)
    {
        return 0;
    }

    int d = 2;
    while (true)
    {
        if(n%d == 0)
        {
            cout << d << endl;
            n /= d;
        }
        else
        {
            d++;
        }

        if(n == 1)
        {
            break;
        }
    }
    

    return 0;
}