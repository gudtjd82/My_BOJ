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

    int t, a, b;
    vector<int> common_mults;

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        cin >> a >> b;

        int j = 1, k = 1;
        bool finish = false;
        while (!finish)
        {
            if(a*j < b*k)
            {
                j++;
            }
            else if(a*j == b*k)
            {
                common_mults.push_back(a*j);
                break;
            }
            else{
                k++;
            }
        }
    }
    

    for(auto elem : common_mults)
    {
        cout << elem << "\n";
    }
    

    return 0;
}