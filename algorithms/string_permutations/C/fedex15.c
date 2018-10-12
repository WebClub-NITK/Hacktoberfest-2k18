#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) { 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
}

void permute(char *str, int start, int end) {
   int i; 
   if (start == end) printf("%s\n", str); 
   else { 
       for (i = start; i <= end; i++) { 
          swap((str+start), (str+i)); 
          permute(str, start+1, end); 
          swap((str+start), (str+i));
       } 
   } 
} 

void main(int argc, char* argv[]) {
	if (argc < 2) {
		printf("Usage %s <string>", argv[0]);
	}
	else {
		char* str = argv[1];
		int len = strlen(str);
		int end = len-1;
		
		permute(str, 0, end); 
	}
}
