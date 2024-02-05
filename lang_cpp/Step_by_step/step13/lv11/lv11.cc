#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct number
{
    int num;
    int idx;
    int compress;
};


bool compare(number a, number b)
{
    return a.num < b.num;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;

    cin >> n;

    number *arr = new number[n];
    number *sort_arr = new number[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].num;
        arr[i].idx = i;
        sort_arr[i] = arr[i];
    }

    sort(sort_arr, sort_arr+n, compare);

    for(int i = 0, c = 0; i < n; i++)
    {
        if(i > 0)
        {
            if(sort_arr[i-1].num == sort_arr[i].num)
            {
                c--;
            }
        }

        arr[sort_arr[i].idx].compress = c;
        
        c++;
    }


    for(int i = 0; i < n; i++)
    {
        cout << arr[i].compress << "\n";
    }

    return 0;
}