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
    int temp;
    set<int> cards;
    vector<int> nums;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        cards.insert(temp);
    }

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }

    for(auto elem : nums)
    {
        if(cards.find(elem) != cards.end())
        {
            cout << 1;
        }
        else
            cout << 0;
        cout << " ";
    }
    cout << "\n";

    return 0;
}