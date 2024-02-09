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
    string name, temp;
    string seq;
    int count = 0;
    map<string, string> pm;
    vector<string> names;

    cin >> n >> m;
    for(int i =0; i <n; i++)
    {
        cin >> name;
        seq = to_string(i+1);
        names.push_back(name);
        pm.insert(make_pair(name, seq));
    }

    for(int i = 0; i < m; i++)
    {
        cin >> temp;

        if(temp[0] >= 65 && temp[0] <= 90)
        {
            cout << pm[temp] << "\n";
        }
        else{
            cout << names[stoi(temp)-1] << "\n";
        }
       
    }

    return 0;
}