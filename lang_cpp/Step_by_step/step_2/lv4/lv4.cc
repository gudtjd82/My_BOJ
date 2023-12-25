#include <iostream>
#include <string>

using namespace std;

int main(){
    int x, y;    
    int quadrant;
    cin >> x;
    cin >> y;

    if (x > 0 && y > 0)
        quadrant = 1;
    else if (x < 0 && y >0)
        quadrant = 2;
    else if (x < 0 && y < 0)
        quadrant = 3;
    else if (x > 0 && y < 0)
        quadrant = 4;
    else   
        return -1;
    
    cout << quadrant << endl;

    return 0;
}