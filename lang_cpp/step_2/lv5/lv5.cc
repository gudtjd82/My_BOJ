#include <iostream>
#include <string>

using namespace std;

int main(){
    int h, m;
    int new_h, new_m;

    cin >> h >> m;

    if ( !(h >= 0 && h <= 23) || !(m >= 0 && m <= 59))
        return -1;
    
    new_m = m - 45;

    if (new_m < 0)
    {
        new_h = h-1;
        new_m += 60;
        if (new_h < 0)
        {
            new_h += 24;
        }
    }
    else{
        new_h = h;
    }
    
    printf("%d %d\n", new_h, new_m);

    return 0;
}