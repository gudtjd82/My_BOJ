#include <iostream>
#include <string>
#include <vector>

using namespace std;

string make_str(int n)
{
    string str = "";
    int size = 1;
    for(int i = 0 ; i < n; i++)
    {
        size *= 3;
    }
    for(int i = 0; i < size; i++)
        str.append("-");

    return str;
}

string get_cantorianSet(string str, int p, int s)
{
    int part_size = (s-p+1) / 3;
    int q = p + part_size - 1;  // p ~ q
    int r = q + part_size;      // (q+1) ~ r, (r+1) ~ s

    for(int i = q+1; i <= r; i++)
    {
        str[i] = ' ';
    }

    if(part_size > 1)
    {
        str = get_cantorianSet(str, p, q);
        str = get_cantorianSet(str, r+1, s);
    }
    return str;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string str, result;

    while (cin >> n)
    {
        str = make_str(n);
        
        result = get_cantorianSet(str, 0, str.length()-1);
        cout << result << "\n";
    }
    
    
    return 0;
}