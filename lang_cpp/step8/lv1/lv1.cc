#include <iostream>
#include <string>

using namespace std;

int pow(int n, int exp)
{
    int result = 1;
    for(int i = 0; i < exp; i++)
        result *= n;
    
    return result;
}

int main(){
    string num_str;
    int b, digit, result = 0;

    cin >> num_str >> b;

    for(int i =0, j = num_str.length()-1; i < num_str.length(); i++, j--)
    {
        if(int(num_str[i]) >= 65 && int(num_str[i]) <= 90)
            digit = int(num_str[i]) - 55;
        else  
            digit = int(num_str[i]) - 48;
        
        result += digit * pow(b, j);
    }

    cout << result << endl;

    return 0;
}