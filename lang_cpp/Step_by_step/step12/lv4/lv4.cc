#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, m;
    int min;
    int temp;

    cin >> n >> m;

    char **board = new char*[n];
    for(int i = 0; i < n; i++)
    {
        board[i] = new char[m];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    min = 64;
    for(int i = 0; i <= n-8; i++)
    {
        for(int j = 0; j <= m-8; j++)
        {
            temp = 0;
            for(int y = i; y < i+8; y++)
            {
                for(int x = j; x < j+8; x++)
                {
                    if((i%2 != y%2 && j%2 != x%2) || (i%2 == y%2 && j%2 == x%2))
                    {
                        if(board[i][j] != board[y][x])
                        {
                            temp++;
                        }
                    }

                    else{
                        if(board[i][j] == board[y][x])
                        {
                            temp++;
                        }
                    }
                }
            }

            if(temp <= min)
            {
                min = temp;
            }
        }
    }

    cout << min << endl;


    return 0;
}