
#include<stdio.h>
#include<string.h>
int main()
{
int l,i,s;
char a[100];
printf("Enter the string:\n");
gets(a);
printf("enter the shift value:\n");
scanf("%d",&s);
l=strlen(a);
for(i=0;i<l;i++)
{
if(a[i]<='z'&&a[i]>='a')
a[i]=((a[i]+s)%('z'+1));
else if(a[i]<='Z'&&a[i]>='A')
a[i]=((a[i]+s)%('Z'+1));
}
//puts(a);
for(i=0;i<l;i++)
printf("%c",a[i]);
return 0;
}
