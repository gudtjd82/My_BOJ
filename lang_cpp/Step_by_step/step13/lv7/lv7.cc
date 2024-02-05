#include <iostream>
#include <string>
#include <algorithm>

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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x, y;

    cin >> n;
    coordinate* arr = new coordinate[n];

    for(int i =0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
    }

    sort(arr, arr + n, compare);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i].x << " " << arr[i].y << "\n";
    }

    return 0;
}