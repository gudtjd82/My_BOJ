#include <iostream>
#include <string>
#include <set>
#include <stack>

using namespace std;

template <typename T>
// 차집합 함수
set<T> diffOfSets(set<T> a, set<T> b)
{
    set<T> diff;
    for(const auto& elem : a)
        {
            if(b.count(elem) == 0)
            {
                diff.insert(elem);
            }
        }
    
    return diff;
}
// 교집합 함수
set


class Node
{
private:
    int num;
    set<int> possible_nums;
    int count = 0;
    int row;
    int col;
    int box;
public:
    Node(){
        this->num = 0;
        this->row = 0;
        this->col = 0;
        this->box = 0;
    }
    Node(int _num, int _row, int _col, int _box)
    {
    this->num = _num;
    this->row = _row;
    this->col = _col;
    this->box = _box;
    }
    ~Node(){}

    void print_node()
    {
        cout << this->num;
    }
    
    void del_possNum(int possNum)
    {
        auto it = this->possible_nums.find(possNum);
        if(it != this->possible_nums.end())
        {
            this->possible_nums.erase(it);
            this->count--;
        }
    }

    void del_possNums(set<int> possNums)
    {
        for(const auto& elem : possNums)
        {
            this->del_possNum(elem);
        }
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
    int get_box(){
        return this->box;
    }
    set<int> get_possibleNums(){
        return this->possible_nums;
    }
    int get_count(){
        return this->count;
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
    void set_box(int _box){
        this->box = _box;
    }
    void set_possibleNums(set<int> nums)
    {
        this->possible_nums = nums;
        this->count = nums.size();
    }
};


int main(){
    Node sudoku[9][9];
    set<int> col[9], row[9], box[9];
    stack<Node*> col_pos[9], row_pos[9], box_pos[9];

    set<int> diff, all_num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numOFBlank = 0;
    int n;
    int r, c, b;
    Node *temp_sq;

    // sudoku 생성
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

    // box 배열 생성
    Node* boxes[9][9];
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j<9; j++)
        {
            r = (i/3)*3 + (j/3);
            c = (i%3)*3 + (j%3);

            boxes[i][j] = &sudoku[r][c];
            sudoku[r][c].set_box(i);
        }
    } 

    // box 출력
    /*
    for(int i = 0; i<9; i++)
    {
        cout << endl;
        cout << i+1 << " 번 Box: " << endl;
        for(int j = 0; j<9; j++)
        {
            cout << boxes[i][j]->get_num() << " ";
            if(j%3 == 2)
                cout << endl;
        }
        cout << "--------------------" << endl;
    }
    return 0;
    */

    // 각각의 row, col, box에 있는 숫자 집합
    for(int i = 0; i <9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            // row
            temp_sq = &sudoku[i][j];
            if(temp_sq->get_num() != 0)
            {
                row[i].insert(temp_sq->get_num());
            }
            else if(temp_sq->get_num() == 0)
            {
                row_pos[i].push(temp_sq);
            }

            // col
            temp_sq = &sudoku[j][i];
            if(temp_sq->get_num() != 0)
            {
                col[i].insert(temp_sq->get_num());
            }
            else if(temp_sq->get_num() == 0)
            {
                col_pos[i].push(temp_sq);
            }

            // box
            temp_sq = boxes[i][j];
            if(temp_sq->get_num() != 0)
            {
                box[i].insert(temp_sq->get_num());
            }
            else if(temp_sq->get_num() == 0)
            {
                box_pos[i].push(temp_sq);
            }
        }
    }

    // 채워야 되는 수 저장
    for(int i =0; i<9; i++)
    {
        for(int j = 0; j<9; j++)
        {
            r = i;
            c = j;
            temp_sq = &sudoku[r][c];
            b = temp_sq->get_box();

            if(temp_sq->get_num() == 0)
            {
                diff = diffOfSets(all_num, box[b]);
                diff = diffOfSets(diff, row[r]);
                diff = diffOfSets(diff, col[c]);

                sudoku[r][c].set_possibleNums(diff);
                
                diff.clear();
            }

        }
    }

    // possible nums 출력
    /*
    cout << "----------------------" << endl;
    for(int i = 0; i <9; i++)
    {
        for(int j = 0; j<9; j++)
        {
            temp_sq = &sudoku[i][j];

            if(temp_sq->get_num() == 0)
            {
                cout << "(" << i+1 << ", " << j+1 <<") =>";
                for(const auto& elem : temp_sq->get_possibleNums())
                {
                    cout << " " <<  elem;
                }
                cout << endl;
            }
        }
    }
    return 0;
    */


    // 빈칸이 하나인 것 채우기
    bool check_change = true;
    Node* temp_node = NULL;
    int insert_num = 0;
    r = -1, c = -1, b = -1;
    while(check_change)
    {
        check_change = false;

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j<9; j++)
            {
                r = i;
                c = j;
                temp_sq = &sudoku[r][c];
                b = temp_sq->get_box();
                
                if(temp_sq->get_num() == 0 && temp_sq->get_count() == 1)
                {
                    int poss_num = *(temp_sq->get_possibleNums().begin());
                    temp_sq->set_num(poss_num);

                    for(int k = 0; k < 9; k++)
                    {
                        sudoku[r][k].del_possNum(poss_num);
                        if(k != r && k != c)
                            sudoku[k][c].del_possNum(poss_num);
                        if(boxes[b][k] != &sudoku[r][k] || boxes[b][k] != &sudoku[k][c])
                            boxes[b][k]->del_possNum(poss_num);
                    }
                    check_change = true;
                }


            }
        }


        // row
        /*
        for(int i = 0; i < 9; i++)
        {
            if(row[i].size() == 1)
            {
                temp_node = row_pos[i].top();
                if(temp_node->get_num() == 0)
                {  
                    insert_num = *(row[i].begin());
                    temp_node->set_num(insert_num);
                    // cout << temp_node->get_row() << ", " << temp_node->get_col() << ", " << insert_num << endl;

                    // 해당 숫자 col, box에서도 삭제
                    c = temp_node->get_col();
                    b = temp_node->get_box();
                    auto it_c = col[c].find(insert_num);
                    auto it_b = box[b].find(insert_num);
                    if(it_c != col[c].end())
                        col[c].erase(it_c);
                    if(it_b != box[b].end())
                        box[b].erase(it_b);

                    row_pos[i].pop();
                    row[i].clear();
                    check_empty = false;
                }
                temp_node = NULL;
            }

            // col
            if(col[i].size() == 1)
            {
                temp_node = col_pos[i].top();
                if(temp_node->get_num() == 0)
                {
                    insert_num = *(col[i].begin());
                    // cout << temp_node->get_row() << ", " << temp_node->get_col() << ", " << insert_num << endl;
                    temp_node->set_num(insert_num);

                    r = temp_node->get_row();
                    b = temp_node->get_box();
                    auto it_r = row[r].find(insert_num);
                    auto it_b = box[b].find(insert_num);
                    if(it_r != row[r].end())
                        row[r].erase(it_r);
                    if(it_b != box[b].end())
                        box[b].erase(it_b);

                    col_pos[i].pop();
                    col[i].clear();
                    check_empty = false;
                }
            }

            // box
            if(box[i].size() == 1)
            {
                temp_node = box_pos[i].top();
                if(temp_node->get_num() == 0)
                {
                    insert_num = *(box[i].begin());
                    // cout << temp_node->get_row() << ", " << temp_node->get_col() << ", " << insert_num << endl;
                    temp_node->set_num(insert_num);

                    r = temp_node->get_row();
                    c = temp_node->get_col();
                    auto it_r = row[r].find(insert_num);
                    auto it_c = col[c].find(insert_num);
                    if(it_r != row[r].end())
                        row[r].erase(it_r);
                    if(it_c != col[c].end())
                        col[c].erase(it_c);

                    box_pos[i].pop();
                    box[i].clear();
                    check_empty = false;
                }
            }
        }
        */
    }

    cout << "----------------------" << endl;
    for(int i = 0; i <9; i++)
    {
        for(int j = 0; j<9; j++)
        {
            temp_sq = &sudoku[i][j];

            if(temp_sq->get_num() == 0)
            {
                cout << "(" << i+1 << ", " << j+1 <<") =>";
                for(const auto& elem : temp_sq->get_possibleNums())
                {
                    cout << " " <<  elem;
                }
                cout << endl;
            }
        }
    }
    return 0;



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