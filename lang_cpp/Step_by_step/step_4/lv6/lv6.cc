#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, m;
    int i, j, temp;
    int* basket;

    cin >> n >> m;

    basket = new int[n];
    for (int l = 0; l<n; l++)
        basket[l] = l+1;

    for (int l = 0; l < m; l++)
    {
        cin >> i >> j;
        temp = basket[i-1];
        basket[i-1] = basket[j-1];
        basket[j-1] = temp;
    }

    for (int l = 0; l<n; l++)
        cout << basket[l] << " ";
    cout << endl;

    return 0;
}