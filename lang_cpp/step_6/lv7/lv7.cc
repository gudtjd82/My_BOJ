#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string str;
    char* letters = new char[100];
    int count = 0;
    char check_alph;
    bool check_groub = true;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        for(int j = 0; j < str.length(); j++)
        {
            string temp_str = str.substr(j+1);
            check_alph = str[j];
            if (temp_str.find(check_alph) != string::npos && temp_str.find(check_alph) > 0)
            {
                check_groub = false;
            }
        }
        if(check_groub)
            count++;

        check_groub = true;
    }

    cout << count << endl;

    return 0;
}
