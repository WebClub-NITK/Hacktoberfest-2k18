#include <iostream>
using namespace std;

int sum(int n)
{
	if (n == 1)
		return 1;
	
	return n+ sum(n - 1);
}
int main()
{
	int n; // number upto which the sum is calculated
	cout << "enter a number" << endl;
	cin >> n;
	int S = sum(n);
	cout << "the sum of all natural numbers upto " << n << " is " << S;
}
