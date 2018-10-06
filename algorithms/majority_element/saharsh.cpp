
/* C++ Program for finding out  
   majority element in an array */
#include <bits/stdc++.h> 
using namespace std; 
  
/* Function to find the candidate for Majority */
int findCandidate(int a[], int size) 
{ 
    int maj_index = 0, count = 1; 
    for (int i = 1; i < size; i++) 
    { 
        if (a[maj_index] == a[i]) 
            count++; 
        else
            count--; 
        if (count == 0) 
        { 
            maj_index = i; 
            count = 1; 
        } 
    } 
    return a[maj_index]; 
} 
  
/* Function to check if the candidate 
   occurs more than n/2 times */
bool isMajority(int a[], int size, int cand) 
{ 
    int count = 0; 
    for (int i = 0; i < size; i++) 
      
    if (a[i] == cand) 
    count++; 
          
    if (count > size/2) 
    return 1; 
      
    else
    return 0; 
} 
  
/* Function to print Majority Element */
void printMajority(int a[], int size) 
{ 
   /* Find the candidate for Majority*/
   int cand = findCandidate(a, size); 
  
   /* Print the candidate if it is Majority*/
   if (isMajority(a, size, cand)) 
   cout << " " << cand << " "; 
     
   else
   cout << "No Majority Element"; 
} 
  
  
/* Driver function to test above functions */
int main() 
{ 
    int n;
    cout<<"Enter the number of elements:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];  
      
    // Function calling 
    printMajority(a,n); 
      
    return 0; 
} 