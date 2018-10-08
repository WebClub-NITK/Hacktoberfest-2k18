#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    
    cout<<"\nEnter the number of test cases: \n";
    int t;
    cin>>t;
    while(t--){
 
 
        int n,result,flag=0;
        cout<<"\nEnter the number of elements: \n";
        cin>>n;
        std::unordered_map<int,int> m;
        int num;
 
        cout<<"\nEnter the elements of array: \n";
        for(int i=0;i<n;i++){
            cin>>num;
            m[num]++;
            if(m[num]>n/2){ result=num; flag=1;}
        }
        if(flag){
           cout<<"\nThe Majority element of the array is: \n";
           cout<<result;
        }else
        {
            cout<<"NO Majority Element";
        }
        cout<<"\n";
    }
    return 0;
}