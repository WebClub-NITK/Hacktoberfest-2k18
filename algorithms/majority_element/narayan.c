#include<stdio.h>

void main()
{
    int a[100],i,j,min,n,temp,count=0,count_max=0;
    printf("Enter the number of elements in the array\n");
    scanf("%d",&n);
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    min=0;
    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
          if (a[j] < a[min])
            min = j;
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    for(i=0;i<n-1;i++)
    {
        count=0;
        j=i;
        while(a[j]==a[i])
        {
            j++;
            //i++;
            count++;
        }
        if(count>count_max)
            count_max=count;
    }
    /*for(i=0;i<n;i++)
        printf("%d",a[i]);*/
    if(count_max > n/2)
        printf("There exists a major element\n");
    else
        printf("There exists no major element\n");
}

