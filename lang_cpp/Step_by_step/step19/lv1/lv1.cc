#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    cout << n*(n-1) << endl;
    
    return 0;
}