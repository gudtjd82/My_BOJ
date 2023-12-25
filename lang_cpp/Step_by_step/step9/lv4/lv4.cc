#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    int a;
    int numOfdivs = 0;
    int count = 0;
    
    cin >>n;

    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 1)
        {
            continue;
        }

        for(int j = 2; j*j <= a; j++)
        {
            if(j*j == a)
            {
                numOfdivs++;
                break;
            }
            else if(a % j == 0)
            {
                numOfdivs++;
                break;
            }
        }
        if(numOfdivs == 0)
        {
            count++;
        }
        else{
            numOfdivs = 0;
        }
    }

    cout << count << endl;
    
    return 0;
}