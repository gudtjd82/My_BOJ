#include <iostream>
#include <string>

using namespace std;
// 6 18 36 60
// 3 6  9  12
int main(){
    int n;
    
    cin >>n;

    if (n == 1)
    {
        cout << 1;
        return 0;
    }
        

    int i =2;

    while(true)
    {
        if( n > 3*(i-1)*(i-2)+1 && n <= 3*i*(i-1)+1)
            break;
        i++;
    }

    cout << i;
    return 0;
}