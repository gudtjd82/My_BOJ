#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int idx;
    char c;

    cin >> str;

    for(int i = 97; i < 123; i++)
    {
        c = char(i);
        if((idx = str.find(c)) == string::npos)
            idx = -1;
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}