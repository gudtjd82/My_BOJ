#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int time = 0;
    int* num_time = new int[10];
    string* strInNum = new string[10];
    int find_idx;

    num_time[0] = 11;
    for (int i =1; i< 10; i++)
    {
        num_time[i] = i+1;
    }

    int alph = 65;
    for(int i = 2; i <= 9; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            strInNum[i] += char(alph++);
        }
        if (i == 7 || i == 9)
            strInNum[i] += char(alph++);
    }

    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        for(int j = 0; j < 11; j++)
        {
            if (strInNum[j].find(str[i]) != string::npos)
            {
                time += num_time[j];
                break;
            }
        }
    }

    cout << time << endl;

    return 0;
}