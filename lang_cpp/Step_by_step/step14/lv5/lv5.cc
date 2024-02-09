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
    int temp;
    map<int, int> cards;
    vector<int> nums;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(cards.find(temp) != cards.end())
        {
            cards[temp]++;
        }
        else{
            cards.insert(make_pair(temp, 1));
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> temp;

        auto it = cards.find(temp);
        if(it != cards.end())
        {
            cout << it->second;
        }
        else
            cout << 0;
        cout << " ";
    }
    cout << "\n";

    return 0;
}