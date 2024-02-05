#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct member
{
    int age;
    string name;
    int seq;
};


bool compare(member a, member b)
{
    if(a.age == b.age)
    {
        return a.seq < b.seq;
    }
    else{
        return a.age < b.age;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;

    cin >> n;

    member *arr = new member[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].age >> arr[i].name;
        arr[i].seq = i;
    }

    sort(arr, arr+n, compare);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i].age << " " << arr[i].name << "\n";
    }

    return 0;
}