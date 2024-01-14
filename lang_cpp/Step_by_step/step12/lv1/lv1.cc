#include <iostream>
#include <string>

using namespace std;

int main()
{   
    int n, m;
    int sum = 0;
    int temp = 0;
    int result = 0;

    cin >> n >> m;

    int *arr = new int[n];

    for(int i = 0; i <n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            for(int k = j+1; k < n; k++)
            {
                sum += arr[i] + arr[j] + arr[k];
                if(sum == m)
                {
                    cout << sum << endl;
                    return 0;
                }

                if(sum < m && temp <= sum)
                {
                    temp = sum;
                }
                sum = 0;
            }
        }
    }
    result = temp;

    cout << result << endl;

    return 0;
}