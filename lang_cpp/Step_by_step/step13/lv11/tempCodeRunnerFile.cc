#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a < b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;

    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n, compare);

    for(int i = 0, c = 0; i < n; i++)
    {
        if(i > 0)
        {
            if(arr[i-1] == arr[i])
            {
                c--;
            }
            else{
                c = i;
            }
        }

        cout << c << "\n";

        c++;
    }

    return 0;
}