/*
To compile this code:

Run "g++ naveen.cpp"

Execute by typing "./a.out"
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int minval(int *A, int n) {
    
    int curr_min=A[0];

    for (int i=0; i<n; i++)
        if (A[i] < curr_min)
            curr_min = A[i];
    return curr_min;
}

int main(){
    int A[MAX];
    
    int n;
    cout<<"Please Enter N\n";
    cin>>n;

    cout<<"Please Enter the elements of the array\n";
    
    for(int iterator=0;iterator<n;iterator++){
        cin>>A[iterator];
    }

    cout<<"Please note that the minimum element from the array is:\n";
    
    cout<<minval(A,n);
}

/*

Test case 1 :

Please Enter N
5
Please Enter the elements of the array
1 2 3 4 5
Please note that the minimum element from the array is:
1

Test case 2 :

Please Enter N
6
Please Enter the elements of the array
4 2 7 4 2 6
Please note that the minimum element from the array is:
2

*/