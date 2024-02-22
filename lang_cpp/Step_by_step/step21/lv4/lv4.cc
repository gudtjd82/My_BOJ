#include <iostream>
#include <string>
#include <vector>

using namespace std;

int save_num = 0;
int result = 0;

void my_merge(int *arr, int p, int q, int r, int target)
{
    int size = r-p+1;
    int *temp = new int[size];

    int i = p, j = q+1, k = 0;
    while (i<=q && j <= r)
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];        
            if(++save_num == target)
                result = temp[k-1];
        }
        else
        {
            temp[k++] = arr[j++];
            if(++save_num == target)
                result = temp[k-1];
        }
    }
    while (i<=q)
    {
        temp[k++] = arr[i++];
        if(++save_num == target)
                result = temp[k-1];
    }
    while (j<=r)
    {
        temp[k++] = arr[j++];
        if(++save_num == target)
                result = temp[k-1];
    }

    for(i = p, k = 0; i <= r; i++, k++)
    {
        arr[i] = temp[k];
    }
    
    
    
}

void my_mergeSort(int* arr, int p, int r, int target)
{
    int q = (r+p)/2;
    if(p < r)
    {
        my_mergeSort(arr, p, q, target);
        my_mergeSort(arr, q+1, r, target);
        my_merge(arr, p, q, r, target);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int k;

    cin >> n >> k;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    my_mergeSort(arr, 0, n-1, k);

    if(save_num < k)
    {
        cout << "-1\n";
        return 0;
    }

    cout << result << "\n";

    return 0;
}