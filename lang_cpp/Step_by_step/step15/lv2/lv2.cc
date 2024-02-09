#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
    if(a < b)
    {
        if(a == 0)
        {
            return b;
        }
        return gcd(b%a, a);
    }   
    else{
        if (b == 0)
            return a;
        return gcd(a%b, b);
    }
}

long long lcm(long long a, long long b)
{
    return (a*b)/gcd(a, b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int a, b;

    cin >> a >> b;

    cout << lcm(a, b) << "\n";

    return 0;
}