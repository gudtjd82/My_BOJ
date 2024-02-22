#include <iostream>
#include <string>
#include <vector>

using namespace std;

int fac(int n)
{
    if(n == 0)
        return 1;
    return n * fac(n-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    int ans;

    cin >> n >> k;

    ans = (fac(n)/fac(n-k))/fac(k);

    cout << ans << endl;

    return 0;
}