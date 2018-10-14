/* Insertion sort ascending order */

#include <stdio.h>

int main()
{
	int n, array[1000], d, t;     // d and t are temporary variables which will be used to sort the array

	printf("Enter number of elements\n");
	scanf("%d", &n);

	printf("Enter %d integers\n", n);

	for (int c = 0; c < n; c++)   
		scanf("%d", &array[c]);  // taking elements of the array as input

	for (int c = 1; c <= n - 1; c++) {
		d = c;

		while (d > 0 && array[d - 1] > array[d]) { // shifting the elements which are greater than the dth element to the right
			t = array[d];
			array[d] = array[d - 1];
			array[d - 1] = t;

			d--;
		}
	}

	printf("Sorted list in ascending order:\n");

	for (int c = 0; c <= n - 1; c++) {
		printf("%d\n", array[c]); // outputs sorted array
	}

	return 0;
}