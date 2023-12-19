#include <iostream>
#include <string>

using namespace std;

int main(){
    int n,m;
    int **a, **b, **sum;

    cin >> n >> m;

    a = new int*[n];
    for(int i =0; i < n; i++)
        a[i] = new int[m];

    b = new int*[n];
    for(int i =0; i < n; i++)
        b[i] = new int[m];

    sum = new int*[n];
    for(int i =0; i < n; i++)
        sum[i] = new int[m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> b[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
