#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int result = 1;

    cin >> n;

    for(int i = 0; i< n; i++)
    {
        result *= 2;
    }

    cout << result << endl;
    return 0;
}