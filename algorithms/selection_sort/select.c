#include<stdioh>
#include<stdlib.h>

void main()
{
	int a[10]={0,2,4,3,1},i,j,n=5,temp,min,pos;
	for(i=0;i<n;i++)
	{
	pos = i; 
		for(j=i;j<n;j++)
			if(a[j]<a[pos])
					pos = j;
	temp = a[pos];
	a[pos]=a[i];
	a[i]=temp;
	}
}
