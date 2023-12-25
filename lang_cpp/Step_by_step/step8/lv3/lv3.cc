#include <iostream>
#include <string>

using namespace std;

int main(){
    int quarter = 0, dime = 0, nickel = 0, penny = 0;
    int n, price;

    cin >> n;

    for(int i =0; i < n; i++)
    {
        cin >> price;

        quarter = price / 25;
        price %= 25;
        dime = price / 10;
        price %= 10;
        nickel = price/5;
        price %= 5;
        penny = price;

        cout << quarter << " "<< dime << " "<< nickel << " "<< penny << endl;
    }
    return 0;
}