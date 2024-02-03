#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, temp;
    int max_five = 0;
    int num_three = 0, num_five = -1;
    int result = 0;

    cin >> n;
    max_five = n/5;

    temp = n;
    while(true)
    {
        if(max_five < 0)
        {
            cout << -1 << endl;
            return 0;
        }

        temp -= 5*max_five;
        if(temp%3 == 0)
        {
            num_five = max_five;
            num_three = temp/3;
            break;
        }
        max_five--;
        temp = n;
    }

    cout << num_three + num_five << endl;
    return 0;
}