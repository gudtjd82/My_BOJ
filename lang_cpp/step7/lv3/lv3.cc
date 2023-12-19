#include <iostream>
#include <string>

using namespace std;

int main(){
    char** mat;
    string str[5];
    int max_leng = 0;

    for(int i =0; i <5; i++)
    {
        cin >> str[i];
        if(str[i].length() > max_leng)
            max_leng = str[i].length();
    }

    for(int i = 0; i < max_leng; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(str[j].length() > i)
            {
                cout << str[j][i];
            }
            else{
                continue;
            }
        }
    }
    cout << endl;

    return 0;
}
