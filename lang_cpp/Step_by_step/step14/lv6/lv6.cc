#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    string temp;
    set<string> not_heard, not_seen;
    int result = 0;
    vector<string> rv;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;

        not_heard.insert(temp);
    }

    for(int i =0; i < m; i++)
    {
        cin >> temp;

        not_seen.insert(temp);
    }

    if(n > m)
    {
        for(auto elem : not_seen)
        {
            auto it = not_heard.find(elem);
            if(it != not_heard.end())
            {
                result++;
                rv.push_back(*it);
            }

        }
    }
    else{
        for(auto elem : not_heard)
        {
            auto it = not_seen.find(elem);
            if(it != not_seen.end())
            {
                result++;
                rv.push_back(*it);
            }
        }
    }

    cout << result << "\n";
    for(auto elem : rv)
    {
        cout << elem << "\n";
    }

    return 0;
}