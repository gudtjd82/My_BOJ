#include <iostream>
#include <string>
#include <set>
#include <stack>

using namespace std;

// 차집합 함수
template <typename T>
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
template <typename T>
set<T> intersecOfSets(set<T> a, set<T> b)
{
    set<T> common;
    for(const auto& elem : a)
    {
        if(b.count(elem) > 0)
        {
            common.insert(elem);
        }
    }

    return common;
}

// 합집합 함수
template <typename T>
set<T> combiOfSets(set<T> a, set<T> b)
{
    set<T> combi = b;
    for(const auto& elem : a)
    {
        if(b.count(elem) == 0)
        {
            combi.insert(elem);
        }
    }

    return combi;
}

class Node
{
private:
    int num;
    int row;
    int col;
    int box;
    set<int> possible_nums;
    int count = 0;
    set<int> inter_row;
    set<int> inter_col;
    set<int> inter_box;
public:
    Node(){
        this->num = 0;
        this->row = 0;
        this->col = 0;
        this->box = 0;
        this->possible_nums.clear();
        this->inter_row.clear();
        this->inter_col.clear();
        this->inter_box.clear();
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
    set<int> get_inter_row()
    {
        return this->inter_row;
    }
    set<int> get_inter_col()
    {
        return this->inter_col;
    }
    set<int> get_inter_box()
    {
        return this->inter_box;
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
    void set_inter_row(set<int> inter_row)
    {
        this->inter_row = inter_row;
    }
    void set_inter_col(set<int> inter_col)
    {
        this->inter_col = inter_col;
    }
    void set_inter_box(set<int> inter_box)
    {
        this->inter_box = inter_box;
    }
};

// sudoku 숫자 설정
void set_sq(Node sudoku[9][9], Node* boxes[9][9], Node* sq, int num)
{
    int r = sq->get_row();
    int c = sq->get_col();
    int b = sq->get_box();
    int poss_num = num;
    sq->set_num(poss_num);

    for(int k = 0; k < 9; k++)
    {
        sudoku[r][k].del_possNum(poss_num);
        sudoku[k][c].del_possNum(poss_num);
        boxes[b][k]->del_possNum(poss_num);
    }
}

int main(){
    Node sudoku[9][9];
    set<int> col[9], row[9], box[9];
    stack<Node*> col_pos[9], row_pos[9], box_pos[9];

    set<int> diff, all_num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numOFBlank = 0;
    int n;
    int r, c, b;
    Node* temp_sq;

    char next;

    // sudoku 생성
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            std::cin >> n;
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
    // cout << "----------------------" << endl;
    // for(int i = 0; i <9; i++)
    // {
    //     for(int j = 0; j<9; j++)
    //     {
    //         temp_sq = &sudoku[i][j];

    //         if(temp_sq->get_num() == 0)
    //         {
    //             cout << "(" << i+1 << ", " << j+1 <<") =>";
    //             for(const auto& elem : temp_sq->get_possibleNums())
    //             {
    //                 cout << " " <<  elem;
    //             }
    //             cout << endl;
    //         }
    //     }
    // }
    // cout << "----------------------" << endl;
    // return 0;


    bool check_change = true;
    bool check_blank = true;
    bool check_common = false;
    set<int> inter_row;
    set<int> inter_col;
    set<int> inter_box;
    r = -1, c = -1, b = -1;
    while(check_blank)
    {
        check_blank = false;
        if(check_change)
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
                    
                    if(temp_sq->get_num() == 0)
                        check_blank = true;
                    
                    if(temp_sq->get_num() == 0 && temp_sq->get_count() == 1)
                    {
                        set_sq(sudoku, boxes, temp_sq, *(temp_sq->get_possibleNums().begin()));
                        check_change = true;
                    }

                    if(temp_sq->get_num() == 0)
                    {
                        Node* temp_sq2;
                        
                        set<int> diff_row = temp_sq->get_possibleNums();
                        set<int> diff_col = temp_sq->get_possibleNums();
                        set<int> diff_box = temp_sq->get_possibleNums();

                        // 같은 row OR col OR box에 있는 칸과 비교
                        for(int k = 0; k<9; k++)
                        {
                            // row
                            temp_sq2 = &sudoku[r][k];
                            if(k != c && temp_sq2->get_num() == 0)
                            {
                                diff_row = diffOfSets(diff_row, temp_sq2->get_possibleNums());
                            }
                            // col
                            temp_sq2 = &sudoku[k][c];
                            if(k != r && temp_sq2->get_num() == 0)
                            {
                                diff_col = diffOfSets(diff_col, temp_sq2->get_possibleNums());
                            }
                            // box
                            temp_sq2 = boxes[b][k];
                            if(temp_sq2 != temp_sq && temp_sq2->get_num() == 0)
                            {
                                diff_box = diffOfSets(diff_box, temp_sq2->get_possibleNums());
                            }
                        }

                        // cout << "sudoku[" << r << "][" << c << "]:";
                        // for(const auto& elem : temp_sq->get_inter_row())
                        // {
                        //     cout << elem << ", ";
                        // }
                        // cout << endl;

                        if(diff_row.size() == 1)
                        {
                            set_sq(sudoku, boxes, temp_sq, *(diff_row.begin()));
                            check_change = true;
                        }
                        else if(diff_col.size() == 1)
                        {
                            set_sq(sudoku, boxes, temp_sq, *(diff_col.begin()));
                            check_change = true;
                        }
                        else if(diff_box.size() == 1)
                        {
                            set_sq(sudoku, boxes, temp_sq, *(diff_box.begin()));
                            check_change = true;
                        }
                    }
                }
                // cin >> next;
                
                if(true)
                {
                    cout << "------------------------" << endl;
                    for(int k = 0; k<9; k++)
                    {
                        for(int j = 0; j <9; j++)
                        {
                            sudoku[k][j].print_node();
                            cout << ' ';
                        }
                        cout << endl;
                    }
                    cout << "----------------------" << endl;
                    for(int k = 0; k <9; k++)
                    {
                        for(int j = 0; j<9; j++)
                        {
                            temp_sq = &sudoku[k][j];

                            if(temp_sq->get_num() == 0)
                            {
                                cout << "(" << k+1 << ", " << j+1 <<") =>";
                                for(const auto& elem : temp_sq->get_possibleNums())
                                {
                                    cout << " " <<  elem;
                                }
                                cout << endl;
                            }
                        }
                    }
                    cout << "----------------------" << endl;
                    
                    std::cin >> next;
                }
            }
        }

        if(!check_change)
        {
            Node* temp_sq2;
            for(int i = 0; i <  9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    r = i;
                    c = j;
                    temp_sq = &sudoku[r][c];
                    b = temp_sq->get_box();

                    if(temp_sq->get_num() == 0)
                    {
                        check_blank = true;
                        inter_row = temp_sq->get_possibleNums();
                        inter_col = temp_sq->get_possibleNums();
                        inter_box = temp_sq->get_possibleNums();

                        for(int k = 0; k < 9; k++)
                        {
                            temp_sq2 = &sudoku[r][k];
                            if(k != c && temp_sq2->get_num() == 0)
                            {
                                inter_row = intersecOfSets(inter_row, temp_sq2->get_possibleNums());
                                temp_sq->set_inter_row(inter_row);
                            }

                            temp_sq2 = &sudoku[k][c];
                            if(k != r && temp_sq2->get_num() == 0)
                            {
                                inter_col = intersecOfSets(inter_col, temp_sq2->get_possibleNums());
                                temp_sq->set_inter_col(inter_col);
                            }

                            temp_sq2 = boxes[b][k];
                            if(temp_sq2 != temp_sq && temp_sq2->get_num() == 0)
                            {
                                inter_box = intersecOfSets(inter_box, temp_sq2->get_possibleNums());
                                temp_sq->set_inter_box(inter_box);
                            }
                        }

                        set<int> valid_nums_row = diffOfSets(temp_sq->get_possibleNums(), inter_row);
                        set<int> valid_nums_col = diffOfSets(temp_sq->get_possibleNums(), inter_col);
                        set<int> valid_nums_box = diffOfSets(temp_sq->get_possibleNums(), inter_box);

                        set<int> common_valid = intersecOfSets(valid_nums_row, valid_nums_col);
                        common_valid = intersecOfSets(common_valid, valid_nums_box);

                        check_common = false;
                        if(common_valid.size() == 1)
                        {
                            cout << "sudoku[" << r << "][" << c << "]:";
                            cout << " valid의 교집합 과정" << endl;

                            cout << "   =>";
                            for(const auto& elem : common_valid)
                            {
                                cout << " " << elem;
                            }
                            cout << endl;

                            check_common = true;
                            set_sq(sudoku, boxes, temp_sq, *(common_valid.begin()));
                            check_change = true;
                        }

                        /*
                        if(valid_nums_row.size() > 0)
                        {
                            set_sq(sudoku, boxes, temp_sq, *(valid_nums_row.begin()));
                            check_change = true;
                        }
                        else if(valid_nums_col.size() > 0)
                        {
                            set_sq(sudoku, boxes, temp_sq, *(valid_nums_col.begin()));
                            check_change = true;
                        }
                        else if(valid_nums_box.size() > 0)
                        {
                            set_sq(sudoku, boxes, temp_sq, *(valid_nums_box.begin()));
                            check_change = true;
                        }
                        else{
                            set_sq(sudoku, boxes, temp_sq, *(temp_sq->get_possibleNums().begin()));
                            check_change = true;
                        }
                        */
                    }
                }
                if(true)
                {
                    cout << "------------------------" << endl;
                    for(int k = 0; k<9; k++)
                    {
                        for(int j = 0; j <9; j++)
                        {
                            sudoku[k][j].print_node();
                            cout << ' ';
                        }
                        cout << endl;
                    }
                    cout << "----------------------" << endl;
                    for(int k = 0; k <9; k++)
                    {
                        for(int j = 0; j<9; j++)
                        {
                            temp_sq = &sudoku[k][j];

                            if(temp_sq->get_num() == 0)
                            {
                                cout << "(" << k+1 << ", " << j+1 <<") =>";
                                for(const auto& elem : temp_sq->get_possibleNums())
                                {
                                    cout << " " <<  elem;
                                }
                                cout << endl;
                            }
                        }
                    }
                    cout << "----------------------" << endl;
                    char next;
                    std::cin >> next;
                }
            }
        }

        if(!check_change && !check_common)
        {
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j <9; j++)
                {
                    if(temp_sq->get_num() == 0)
                    {
                        check_blank = true;

                        set<int> valid_nums_row = diffOfSets(temp_sq->get_possibleNums(), temp_sq->get_inter_row());
                        set<int> valid_nums_col = diffOfSets(temp_sq->get_possibleNums(), temp_sq->get_inter_col());
                        set<int> valid_nums_box = diffOfSets(temp_sq->get_possibleNums(), temp_sq->get_inter_box());

                        set<int> combi_valid = combiOfSets(valid_nums_row, valid_nums_col);
                        combi_valid = combiOfSets(combi_valid, valid_nums_box);
                        
                        if(combi_valid.size() > 0)
                        {
                            cout << "sudoku[" << r << "][" << c << "]:";
                            cout << " valid의 합집합 과정" << endl;
                            set_sq(sudoku, boxes, temp_sq, *(combi_valid.begin()));
                            check_change = true;
                        }
                    }
                }
                if(true)
                {
                    cout << "------------------------" << endl;
                    for(int k = 0; k<9; k++)
                    {
                        for(int j = 0; j <9; j++)
                        {
                            sudoku[k][j].print_node();
                            cout << ' ';
                        }
                        cout << endl;
                    }
                    cout << "----------------------" << endl;
                    for(int k = 0; k <9; k++)
                    {
                        for(int j = 0; j<9; j++)
                        {
                            temp_sq = &sudoku[k][j];

                            if(temp_sq->get_num() == 0)
                            {
                                cout << "(" << k+1 << ", " << j+1 <<") =>";
                                for(const auto& elem : temp_sq->get_possibleNums())
                                {
                                    cout << " " <<  elem;
                                }
                                cout << endl;
                            }
                        }
                    }
                    cout << "----------------------" << endl;
                    char next;
                    std::cin >> next;
                }
            }
        }

        
    }

    // cout << "------------------------" << endl;
    for(int i = 0; i<9; i++)
    {
        for(int j = 0; j <9; j++)
        {
            sudoku[i][j].print_node();
            if(j != 8)
                cout << ' ';
        }
        cout << endl;
    }
    // possible nums 출력
    // cout << "----------------------" << endl;
    // for(int i = 0; i <9; i++)
    // {
    //     for(int j = 0; j<9; j++)
    //     {
    //         temp_sq = &sudoku[i][j];

    //         if(temp_sq->get_num() == 0)
    //         {
    //             cout << "(" << i+1 << ", " << j+1 <<") =>";
    //             for(const auto& elem : temp_sq->get_possibleNums())
    //             {
    //                 cout << " " <<  elem;
    //             }
    //             cout << endl;
    //         }
    //     }
    // }
    return 0;
}