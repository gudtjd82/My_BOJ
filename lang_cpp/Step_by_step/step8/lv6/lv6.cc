#include <iostream>
#include <string>

using namespace std;

int main(){
    int x, count = 0;
    int a = 0,b = 0;
    bool finish = false;

    cin >> x;

    int i = 1;
    while (!finish)
    {
        for(int j =1; j <= i; j++)
        {
            count++;
            if(i%2 == 1)
            {
                a = i-j+1;
                b = j;
            }
            else
            {
                a = j;
                b = i-j+1;
            }
            if(count == x)
            {
                finish = true;
                break;
            }
        }
        i++;
    }

    cout << a <<"/"<< b << endl; 
    
    return 0;
}