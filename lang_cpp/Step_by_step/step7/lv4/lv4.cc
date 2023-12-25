#include <iostream>
#include <string>

using namespace std;

int main(){
    int mat[100][100];
    int n, x, y;
    int area = 0;
    
    for (int i =0; i < 100; i++)
    {
        for (int j = 0; j<100; j++)
        {
            mat[i][j] = 0;
        }
    }
    
    cin >> n;
    
    for(int i =0; i < n; i++)
    {
        cin >> x >> y;
        for(int j = x; j < x+10; j++)
        {
            // cout << "j = " << j << endl;
            for(int k = y; k < y+10; k++)
            {
                // cout << "k = " << k << endl;
                mat[j][k] = 1;
            }
        }
        // cout << "done" << endl;
    }

    for(int i = 0; i<100; i++)
    {
        for(int j = 0; j <100; j++)
        {
            if(mat[i][j] == 1)
                area++;
        }
    }

    cout << area << endl;
    
    return 0;
}
