#include<stdio.h>

int natsum(int n)
{
    if(n != 0)
        return n + natsum(n-1);
    else
        return n;
}
int main()
{
  int a;
  printf("Sum till?");
  scanf("%d",&a);
  printf("SUM= %d",natsum(a));
}
  
