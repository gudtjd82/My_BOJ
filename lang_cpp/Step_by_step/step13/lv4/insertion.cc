
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;

    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j;
        for(j = i-1; j >= 0 && arr[j] < key; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}