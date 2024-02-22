#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    queue<int> cards;

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cards.push(i);
    }

    while (cards.size() != 1)
    {
        cards.pop();
        cards.push(cards.front());
        cards.pop();
    }

    cout << cards.front() << "\n";

    return 0;
}