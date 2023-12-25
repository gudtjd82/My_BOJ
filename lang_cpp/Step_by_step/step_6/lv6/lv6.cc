#include <iostream>
#include <string>

using namespace std;

// ASCII a => 97, z => 122, A => 65, Z => 90
int main(){
    string str;
    int leng;

    cin >> str;

    leng = str.length();

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == 'c')
        {
            if(str[i+1] == '=')
            {
                leng--;
                i++;
            }
            else if(str[i+1] == '-')
            {
                leng--;
                i++;
            }
        }
        else if (str[i] == 'd')
        {
            if(str[i+1] == 'z')
            {
                if(str[i+2] == '=')
                {
                    leng -= 2;
                    i += 2;
                }
            }
            else if(str[i+1] == '-')
            {
                leng--;
                i++;
            }
        }
        else if(str[i] == 'l')
        {
            if(str[i+1] == 'j')
            {
                leng--;
                i++;
            }
        }
        else if(str[i] == 'n')
        {
            if(str[i+1] == 'j')
            {
                leng--;
                i++;
            }
        }
        else if(str[i] == 's')
        {
            if(str[i+1] == '=')
            {
                leng--;
                i++;
            }
        }
        else if(str[i] == 'z')
        {
            if(str[i+1] == '=')
            {
                leng--;
                i++;
            }
        }
    }

    cout << leng << endl;

    return 0;
}