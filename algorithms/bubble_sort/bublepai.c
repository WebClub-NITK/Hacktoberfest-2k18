#include<stdioh>
#include<stdlib.h>

void main()
{
	int a[10]={0,2,4,3,1},i,j,n=5,temp;
	for(i=0;i<n;i++)
		for(j=0;j<n-1-i;j++)
			if(a[j]>a[j+1])
				{
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
}
	
