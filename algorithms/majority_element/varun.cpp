#include<bits/stdc++.h>
using namespace std;


void majority(int arr[], int n)
{
    int maxCount=0;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
            count++;
        }


        if(count>maxCount)
        {
            maxCount=count;
            index=i;
        }
    }


    if (maxCount>n/2)
       cout<<arr[index]<<endl;

    else
        cout<<"No Majority Element"<<endl;
}

int main()
{
    int a[100],n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    majority(a,n);

    return 0;
}
