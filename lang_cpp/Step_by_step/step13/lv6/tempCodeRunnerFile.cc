#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int d, num;
    int c[10] = {0};

    cin >> num;

    int i =0;
    int t = 1;
    while (true)
    {
        if(num%t == num)
            break;
        d = (num/t)%10;
        t *= 10;
        
        c[d]++;
        i++;
    }
    
    for(int i = 9; i >= 0; i--)
    {
        for(int j = 0; j < c[i]; j++)
        {
            cout << i << "\n";
        }
    }
    
    return 0;
}