#include <iostream>
#include <string>

using namespace std;

int pow(int n, int exp)
{
    int result = 1;

    if (exp == 0)
        return 1;

    for(int i = 0; i < exp; i++)
        result *= n;
    
    return result;
}

int main(){
    // 4, 1*2*2+1 ,+(2*3*2)+1*4, +()
    // An+1 = An + (An의 변의 개수) +  pow(4, n)
    // 변의 개수 => 1*(2^0+1)*2, 2^1*(2^1+1)*2, 2^2*(2^2+1)*2,  
    int numOfDot = 4;
    int N;

    cin >> N;
    for(int i =0; i<N; i++)
    {
        numOfDot += pow(2, i)*(pow(2,i)+1)*2 + pow(4, i);
    }

    cout << numOfDot << endl;
    return 0;
}