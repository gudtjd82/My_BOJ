#include <iostream>
#include <string>

using namespace std;

int main(){
    int a = -1, b = -1;
    string result;

    while(true)
    {
        cin >> a >> b;
        if(a == 0 && b == 0)
            break;

        else if(b%a == 0)
            result = "factor";
        else if(a%b == 0)
            result = "multiple";
        else
            result = "neither";
        
        cout << result << endl;
    }
    return 0;
}