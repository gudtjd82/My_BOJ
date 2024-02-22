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

    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(temp == "ENTER")
            continue;
        
        members.insert(temp);
    }

    cout << members.size() << endl;

    return 0;
}