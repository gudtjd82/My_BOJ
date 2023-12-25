#include <iostream>
#include <string>

using namespace std;

int main(){
    int a, b, v;
    int day = 0;

    cin >> a >> b >>v;
  
    if((v-b)%(a-b) > 0)
        day = (v-b)/(a-b)+1;
    else
        day = (v-b)/(a-b);
    
    cout << day << endl;    
    return 0;
}