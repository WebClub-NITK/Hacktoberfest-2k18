import java.util.*;
class Bubble
{
public static void main(String args[])
{
int temp=0;
int a[]=new int[100];
Scanner sc=new Scanner(System.in);
System.out.println("Enter number of elements");
int n=sc.nextInt();
  System.out.println("Enter elements");
for(int i=0;i<n;i++)
{
  a[i]=sc.nextInt();
}
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-i-1;j++)
    {
      if(a[j]>a[j+1])
      {
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
    
    System.out.println("printing elements");
for(int i=0;i<n;i++)
{
System.out.println(a[i]);
}
  }
}


