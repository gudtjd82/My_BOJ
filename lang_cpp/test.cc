#include <iostream>
#include <string>

using namespace std;

int main(){
    int arr[3][3];
    int a = 3;

    arr[2][2] = a;

    a  = 1;

    cout << arr[2][2] << endl;
    
    return 0;
}