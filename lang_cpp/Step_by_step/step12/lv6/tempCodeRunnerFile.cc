#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, temp;
    int max_five = 0;
    int num_three = 0, num_five;
    int result = 0;

    cin >> n;
    temp = n;

    while (temp >= 5)
    {
        temp -= 5;
        max_five++;
    }

    temp = n;
    for(int i = max_five; i >= 0; i--)
    {
        temp -= i * 5;
        while (temp >= 3)
        {
            temp -= 3;
            num_three++;
        }
        if(temp > 0)
        {
            num_three = 0;
            temp = n;
        }
        else if(temp == 0)
        {
            num_five = i;
            break;
        }
    }

    cout << num_three + num_five << endl;
    return 0;
}