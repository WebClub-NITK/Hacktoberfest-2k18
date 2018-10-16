#include <stdio.h>
#include <iostream>
using namespace std;
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   bool temp; 
   for (i = 0; i < n-1; i++) 
   { 
     temp = false; 
     for (j = 0; j < n-i-1; j++) 
     { 
        if (arr[j] > arr[j+1]) 
        { 
           swap(&arr[j], &arr[j+1]); 
           temp = true; 
        } 
     } 
     if (temp == false) 
        break; 
   } 
} 

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
} 

int main() 
{ 
    int arr[10],n;
    cout<<"enter size of array:";
    cin>>n;
    cout<<"enter array:\n";
    for(int i=0;i<n;i++)
    	cin>>arr[i];
    bubbleSort(arr, n); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
}
