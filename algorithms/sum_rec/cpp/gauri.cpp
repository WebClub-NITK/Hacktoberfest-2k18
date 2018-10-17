#include<bits/stdc++.h>
using namespace std;
int sumnat(int n){
 if(n==1)
  return 1;
 else
  return n+sumnat(n-1);
 }

int main(){
 int S,n;
 cout<<"Enter a natural no.: ";
 cin>>n;
 if(n<1)
 cout<<"Not natural no.";
 else
 { S=sumnat(n);
   cout<<"\nSum of natural no.s till "<<n<<"is "<<S<<"\n";
  }
 return 0;
}
