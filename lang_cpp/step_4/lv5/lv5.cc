#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, m;
    int i, j, k;
    int* basket;

    cin >> n >> m;

    basket = new int[n];
    for (int l = 0; l<n; l++)
        basket[l] = 0;

    for (int l = 0; l < m; l++)
    {
        cin >> i >> j >> k;
        for (int cur = i-1; cur < j; cur++)
        {
            basket[cur] = k;
        }
    }

    for (int l = 0; l<n; l++)
        cout << basket[l] << " ";
    cout << endl;

    return 0;
}