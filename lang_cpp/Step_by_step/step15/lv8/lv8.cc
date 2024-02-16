#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const int MAX = 1000000;
    int n, t;
    int cnt = 0;

    int *prime = new int[MAX+1];

    
    for(int i = 2; i <= MAX; i++)
    {
        prime[i] = i;
    }
    for(int i = 2; i*i <= MAX; i++)
    {
        if(prime[i] == 0)
        {
            continue;
        }

        for(int j = i*i; j <= MAX; j +=i)
        {
            prime[j] = 0;
        }
    }

    cin >> t;

    int temp;
    for(int i =0; i < t; i++)
    {
        cnt = 0;
        cin >> n;

        for(int j = 2; j <= n/2; j++)
        {
            if(prime[j] != 0)
            {
                temp = n - j;
                if(prime[temp] != 0)
                    cnt++;
            }
        }

        cout << cnt << "\n";
    }

    delete[] prime;
    
    return 0;
}