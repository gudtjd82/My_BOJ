#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    const int MAX = 123456*2;
    int cnt = 0;

    int prime[MAX+1];
    
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

    while (true)
    {
        cnt = 0;
        cin >> n;
        if(n == 0)
            break;
        for(int i = n+1; i <= 2*n; i++)
        {
            if(prime[i] != 0)
            {
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    
    return 0;
}