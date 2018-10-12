#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


void findNext(char number[], int n)
{
    int i, j;

    for (i = n-1; i > 0; i--)
        if (number[i] > number[i-1])
           break;

    if (i==0)
    {
        cout << "Next number is not possible";
        return;
    }

    int x = number[i-1], smallest = i;
    for (j = i+1; j < n; j++)
        if (number[j] > x && number[j] < number[smallest])
            smallest = j;

    swap(&number[smallest], &number[i-1]);

    sort(number + i, number + n);

    cout << "Next number with same set of digits is " << number;

    return;
}

int main()
{
    string num;
    cin>>num;
    int n = num.length();
    char digits[n+1];
	//string to char array
    strcpy(digits, num.c_str());
    findNext(digits, n);
    return 0;
}

