#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    string temp;
    set<string> members;
    int cnt = 0;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp == "ENTER")
        {
            cnt += members.size();
            members.clear();
            continue;
        }
        
        members.insert(temp);
    }
    cnt += members.size();
    
    cout << cnt << endl;

    return 0;
}