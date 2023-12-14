#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    string str;

    cin >> t;

    for(int i =0; i < t; i++)
    {
        cin >> str;
        cout << str[0] << str[str.length()-1] << endl;
    }
    return 0;
}