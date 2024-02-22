#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned long long fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    cout << fibonacci(n) << endl;
    
    return 0;
}