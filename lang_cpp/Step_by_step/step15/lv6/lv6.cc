#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> m >> n;

    // int *prime = new int[n+1];
    int prime[1000001];
    for(int i = 2; i <= n; i++)
    {
        prime[i] = i;
    }
    for(int i = 2; i*i <= n; i++)
    {
        if(prime[i] == 0)
        {
            continue;
        }

        for(int j = i*i; j <= n; j +=i)
        {
            prime[j] = 0;
        }
    }

    for(int i = m; i <= n; i++)
    {
        if(prime[i] != 0)
        {
            cout << i << "\n";
        }
    }

    return 0;
}