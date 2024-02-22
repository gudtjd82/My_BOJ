#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    string temp1, temp2;
    map<string, int> members;
    int cnt = 0;

    members.insert(make_pair("ChongChong", 1));

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;

        if(members[temp1] == 1)
        {
            members[temp2] = 1;
        }
        else if(members[temp2] == 1)
            members[temp1] = 1;
    }

    for(auto mem : members)
    {
        if(mem.second == 1)
            cnt++;
    }
    
    cout << cnt << endl;

    return 0;
}