#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

set<int> difference(set<int> a, set<int> b)
{
    set<int> diff;

    for(auto elem : a)
    {
        if(b.find(elem) == b.end())
        {
            diff.insert(elem);
        }
    }

    return diff;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    int temp;
    set<int> a, b, a_b, b_a;

    cin >> n >> m;
    for(int i = 0; i<n; i++)
    {
        cin >> temp;
        a.insert(temp);
    }
    for(int i = 0; i<m; i++)
    {
        cin >> temp;
        b.insert(temp);
    }

    a_b = difference(a, b);
    b_a = difference(b, a);

    cout << a_b.size() + b_a.size() << "\n";

    return 0;
}