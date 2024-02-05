#include <iostream>
#include <string>

using namespace std;

typedef struct coordinate
{
    int x;
    int y;
} coordinate;

bool compare(coordinate a, coordinate b)
{
    if(a.x == b.x)
    {
        return (a.y < b.y);
    }
    else
        return (a.x < b.x);
}

void my_merge(coordinate *arr, int p, int q, int r)
{
    int i = 0;
    int arr1_size = q-p+1;
    int arr2_size = r-q;

    coordinate *arr1 = new coordinate[arr1_size+1];
    coordinate *arr2 = new coordinate[arr2_size+1];

    arr1[arr1_size].x = 100000;
    arr1[arr1_size].y = 100000;
    arr1[arr2_size].x = 100000;
    arr1[arr2_size].y = 100000;

    for(int i = 0; i < arr1_size; i++)
    {
        arr1[i].x = arr[i+p].x;
        arr1[i].y = arr[i+p].y;
    }
    for(int i = 0; i < arr2_size; i++)
    {
        arr2[i].x = arr[i+q+1].x;
        arr2[i].y = arr[i+q+1].y;
    }

    int j = 0, k = 0;
    for(int i = p; i <= r; i++)
    {
        if(compare(arr1[j], arr2[k]))
        {
            arr[i].x = arr1[j].x;
            arr[i].y = arr1[j].y;
            j++;
        }
        else{
            arr[i].x = arr2[k].x;
            arr[i].y = arr2[k].y;
            k++;
        }
    }
}

void my_mergeSort(coordinate *arr, int p, int r)
{
    int q = (p+r)/2;

    my_mergeSort(arr, p, q);
    my_mergeSort(arr, q+1, r);
    my_merge(arr, p, q, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y;

    cin >> n;

    coordinate *arr = new coordinate[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    my_mergeSort(arr, 0, n-1);

    for(int i =0; i <n; i++)
    {
        cout << arr[i].x << " " << arr[i].y << "\n";
    }

    return 0;
}