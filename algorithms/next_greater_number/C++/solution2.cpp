#include <bits/stdc++.h>
using namespace std;

bool nextPermutation(char a[]) {

	int n = strlen(a);
	if(n==1)
		return 0;

	int pos = n-2;
	while(pos >= 0) {
		if(a[pos] < a[pos+1])
			break;
		pos--;
	}

	if(pos == -1)
		return 0;

	int swapPos = pos+1, minval = a[pos+1], t = pos+2;
	while(t < n) {
		if(a[t] > a[pos] && a[t] < minval) {
			swapPos = t;
			minval = a[t];
		}
		t++;
	}

	swap(a[swapPos], a[pos]);
	sort(a+pos+1, a+n);
	return 1;
}

int main() {

	char num[100000];

	cin >> num;
	if(!nextPermutation(num))
		printf("not possible\n");
	else
		printf("%s\n", num);
}

/*

Test Cases
---------------------

Input 1:
1234

Output:
1243

---------------------

Input 2:
4321

Output:
not possible

---------------------

*/
