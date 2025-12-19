#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr[5] = { 10, 20, 30, 40, 50 };
    int* ptr = arr;

    printf("\nPointer to the initial Array %p", ptr);
    printf("\nLooping through array using pointer:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d (address: %p)\n", i, *(ptr + i), (ptr + i));
    }

    for (int j = 0; j < 5; j++) {
        printf(" Address of each element in array %d\n", *&arr[j]);
    }

    return 0;
}