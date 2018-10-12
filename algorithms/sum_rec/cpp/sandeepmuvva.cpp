#include<iostream>
using namespace std;

int sum(int n){
	if(n==1)
		return 1;
	else
		return n+sum(n-1);
}
int main(){
	int n;
	cout<<"Enter a natural number:"<<endl;
	cin>>n;
	if(n<=0){
		cout<<n<<" is not a natural number";
	}
	else{
		cout<<sum(n);
	}
	return 0;
}
