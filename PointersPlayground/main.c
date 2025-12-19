#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");
    double x = 8;
    float* y = &x;
	printf("Value of x: %f\n", x);
	printf("pointer address of x is  %p\n", y);
    printf("Value at addess provided by %p is %f", y, *y);
    printf("\n%f", *y + 1);
	printf("\nsize of x in bytes %zu", sizeof(x));
    printf("\nsize of y in bytes %zu", sizeof(y));
    return 0;
}
