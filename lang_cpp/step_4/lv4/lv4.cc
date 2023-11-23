#include <iostream>
#include <string>

using namespace std;

int main(){
    int length = 9;
    int* arr;
    int max, index_of_max;

    arr = new int[length];

    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    max = arr[0];
    index_of_max = 0;

    for (int i = 1; i < length; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            index_of_max = i+1;
        }
    }
    cout << max << endl;
    cout << index_of_max << endl;

    return 0;
}