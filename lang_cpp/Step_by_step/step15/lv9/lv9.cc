#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int cnt = 0;

    cin >> n;

    int sq;
    for(int i = 1; i*i <= n; i++)
    {
        cnt++;
    }
    
    cout << cnt << "\n";
    return 0;
}