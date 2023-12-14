#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    int space_num, star_num;

    cin >> n;

    for(space_num = n-1, star_num = 1; space_num >= 0; space_num--, star_num += 2)
    {
        for(int i = 0; i < space_num; i++)
            cout << " ";

        for(int i = 0; i < star_num; i++)
            cout << "*";
        
        cout << endl;
    }

    for(space_num = 1, star_num = 2*n-3; space_num < n; space_num++, star_num -= 2)
    {
        for(int i = 0; i < space_num; i++)
            cout << " ";

        for(int i = 0; i < star_num; i++)
            cout << "*";
        
        cout << endl;
    }


    return 0;
}