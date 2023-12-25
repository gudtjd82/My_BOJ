#include <iostream>
#include <string>

using namespace std;

int main(){
    int length;
    int x;
    int* arr;

    cin >> length >> x;

    arr = new int[length];

    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < length; i++)
    {
        if(arr[i] < x)
            cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}