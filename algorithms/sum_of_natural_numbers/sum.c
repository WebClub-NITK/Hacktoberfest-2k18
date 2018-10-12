#include<stdio.h>
int findSum(int n)
{
  if(n<=1)
    return n;
  return n+findSum(n-1);
}
void main()
{
  int n;
  printf("Enter the number:");
  scanf("%d",&n);
  int sum=findSum(n);
  printf("Sum of %d natural numbers is %d\n",n,sum);
}
