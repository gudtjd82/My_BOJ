#include <iostream>
#include <stack>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, temp;
    vector<int> qs;
    deque<int> queues;
    vector<int> elems;
    vector<int> inputs;

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        qs.push_back(temp);
    }
    for(int i =0; i< n; i++)
    {
        cin >> temp;
        if(qs[i] == 0)
            queues.push_back(temp);
    }

    cin >> m;
    for(int i =0; i < m; i++)
    {
        cin >> temp;
        inputs.push_back(temp);
    }

    for(auto input : inputs)
    {
        queues.push_front(input);
        cout << queues.back() << " ";
        queues.pop_back();
    }
    cout << "\n";

    return 0;
}