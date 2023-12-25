#include <iostream>
#include <string>

using namespace std;

// ASCII a => 97, z => 122, A => 65, Z => 90
int main(){
    string str;
    int temp = 1;
    int max_num = -1;
    char max_char;

    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        int n = int(str[i]);

        if(n >= 97 && n <=122)
            str[i] = char(n-32);
    }

    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] != '*')
        {
            for(int j = i+1; j<str.length(); j++)
            {
                if(str[i] == str[j])
                {
                    temp++;
                    str[j] = '*';
                }
            }
            if(temp > max_num)
            {
                max_num = temp;
                max_char = str[i];
            }
            else if (temp == max_num){
                cout << "?" << endl;
                return 0;
            }
            temp = 1;
        }
    }

    cout << max_char << endl;

    return 0;
}