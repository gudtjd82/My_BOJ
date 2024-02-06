#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    string temp;
    int count = 0;
    set<string> ss;
    vector<string> sv;

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        ss.insert(temp);
    }

    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        sv.push_back(temp);
    }

    for(auto elem: sv)
    {
        if(ss.find(elem) != ss.end())
        {
            count++;
        }
    }

    cout << count << "\n";

    return 0;
}