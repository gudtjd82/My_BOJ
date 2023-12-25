#include <iostream>
#include <string>
#include <set>
#include <stack>

using namespace std;

class Node
{
private:
    int num;
    int row;
    int col;
public:
    Node(){
        this->num = 0;
        this->row = 0;
        this->col = 0;
    }
    Node(int _num, int _row, int _col)
    {
    this->num = _num;
    this->row = _row;
    this->col = _col;
    }
    ~Node(){}

    void print_node()
    {
        cout << this->num;
    }

    int get_num(){
        return this->num;
    }
    int get_row(){
        return this->row;
    }
    int get_col(){
        return this->col;
    }

    void set_num(int _num){
        this->num = _num;
    }
    void set_row(int _row){
        this->row = _row;
    }
    void set_col(int _col){
        this->col = _col;
    }
};

class Box
{
private:
    Node node[9];
    int count = 0;
public:
    Box(){};
    Box(Node _node)
    {
        this->node[count] = _node;
        count++;
    }
    ~Box();
};

class Boxes
{
private:
    Node Box[9];
public:
    Boxes(){}
    Boxes(Node** sudoku)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = i/3; j < i/3+3; j++)
            {
                for(int k = )
            }
        }
    }
    ~Boxes();
};

int main(){
    Node sudoku[9][9];
    set<int> col[9], row[9];
    stack<Node*> col_pos[9], row_pos[9];

    set<int> diff, all_num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numOFBlank = 0;
    int n;
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> n;
            sudoku[i][j].set_num(n);
            sudoku[i][j].set_row(i);
            sudoku[i][j].set_col(j);
        }
    }

    for(int i = 0; i <9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            
            // row
            if(sudoku[i][j].get_num() != 0)
            {
                row[i].insert(sudoku[i][j].get_num());
            }
            if(sudoku[i][j].get_num() == 0)
            {
                row_pos[i].push(&sudoku[i][j]);
            }
            // col
            if(sudoku[j][i].get_num() != 0)
            {
                col[i].insert(sudoku[j][i].get_num());
            }
            if(sudoku[j][i].get_num() == 0)
            {
                col_pos[i].push(&sudoku[j][i]);
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

    /*
    // row col 출력
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

    bool check_empty = false;
    Node* temp_node = NULL;
    int insert_num = 0;
    int j = -1;
    while(!check_empty)
    {
        check_empty = true;

        for(int i = 0; i < 9; i++)
        {
            if(row[i].size() == 1)
            {
                temp_node = row_pos[i].top();
                if(temp_node->get_num() == 0)
                {  
                    insert_num = *(row[i].begin());
                    // cout << "1" << endl;
                    temp_node->set_num(insert_num);
                    cout << temp_node->get_row() << ", " << temp_node->get_col() << ", " << insert_num << endl;
                    // cout << "2" << endl;
                    // 해당 숫자 col에서도 삭제
                    j = temp_node->get_col();
                    auto it = col[j].find(insert_num);
                    if(it != col[j].end())
                        col[j].erase(it);
                    // cout << "3" << endl;
                    row_pos[i].pop();
                    row[i].clear();
                    check_empty = false;
                    // cout << "4" << endl;
                }
                temp_node = NULL;
            }

            if(col[i].size() == 1)
            {
                temp_node = col_pos[i].top();
                if(temp_node->get_num() == 0)
                {
                    insert_num = *(col[i].begin());
                    cout << temp_node->get_row() << ", " << temp_node->get_col() << ", " << insert_num << endl;
                    temp_node->set_num(insert_num);

                    j = temp_node->get_row();
                    auto it = row[j].find(insert_num);
                    if(it != row[j].end())
                        row[j].erase(it);

                    col_pos[i].pop();
                    col[i].clear();
                    check_empty = false;
                }
            }
        }
    }

    cout << "------------------------" << endl;
    for(int i = 0; i<9; i++)
    {
        for(int j = 0; j <9; j++)
        {
            sudoku[i][j].print_node();
            cout << ' ';
        }
        cout << endl;
    }
    return 0;
}