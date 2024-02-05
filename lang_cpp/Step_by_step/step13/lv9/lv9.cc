#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
    if(a.length() == b.length())
    {
        for(int  i =0; i < a.length(); i++)
        {
            if(a[i] == b[i])
                continue;
            
            return (a[i] < b[i]);
        }
        return false;
    }
    else{
        return (a.length() < b.length());
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;

    cin >> n;

    string *arr = new string[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr+n, compare);

    for(int i = 0; i < n; i++)
    {
        if(i > 0 && arr[i-1] == arr[i])
            continue;

        cout << arr[i] << "\n";
    }

    return 0;
}