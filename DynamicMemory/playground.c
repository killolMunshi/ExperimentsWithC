#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int n;
	printf("Enter number n \n");
	scanf("%d", &n);
	printf("\n Number entered %d and its memory address %p", n, &n);

	int* myarr = malloc(sizeof(int) * n);
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		*(&myarr[i]) = i;
		printf("\n Memory address of %d element of my myarr is %p", i, &myarr[i]);
		printf("\n Confirming value at memory address %p is %d", &myarr[i], *(&myarr[i]));
		sum = sum + *(&myarr[i]);
	}
	int avg = sum / n;
	printf("\n Sum of the numbers is %d and average is %d", sum, avg);

	return 0;
}
