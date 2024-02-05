#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, num;
    int c[10001] = {0}, max_arr = 0;

    cin >> n;


    for(int i = 0; i < n; i++)
    {
        cin >> num;
        if(max_arr < num)
            max_arr = num;
        c[num]++;
    }
    
    for(int i = 0; i <= max_arr; i++)
    {
        for(int j = 0; j < c[i]; j++)
        {
            cout << i << "\n";
        }
    }
    
    return 0;
}