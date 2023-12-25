#include <iostream>
#include <string>

using namespace std;

int pow(int n, int exp)
{
    int result = 1;

    if (exp == 0)
        return 1;

    for(int i = 0; i < exp; i++)
        result *= n;
    
    return result;
}

int main(){
    string num_str;
    int b, remainder, q;
    char digit;
    string result = "";

    cin >> num_str >> b;

    q = stoi(num_str);
    int i =0;

    while(q > 0)
    {
        remainder = q % b;
        q = q / b;
        if(remainder >= 10)
            digit = remainder - 10 + 'A';
        else  
            digit = remainder - 1 + '1';
        
        result = digit + result;
    }

    cout << result << endl;

    return 0;
}