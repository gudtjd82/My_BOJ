#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    int a;

    cin >> str;

    a = stoi(str);

    cout << stoi(str) << endl;
    return 0;
}