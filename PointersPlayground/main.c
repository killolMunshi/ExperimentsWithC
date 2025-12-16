#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Hello, World!\n");
    int x = 8;
    int* y = &x;
	printf("Value of x: %d\n", x);
	printf("pointer address of x is  %p\n", y);
    printf("Value at addess provided by %p is %d", y, *y);
    printf("\n%d", *y + 1);
    return 0;
}
