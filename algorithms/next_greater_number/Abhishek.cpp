
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
  
// Swap is Utility function to swap two characters in the string
void swap(char *strA, char *strB)
{
    char temp = *strA;
    *strA = *strB;
    *strB = temp;
}
  
//Given a number as a char array strNumber[], 
//This function finds the next greater number.  
//It modifies the same array to store the result as we are using call by reference mechanism 
 
void  findNextNumber(char strNumber[], int nLen)
{
    int i, j;
  
    // Step 1: Start from the right most digit and find the first digit // which is smaller than the digit next to it.
    for (i = nLen-1; i > 0; i--)
        if (strNumber[i] > strNumber[i-1])
           break;
  
    // If no such digit is there, then all digits might be in descending order
    // In this case there is no greater number possible with same set of digits
    if (i==0)
    {
        cout << "Next number is not possible";
        return;
    }
  
    // Step 2: Find the smallest digit on right side of (i-1)'th digit // that is greater than strNumber[i-1]
    int x = strNumber[i-1], nSmallestLoc = i;
    for (j = i+1; j < nLen; j++) if (strNumber[j] > x && strNumber[j] < strNumber[nSmallestLoc])
            nSmallestLoc = j;
  
    // Step 3: Swap the above found smallest digit with number[i-1]
    // using utilit function swap
    swap(&strNumber[nSmallestLoc], &strNumber[i-1]);
  
    // Step 4: Sort the all the digits in strNumber after (i-1) in ascending order
    sort(strNumber + i, strNumber + nLen);
    return;
}
  
// Main Driver program to test function findNextNumber()
int main()
{
    char strNumber[] = "454652";
    cout<<"Next Greater Number with Same Set of Digits";
    cout<<"\nGiven Number is "<<strNumber;
    int nLen = strlen(strNumber);
    findNextNumber(strNumber, nLen);
    cout<<"\nNext greater number is "<<strNumber;   
    return 0;
}