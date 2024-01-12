#include <iostream>
#include <string>

using namespace std;

bool inSafe(int sudoku[9][9], int row, int col, int num)
{
    for(int i = 0; i < 9; i++)
    {
        if(sudoku[i][col] == num)
            return false;
        if(sudoku[row][i] == num)
            return false;

        int start_row = row/3 * 3;
        int start_col = col/3 * 3;
        if(sudoku[start_row+i/3][start_col+i%3] == num)
            return false;
    }
    return true;
}

bool solveSudoku(int sudoku[9][9])
{   
    for(int r = 0; r < 9; r++)
    {
        for(int c = 0; c <  9; c++)
        {
            if(sudoku[r][c] == 0)
            {
                for(int num = 1; num <= 9; num++)
                {
                    if(inSafe(sudoku, r, c, num))
                    {
                        sudoku[r][c] = num;
                        if(solveSudoku(sudoku))
                        {
                            return true;
                        }
                        sudoku[r][c] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    int sudoku[9][9];

     for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
        }
    }

    if(solveSudoku(sudoku))
    {
        // cout << "-------------------------" << endl;
        for(int i = 0; i<9; i++)
        {
            for(int j = 0; j <9; j++)
            {
                cout << sudoku[i][j];
                if(j != 8)
                    cout << ' ';
            }
            cout << endl;
        }
    }
    else{
        cout << "답이 없습니다." << endl;
    }
    return 0;
}