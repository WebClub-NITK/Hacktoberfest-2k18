#include<stdio.h>
#include<conio.h>
# define max 50
int main()
{
    int i= 0;
    char ch,passwd[max];
    while((ch=getch())!='\n') //Use '\r' if it does not work
    {
        ch = passwd[i];  
        printf("*");
        i++;
    }
    passwd[i]='\0';
    cout<<"\nPassword is ";
    puts(passwd);
    getch();
    
}

