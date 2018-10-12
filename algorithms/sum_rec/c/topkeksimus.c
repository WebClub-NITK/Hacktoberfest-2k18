#include <stdio.h>

int sum(int);

int main(){
  int n;
  printf("Enter a natural number\n");
  scanf("%d", &n);
  if(n<=0){
    printf("%d is not a natural number\n", n);
    return 1;
  }
  printf("%d\n",sum(n));
  return 0;
}

int sum(int n){
  if(n==1){return 1;}
  return n+sum(n-1);
}
