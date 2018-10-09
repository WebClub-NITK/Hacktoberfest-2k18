#include<stdio.h>
#include<string.h>

int sort1(char s[],int n)
{
    char temp;
    int i,j;
    for(i=n;i<strlen(s);i++)
	{
		for(j=i+1;j<strlen(s);j++)
		{
			if(s[i]>s[j])
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
  			}
		}
     }
    return 0;
}

int main() {
    int chk=0;
    char w[100],temp; // assuming max number of digits is 100
    scanf("%s",w);
    int n=strlen(w);
    int j;
    for(j=n;j>=0;j--)
    {
        if(w[j-1]<w[j]&&j!=0)
        {    
            sort1(w,j);
            int k;
            for(k=j;k<strlen(w);k++)
            {
                if(w[j-1]<w[k])
                {
                    temp=w[j-1];
                    w[j-1]=w[k];
                    w[k]=temp;
                    chk=1;
                    goto A;
                }
            }        
        }
     }
    A:
    if(chk==1)
        printf("%s\n",w);
    else
        printf("Not possible\n");
    
    return 0;
}

