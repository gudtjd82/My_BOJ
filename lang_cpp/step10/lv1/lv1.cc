#include <iostream>
#include <string>
#include <set>
#include <stack>

using namespace std;

int main(){
    int sudoku[9][9];
    set<int> col[9], row[9];
    stack<int*> col_pos[9], row_pos[9];
    set<int> diff, all_num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numOFBlank = 0;

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
        }
    }

    for(int i = 0; i <9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            
            // row
            if(sudoku[i][j] != 0)
            {
                row[i].insert(sudoku[i][j]);
            }
            if(sudoku[i][j] == 0)
            {
                row_pos[i].push(&(sudoku[i][j]));
            }
            // col의 빈칸 수
            if(sudoku[j][i] != 0)
            {
                col[i].insert(sudoku[j][i]);
            }
            if(sudoku[j][i] == 0)
            {
                col_pos[i].push(&(sudoku[j][i]));
            }
        }
    }

    for(int i =0; i<9; i++)
    {
        for(const auto& elem : all_num)
        {
            if(row[i].count(elem) == 0)
            {
                diff.insert(elem);
            }
        }
        row[i] = diff;
        diff.clear();

        for(const auto& elem : all_num)
        {
            if(col[i].count(elem) == 0)
            {
                diff.insert(elem);
            }
        }
        col[i] = diff;
        diff.clear();
    }

    for(int i = 0; i < 9; i++)
    {
        if(row[i].size() == 1)
        {
            if(*(row_pos[i].top()) == 0)
            {
                *(row_pos[i].top()) = *(row[i].begin());
                row_pos[i].pop();
                row[i].clear();
            }
            
        }

        if(col[i].size() == 1)
        {
            if(*(col_pos[i].top()) == 0)
            {
                *(col_pos[i].top()) = *(col[i].begin());
                col_pos[i].pop();
                col[i].clear();
            }
        }
    }



    // row col 출력
    /*
    for(int i = 0; i < 9; i ++)
    {
        cout << i+1 << " 번째 row :";
        for(const auto& elem : row[i])
        {
            cout << " " << elem;
        }
        cout << endl;
    }
    for(int i = 0; i < 9; i ++)
    {
        cout << i+1 << " 번째 col :";
        for(const auto& elem : col[i])
        {
            cout << " " << elem;
        }
        cout << endl;
    }
    */

    for(int i = 0; i<9; i++)
    {
        for
    }
    return 0;
}