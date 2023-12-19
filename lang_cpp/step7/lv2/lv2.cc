#include <iostream>
#include <string>

using namespace std;

int main(){
    int max, max_col, max_row;
    int **mat;


    mat = new int*[9];
    for(int i =0; i < 9; i++)
        mat[i] = new int[9];

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> mat[i][j];
        }
    }

    max = mat[0][0];
    max_row = 1;
    max_col = 1;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(max < mat[i][j])
            {
                max = mat[i][j];
                max_row = i+1;
                max_col = j+1;
            }
        }
    }

    cout << max << endl;
    cout << max_row <<  " " << max_col << endl;

    return 0;
}
