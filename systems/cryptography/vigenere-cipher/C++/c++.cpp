#include<bits/stdc++.h>
using namespace std;
string encrypt(string s,string key)
{
    long long int s1=s.size();
    long long int s2=key.size(),j=0;
    string res;
    for(long long int i=0;i<s1;i++)
    {
      long long int p=s[i];
      long long int k=key[j%s2];
      j=j+1;
      k=k-97;
      p=p-97;
      long long int r=(p+k)%26;
      r=r+'a';
      res.push_back(r);
    }
    return res;
}
string decrypt(string s,string key)
{
    long long int s1=s.size();
    long long int s2=key.size(),j=0;
    string res;
    for(long long int i=0;i<s1;i++)
    {
      long long int p=s[i];
      long long int k=key[j%s2];
      j=j+1;
      long long int r=(p-k+26)%26+'a';
      res.push_back(r);
    }
    return res;
}
int main()
{
  string s,k;
    cout<<"Please enter the text to be encrypted:-"<<endl;
    cin>>s;
    cout<<"Please enter the KEY:-"<<endl;
    cin>>k;
    string cipher=encrypt(s,k);
    cout<<"The encrypted cipher is:- "<<cipher<<endl;
    cout<<"The decrypted message is:- "<<decrypt(cipher,k)<<endl;
  return 0;
}
