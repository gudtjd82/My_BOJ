#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int sudoku[9][9];
    stack<int> col[9], row[9];
    int numOFBlank = 0;

    for(int i = 0; i < 9; i++)
    {
        col[i] = 0;
        row[i] = 0;
        for(int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
        }
    }

    for(int i = 0; i <9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            
            // row의 빈칸 수
            if(sudoku[i][j] == 0)
            {
                row[i]++;
            }
            // col의 빈칸 수
            if(sudoku[j][i] == 0)
            {
                col[i]++;
            }
        }

    }

    // 
    return 0;
}