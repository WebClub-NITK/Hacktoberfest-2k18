#include<bits/stdc++.h>
#include<ctime>
using namespace std;
long long int get_rand();
bool check_prime(long long int a);
long long int expo(long long int x,long long int y, long long int z);
int main()
{
    long long int g,n;
    cout<<"Enter two prime numbers:\n";
    cout<<"g: ";
    cin>>g;
    cout<<"n: ";
    cin>>n;

    while(!check_prime(g))
    {
        cout<<"g is not prime. Enter a prime number g: ";
        cin>>g;
    }
    while(!check_prime(n))
    {
        cout<<"n is not prime. Enter a prime number n: ";
        cin>>n;
    }
    std::srand(std::time(0));
    long long int a = rand();
    long long int b = rand();

    printf("Random keys chosen by 1 and 2 are: %lld and %lld respectively.\n",a,b);

    long long int A = expo(g,a,n);
    long long int B = expo(g,b,n);

    
    printf("The keys exchanged by 1 and 2 are %lld and %lld respectively.\n",A,B);

    long long int RES1 = expo(A,b,n);
    long long int RES2 = expo(B,a,n);

    printf("The final results are : %lld and %lld \n",RES1,RES2);

    return 0;
}
bool check_prime(long long int a)
{
    int flag=1;
    if(a==1)
        flag=0;
    for(long long int i=2;i<=ceil(sqrt(a));i++)
    {
        if(a%i==0)
        {
            flag=0;
            break;
        }
    }
    return flag;
}
long long int expo(long long int x,long long int y, long long int z)
{
    long long int p = x;
    for(long long int i =0;i<y;i++)
    {
        p*=x;   
        p%=z;
    }
    return p;
}