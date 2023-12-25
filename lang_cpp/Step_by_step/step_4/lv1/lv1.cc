#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    int find_num;
    int result = 0;
    
    // 1st line
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        // 2nd line
        cin >> arr[i];
    }

    // 3rd line
    cin >> find_num;

    for (int j = 0; j < n; j++)
    {
        if (arr[j] == find_num)
            result++;
    }
    
    // result
    cout << result << endl;

    return 0;
}