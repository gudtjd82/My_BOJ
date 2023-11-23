#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, result = 0;
    int* remain = new int[42];

    fill_n(remain, 42, 0);

    for (int i = 0; i < 10; i++)
    {
        cin >> n;
        remain[n%42]++;
    }

    for (int i = 0; i < 42; i++)
    {
        if(remain[i] > 0)
            result++;
    }

    cout << result << endl;

    return 0;
}