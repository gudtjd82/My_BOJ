#include <iostream>
#include <string>

using namespace std;

int main(){
    string num_str;
    int sum = 0;

    cin >> num_str;

    for(int i =0; i < num_str.length(); i++)
    {   
        sum += int(num_str[i]) - 48;
    }

    cout << sum << endl;
    return 0;
}