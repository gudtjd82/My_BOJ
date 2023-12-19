#include <iostream>
#include <string>

using namespace std;

int main(){
    int quarter, price = 101;
    quarter = int(price /= 25);
    cout << quarter << " " << price <<endl;
    return 0;
}