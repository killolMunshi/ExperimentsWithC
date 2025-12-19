#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int arr[5] = { 10, 20, 30, 40, 50 };
    int* ptr = arr;

    printf("\nPointer to the initial Array %p", ptr);
    printf("\nAddress of pointer %p and its size is %zu", *(ptr), sizeof(ptr));
    printf("\nLooping through array using pointer:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d (address: %p)\n", i, *(ptr + i), (ptr + i));
    }

    int (*arrayPtr)[5] = &arr;  // Pointer to array of 5 ints
    printf("Priting the array pointer itself %p", &arr);
    printf("sizeof(*arrayPtr) = %zu\n", sizeof(*arrayPtr));  // 20 bytes

    //for (int j = 0; j < 5; j++) {
    //    printf(" Address of each element in array %d\n", *&arr[j]);
    //}

    return 0;
}