#include <iostream>
#include <string>

using namespace std;

int main(){
    string subject, grade_alph;
    double credit, grade_num;
    double sum_credit = 0;
    double avg_grade = 0;

    // cout 소수점
    cout << fixed;
    cout.precision(6);

    for (int i = 0; i < 20; i++)
    {
        cin >> subject >> credit >> grade_alph;

        if(grade_alph == "A+")
            grade_num = 4.5;
        else if(grade_alph == "A0")
            grade_num = 4.0;
        else if(grade_alph == "B+")
            grade_num = 3.5;
        else if(grade_alph == "B0")
            grade_num = 3.0;
        else if(grade_alph == "C+")
            grade_num = 2.5;
        else if(grade_alph == "C0")
            grade_num = 2.0;
        else if(grade_alph == "D+")
            grade_num = 1.5;
        else if(grade_alph == "D0")
            grade_num = 1.0;
        else if(grade_alph == "F")
            grade_num = 0.0;
        else if(grade_alph == "P")
            continue;
        
        sum_credit += credit;
        avg_grade += credit*grade_num;
    }
    avg_grade = avg_grade/sum_credit;

    cout << avg_grade << endl;

    return 0;
}
