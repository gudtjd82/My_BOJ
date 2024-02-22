#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int get_mean(vector<int> arr)
{
    int mean = 0;
    for(auto elem: arr)
    {
        mean += elem;
    }

    mean = round((double)mean/(arr.size()));

    return mean;
}
int get_median(vector<int> arr)
{
    int median;
    int idx = arr.size()/2;

    return arr[idx];
}
int get_mode(vector<int> arr)
{
    int cur_cnt = 1, max_cnt = 0;
    vector<int> modes;

    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i-1] == arr[i])
        {
            cur_cnt++;
        }
        else
        {
            if(cur_cnt > max_cnt)
            {
                max_cnt = cur_cnt;
                modes.clear();
                modes.push_back(arr[i-1]);
            }
            else if(cur_cnt == max_cnt)
            {
                modes.push_back(arr[i-1]);
            }
            cur_cnt = 1;
        }
    }
    if(cur_cnt > max_cnt)
        return arr.back();
    else if(cur_cnt == max_cnt)
    {
        modes.push_back(arr.back());
    }
    
    if(modes.size() > 1)
        return modes[1];
    else
        return modes[0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp, max = -4000, min = 4000; 
    int mean, median, mode, range;
    vector<int> arr;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);

        if(temp > max)
            max = temp;
        if(temp < min)
            min = temp;
    }
    sort(arr.begin(), arr.end());

    mean = get_mean(arr);
    median = get_median(arr);
    mode = get_mode(arr);
    range = max - min;

    cout << mean << "\n";
    cout << median << "\n";
    cout << mode << "\n";
    cout << range << "\n";

    return 0;
}