#include<iostream>
using namespace std;
int minval(int *A, int n) {
int curr_min=A[0];

for (int i=0; i<n; i++)
if (A[i] < curr_min)
curr_min = A[i];
return curr_min;
}


int main()
{
  int n;
  cout<<"Number of elements in the array?"<<endl;
  cin>>n;
  int A[n];
  for(int i=0;i<n;i++)
  cin>>A[i];
  cout<<"the least value in the array is "<<minval(A,n);
  return 0;
}
