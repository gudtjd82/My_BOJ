#include <iostream>
#include <string>

using namespace std;

int main()
{   
    int n, m;
    int sum = 0;
    int d;

    cin >> n;

    m = 1;
    while (m < 1000000)
    {
        int i = 1;
        sum = m;
        while(true)
        {
            d = (m % (i*10)) / i;
            if(d == 0)
            {
                break;
            }

            sum += d;
            i *= 10;
        }
        if (sum == n)
        {
            break;
        }
        m++;
    }

    if(n == sum)
        cout << m << endl;
    else   
        cout << 0 << endl;
    

    return 0;
}