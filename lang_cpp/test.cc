#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> nums(5, 10);

    for(auto elem : nums)
        cout << elem << endl;
    
    return 0;
}