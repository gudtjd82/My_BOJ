#include <iostream>
#include <string>

using namespace std;

int main(){
    int y;
    int result;

    cin >> y;

    if (y%4 == 0 && y%100 != 0)
    {
        result = 1;
    }
    else if (y%400 == 0)
    {
        result = 1;
    }
    else{
        result = 0;
    }

    cout << result << endl;
    
    return 0;
}