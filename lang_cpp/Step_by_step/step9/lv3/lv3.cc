#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    int sum;
    string sum_str;

    while (true)
    {
        sum = 1;
        sum_str = "";

        cin >>n;

        if (n == -1)
        {
            break;
        }

        sum_str = to_string(n) + " = 1";

        for(int i = 2; i <= n/2; i++)
        {
            if(n % i == 0)
            {
                sum += i;
                sum_str += " + " + to_string(i);
            }
        }

        if(sum == n)
        {
            cout << sum_str << endl;
        }
        else{
            cout << to_string(n) + " is NOT perfect." << endl;
        }
        
    }
    
    return 0;
}