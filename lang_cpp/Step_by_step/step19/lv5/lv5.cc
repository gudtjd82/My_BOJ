#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    int n, m;
    int ans = 1;

    cin >> t;

    for(int i =0; i < t; i++)
    {
        cin >> n >> m;

        for(int j = 0; j < n; j++)
        {
            ans *= m-j;
            ans /= j+1;
        }
        cout << ans << endl;
        ans = 1;
    } 
}