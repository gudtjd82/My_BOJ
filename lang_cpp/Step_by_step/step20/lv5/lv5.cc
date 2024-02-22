#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(const pair<string, int> &a, const pair<string, int> &b)
{
    if(a.second != b.second)
    {
        return a.second > b.second;
    }
    else{
        if(a.first.length() != b.first.length())
            return a.first.length() > b.first.length();
        else{
            return a.first < b.first;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string temp;
    map<string, int> wm;

    cin >> n >> m;
    for(int i =0; i < n; i++)
    {
        cin >> temp;
        if(temp.length() < m)
            continue;
        wm[temp]++;
    }
    vector<pair<string, int>> vec(wm.begin(), wm.end());
    sort(vec.begin(), vec.end(), compare);

    for(auto w : vec)
    {
        cout << w.first << "\n";
    }

    
    return 0;
}