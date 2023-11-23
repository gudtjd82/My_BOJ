#include <iostream>
#include <string>

using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < n-i; k++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}