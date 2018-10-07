#include <stdio.h>


int main(void){
    
    int a[]={1,2,4,5,6,8,9,12,18,22,24,29,31,37,41,44,45};     	        // take sorted array 
    int search, mid, len, flag=0;              				// search is element to be searched, flag is to be set when element is found 
   
    printf("Enter element to search in array: "); 
    scanf("%d", &search); 

    len = sizeof(a)/sizeof(a[0]);              				// find number of elements in the array 

    for(int i=0; i<len; ){
        mid = (i+len)/2;                   				// find middle index of array 
        if(search == a[mid]){                  				// If element at mid is our element set flag to 1 and we found our element in array 
            flag = 1;  
            break; 
        }
        else if(search < a[mid]){             				// if search is less than element at mid then it is in left half of the array 
            len = mid;                         				// therefore search in that half and set n = mid , so we search from leftmost index to mid 
        }
        else{                                  				// if number is greater than element at mid then search is right half of array and start search from 
            i = mid +1;                       			 	// mid+1 to rightmost index. 
        }
    }
    if(flag==1){
        printf("Element found at index %d\n", mid);
    }
    else{
        printf("Element not found !!\n");
    }
    return 0;
}
