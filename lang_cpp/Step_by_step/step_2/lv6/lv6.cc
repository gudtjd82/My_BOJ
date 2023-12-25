#include <iostream>
#include <string>

using namespace std;

int main(){
    int h, m;
    int time;
    int new_h, new_m;

    cin >> h >> m;
    cin >> time;

    if ( !(h >= 0 && h <= 23) || !(m >= 0 && m <= 59))
        return -1;
    
    new_m = m + time;

    if (new_m >= 60)
    {
        int time_hour = new_m / 60;
        new_m = new_m % 60;
        new_h = h + time_hour;
        
        if (new_h >= 24)
        {
            new_h -= 24;
        }
    }
    else{
        new_h = h;
    }
    
    printf("%d %d\n", new_h, new_m);

    return 0;
}