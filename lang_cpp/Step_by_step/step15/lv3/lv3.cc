#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long get_gcd(long long a, long long b)
{
    if(a < b)
    {
        if(a == 0)
        {
            return b;
        }
        return get_gcd(b%a, a);
    }   
    else{
        if (b == 0)
            return a;
        return get_gcd(a%b, b);
    }
}

long long get_lcm(long long a, long long b)
{
    return (a*b)/get_gcd(a, b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int a, b, c , d;

    cin >> a >> b >> c >> d;

    a = a*d + c*b;
    b = b*d;

    int gcd = get_gcd(a, b);

    cout << a/gcd << " " << b/gcd << "\n";

    return 0;
}