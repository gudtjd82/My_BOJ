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
    
    int n;
    string name, stat;
    int count = 0;
    map<string, string> members;
    vector<string> sv;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> name >> stat;
        if(members.find(name) == members.end())
        {
            members.insert(make_pair(name, stat));
        }
        else
        {
            members[name] = stat;
        }
    }

    for(auto it = members.rbegin(); it != members.rend(); ++it)
    {
        if(it->second == "enter")
            cout << it->first << "\n";
    }

    return 0;
}