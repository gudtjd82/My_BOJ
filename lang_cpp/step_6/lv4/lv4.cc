#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    string rev_str = "";

    cin >> str;

    for(int i = str.length()-1; i >= 0; i--)
    {
        rev_str += str[i];
    }

    if (!str.compare(rev_str))
    {
        cout << "1" << endl;
    }
    else
        cout << "0" << endl;
    return 0;
}