
#include <iostream>
#include <string>

using namespace std;

void my_merge(int* arr, int* arr1, int* arr2, int arr1_size, int arr2_size)
{
    int p = 0, q = 0, i = 0;
    while (p < arr1_size || q < arr2_size)
    {
        if(p >= arr1_size)
        {
            arr[i] = arr2[q];
            q++;
        }
        else if(q >= arr2_size)
        {
            arr[i] = arr1[p];
            p++;
        }
        else if((arr1[p] < arr2[q]))
        {
            arr[i] = arr1[p];
            p++;
        }
        else{
            arr[i] = arr2[q];
            q++;
        }
        i++;
    }
}

void my_mergeSort(int* arr, int n)
{
    if (n <= 1)
        return;
    int p = n/2;
    int size1 = p, size2 = n-p;
    int *arr1 = new int[size1];
    int *arr2 = new int[size2];

    for(int i = 0; i < size1; i++)
    {
        arr1[i] = arr[i];
    }
    for(int i = 0; i < size2; i++)
    {
        arr2[i] = arr[size1 + i];
    }

    my_mergeSort(arr1, size1);
    my_mergeSort(arr2, size2);
    my_merge(arr, arr1, arr2, size1, size2);
}

int main(){
    int n, temp;

    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // merge sort
    my_mergeSort(arr, n);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
    
    return 0;
}