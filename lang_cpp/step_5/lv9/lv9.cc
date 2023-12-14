#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int n = 0;

    getline(cin, str);

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] != ' ' && (str[i+1] == ' ' || str[i+1] == '\0'))
        {
            n++;
        }
    }
    cout << n << endl;

    return 0;
}