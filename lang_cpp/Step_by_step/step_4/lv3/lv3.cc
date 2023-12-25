#include <iostream>
#include <string>

using namespace std;

int main(){
    int length;
    int* arr;
    int min, max;

    cin >> length;

    arr = new int[length];

    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    min = arr[0];
    max = arr[0];

    for (int i = 1; i < length; i++)
    {
        if (min > arr[i])
            min = arr[i];
        if (max < arr[i])
            max = arr[i];
    }
    cout << min << " " << max << endl;

    return 0;
}