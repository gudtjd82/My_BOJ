#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int recursion(const char* str, int l, int r, int& n)
{
    n++;
    if(l >= r)
        return 1;
    else if(str[l] != str[r])
        return 0;
    else
        return recursion(str, l+1, r-1, n);
}

int isPalindrome(const char* str, int& n)
{
    return recursion(str, 0, strlen(str)-1, n);
}

int main(){
    int n, temp;

    scanf("%d", &n);

    for(int i =0; i < n; i++)
    {
        char str[1000];
        temp = 0;
        int& rtemp = temp;
        scanf("%s", str);
        int result = isPalindrome(str, rtemp);
        printf("%d %d\n", result, rtemp);
    }
    
    return 0;
}