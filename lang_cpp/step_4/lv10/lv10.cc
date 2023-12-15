#include <iostream>
#include <string>

using namespace std;

int main(){
    int length;
    double max, mean = 0;
    double* arr;

    cin >> length;

    arr = new double[length];
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }

    max = arr[0];

    for (int i = 1; i < length; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }

    for (int i = 0; i < length; i++)
    {
        mean += (arr[i]/max) * 100;
    }
    mean = mean/length;

    cout << fixed;
    cout.precision(3);
    cout << mean << endl;


    return 0;
}