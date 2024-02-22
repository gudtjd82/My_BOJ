#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> divs;
    int n, temp;

    cin >> n;
    for(int i =0; i < n; i++)
    {
        cin >> temp;

        divs.push_back(temp);
    }
    
    cout << *max_element(divs.begin(), divs.end()) * *min_element(divs.begin(), divs.end()) << endl;
    
    return 0;
}