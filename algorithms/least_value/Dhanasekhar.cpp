#include<iostream>
using namespace std;
int min(int *A,int n)
{
	int i;
	int cur_min = A[0]; //Error
	for(i=1;i<n;i++)
	{
		if(cur_min > A[i])
			cur_min = A[i];
	} 
	return cur_min;
}
int main()
{
	int A[100],i,n;
	cout<< "Enter the number of elements:";
	cin>>n;
	cout<<"Enter the elements";
	for(i=0;i<n;i++)
		cin>>A[i];
	cout<<min(A,n);
	return 0;
}
