#include <iostream>
#include <string>

using namespace std;

int main(){
    int m, n;
    int sum = 0;
    int min_prime = 0;
    bool *is_prime, first_prime = false;

    cin >> m >> n;

    is_prime = new bool[n-m+1];

    for(int i = 0; i < n-m+1; i++)
    {
        is_prime[i] = true;
    }

    for(int i = m; i <= n; i++)
    {   
        if (i == 1)
            continue;

        if(is_prime[i-m])
        {
            for(int j = 2; j*j <= i; j++)
            {
                if(j*j == i){
                    is_prime[i-m] = false;
                    break;
                }
                else if(i%j == 0){
                    is_prime[i-m] = false;
                    break;
                }
            }
            if(is_prime[i-m])
            {
                if(!first_prime)
                {
                    first_prime = true;
                    min_prime = i;
                }
                sum += i;

                for(int k = 2*i; k <= n; k += i)
                {
                    is_prime[k-m] = false;
                }
            }
        }
    }

    if(sum > 0)
    {
        cout << sum <<endl;
        cout << min_prime << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}