#include<iostream>
#include<algorithm>         
using namespace std;


void nextNum(char num[],int size) 
{
	int i,j;
	for(i=size-1;i>0;i--)	
	{
		if(num[i-1]<num[i])  
		    break;
	}
	
	if(i==0)            
	{
		cout<<"No number greater number possible";
		return;
	}
	int x=num[i-1],smaller=i;
	for(j=i+1;j<size;j++)
	{
		if(num[j]>x && num[j]<num[smaller])  
		{
			smaller=j;
		}
	}
	swap(num[smaller],num[i-1]);    
	sort(num+i,num+size);            
	for(int i=0;i<size;i++)
	{
		cout<<num[i];
	}
	return ;
}

int main()
{
	int n;
	cout<<"Enter the number of digits :";
	cin>>n;
	char number[n];
	cout<<"Enter the number :";
	for(int i=0;i<n;i++)
	{
		cin>>number[i];
	}
	nextNum(number,n);
	return 0;
}