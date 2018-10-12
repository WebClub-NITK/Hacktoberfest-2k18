#include<bits/stdc++.h>
using namespace std;
 int maj(int * arr, int size)
{
	int count = 0, i, majorityElement;
	for (i = 0 ; i < size ; i++)
	{
	       if (count == 0) {
		   majorityElement = arr[i];
		   count = 1;
		}
		  else
		 {
			if(arr[i] == majorityElement)
				count++;
			else
				count--;
		 }
	}
	  count = 0;
	  for (i = 0; i < size; i++)
      {
		if (arr[i] == majorityElement) 
        {
			count++;
       }
      } 
	    if (count > size/2)
        {
		  return majorityElement;
    	}
 	else return -1;
    
}
int main()
{
int a[10]={2,2,2,2,2,2,3,1,1,9};
int m=maj(a,10);
if(m!=-1)
cout<<"Majority Element :"<<m;
else
cout<<"No Majority Element";
return 0;
}
