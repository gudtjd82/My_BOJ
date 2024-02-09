#include <iostream>
#include <cmath>

using namespace std;

bool isprime(long long n)
{
    if (n <= 1)
        return false;

    if(n == 2 || n == 3)
        return true;

    if(n % 2 == 0 || n % 3  == 0)
        return false;
    
    for(int i = 5; (i*i)<= n; i++)
    {
        if(i*i == n)
            return false;

        if(n%i == 0)
            return false;
    }

    return true;

}

int main(){
    long long t;
    long long n;

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        cin >> n;

        while (!isprime(n))
        {
            n++;
        }
        cout << n << endl;
    }

    return 0;
}