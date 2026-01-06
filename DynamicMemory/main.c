#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int n;
    
    printf("Enter an integer: ");
    //scanf("%d", &n);
    // Read integer input from user
    if (scanf("%d", &n) != 1) {
        printf("Pointer address %p\n", (void*)&n);
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }
    printf("Pointer address %p\n", (void*)&n);
    printf("You entered: %d\n", n);

    int* arr = malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)      {
		printf("Memory address of arr[%d] is %p\n", i, (void*)&arr[i]);
    }
        
    free(arr);
    return 0;
}
