#include <stdio.h>
#include <stdlib.h>

// Struct where all members are pointers instead of direct values
// This demonstrates how to work with pointer-based struct members
struct PointerStruct {
    int* intPtr;        // Pointer to an integer
    char* charPtr;      // Pointer to a character (or string)
    float* floatPtr;    // Pointer to a float
    double* doublePtr;  // Pointer to a double
};

int main(int argc, char* argv[]) {
    // Declare variables to point to
    int num = 42;
    char letter = 'A';
    float pi = 3.14159f;
    double euler = 2.71828;
    
    // Declare the struct
    struct PointerStruct ps;
    
    // Assign addresses to the pointer members
    ps.intPtr = &num;
    ps.charPtr = &letter;
    ps.floatPtr = &pi;
    ps.doublePtr = &euler;
    
    // Access the values through the pointers
    printf("Integer: %d\n", *ps.intPtr);
    printf("Character: %c\n", *ps.charPtr);
    printf("Float: %.5f\n", *ps.floatPtr);
    printf("Double: %.5f\n", *ps.doublePtr);
    
    // Demonstrate modifying values through pointers
    *ps.intPtr = 100;
    *ps.charPtr = 'Z';
    
    printf("\nAfter modification:\n");
    printf("Integer: %d\n", *ps.intPtr);
    printf("Character: %c\n", *ps.charPtr);
    
    return 0;
}