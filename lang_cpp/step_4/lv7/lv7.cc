#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    int* students = new int[30];

    for (int i = 0; i < 30; i++)
    {
        students[i] = 0;
    }    
    
    for (int i = 0; i < 28; i++)
    {
        cin >> n;
        students[n-1] = 1;
    }

    for (int i = 0; i < 30; i++)
    {
        if(students[i] == 0)
            cout << i+1 << endl;
    }

    return 0;
}