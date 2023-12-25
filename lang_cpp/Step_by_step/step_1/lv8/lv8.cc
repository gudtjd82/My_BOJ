#include <iostream>
#include <string>

using namespace std;

int main(){
    int in_year, out_year;
    cin >> in_year;
    if ( in_year < 1000 || in_year > 3000)
    {
        return -1;
    }
    out_year = in_year - 543;
    cout << out_year << endl;
    return 0;
}