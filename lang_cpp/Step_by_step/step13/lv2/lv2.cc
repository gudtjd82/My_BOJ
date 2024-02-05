
#include <iostream>
#include <string>

using namespace std;

int main(){
    int arr[5];
    int avg = 0;
    int median;

    for(int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        avg += arr[i];
    }

    for(int i = 1; i < 5; i++)
    {
        int key = arr[i];
        int j;
        for(j = i-1; j >= 0 && arr[j] > key; j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }

    avg /= 5;
    median = arr[2];

    cout << avg << endl;
    cout << median << endl;
    return 0;
}