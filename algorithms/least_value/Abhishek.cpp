#include<bits/stdc++.h>
using namespace std;

int minval(int *A, int n) {
int curr_min=A[0];

for (int i=1; i<n; i++)
if (A[i] < curr_min)
curr_min = A[i];
return curr_min;
}


int main()
{
int a[11]={1,2,4 ,9,0,5,2,4,1,9,9};
cout<<"Minimum Value:"<<minval(a,11);

return 0;

}