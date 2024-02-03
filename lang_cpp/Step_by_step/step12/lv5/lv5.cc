#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    
    cin >> n;

    int count = 0;
    int num = 0;
    string num_str;
    while (count != n)
    {
        num++;
        num_str = to_string(num);
        for(int i =0; i < num_str.length(); i++)
        {
            if(num_str[i] == '6' && num_str[i+1] == '6' && num_str[i+2] == '6')
            {
                count++;
                break;
            }
        }
    }

    cout << num << endl;
    

    return 0;
}