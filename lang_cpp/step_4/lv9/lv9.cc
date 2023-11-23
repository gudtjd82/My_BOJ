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
        for(int p = i-1, q = j-1; p<j/2-1; p++, q--)
        {
            temp = basket[p];
            basket[p] = basket[q];
            basket[q] = temp;
        }
    }

    for (int l = 0; l<n; l++)
        cout << basket[l] << " ";
    cout << endl;

    return 0;
}