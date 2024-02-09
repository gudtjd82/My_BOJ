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
    
    string str, temp;
    set<string> ss;

    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        for(int j = 1; j <= str.length()-i; j++)
        {
            temp = str.substr(i, j);
            ss.insert(temp);
        }
    }

    cout << ss.size() << "\n";


    return 0;
}