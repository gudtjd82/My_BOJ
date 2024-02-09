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

    int n;
    vector<int> trees;
    int temp;
    int gcd;
    int cnt = 0;

    cin >>n;
    for(int i =0; i < n; i++)
    {
        cin >> temp;
        trees.push_back(temp);
    }


    for(int i = 1; i < n; i++)
    {
        if(i == 1)
        {
            gcd = trees[i]-trees[i-1];
        }
        gcd = get_gcd(gcd, trees[i]-trees[i-1]);
    }

    temp = trees[0];
    int i = 1;
    while (i < n)
    {
        if((temp += gcd) < trees[i])
        {
            cnt++;
        }
        else if(temp == trees[i])
        {
            i++;
        }
    }

    cout << cnt << "\n";
    

    return 0;
}