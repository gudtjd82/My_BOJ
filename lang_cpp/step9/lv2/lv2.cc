#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, k;
    int q = 0;

    cin >> n >> k;

    for(int i = 0; i < k; i++)
    {
        if (q == n)
        {
            q = 0;
            break;
        }
        for(int j = q+1; j <= n; j++)
        {
            if(n%j == 0)
            {
                q = j;
                break; 
            }
        }
    }

    cout << q << endl;
    return 0;
}