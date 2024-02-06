#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool isdigit(string str)
{
    for(auto elem: str)
    {
        if(!(elem >=0 && elem <= 57))
        {
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    string name, temp;
    string seq;
    int count = 0;
    map<string, string> pm;
    vector<string> search;

    cin >> n >> m;
    for(int i =0; i <n; i++)
    {
        cin >> name;
        seq = to_string(i+1);
        pm.insert(make_pair(name, seq));
    }

    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        search.push_back(temp);
    }

    for(auto elem: search)
    {
        auto it = pm.find(elem);
        if(it != pm.end())
        {
            cout << it->second << "\n";
        }
        else{
            for(auto elem2 : pm)
            {
                if(elem2.second == elem)
                {
                    cout << elem2.first << "\n";
                }
            }
        }
    }

    return 0;
}