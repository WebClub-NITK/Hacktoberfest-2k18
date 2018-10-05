#include<bits/stdc++.h>
using namespace std;

int a[1000];
map<int ,int>m;
int main()
{
	int n,i;
	cin>>n;
    for(i=0;i<n;i++){
    	cin>>a[i];
    	m[a[i]]++;
    }

    int ans=-1, idx=-1;
    for(auto it : m)
    {
    	if(it.second > ans)
    	{
    		ans = it.second;
    		idx = it.first;
    	}
    }

    if(ans > (n/2))
    	cout<<ans<<endl;
    else
    	cout<<-1<<endl;


}