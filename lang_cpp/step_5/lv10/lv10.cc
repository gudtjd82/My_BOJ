#include <iostream>
#include <string>

using namespace std;

int main(){
    string str1, str2;
    int num1, num2;

    cin >> str1 >> str2;

    num1 = 100*(int(str1[2]) - 48) + 10*(int(str1[1]) - 48) + (int(str1[0]) - 48);
    num2 = 100*(int(str2[2]) - 48) + 10*(int(str2[1]) - 48) + (int(str2[0]) - 48);

    if (num1 > num2)
        cout << num1 << endl;
    else
        cout << num2 << endl;

    return 0;
}