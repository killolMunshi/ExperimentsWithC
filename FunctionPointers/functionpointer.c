#include <stdio.h>
#include <stdlib.h>

// Function pointers in C allow you to store and pass around references to functions
// just like you would with variables. They're useful for callbacks, polymorphism,
// and implementing strategies or command patterns.

// Simple arithmetic functions to demonstrate function pointers
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    }
    return 0; // Avoid division by zero
}

// Function that takes a function pointer as a parameter
// This demonstrates how function pointers enable dynamic behavior
void perform_operation(int x, int y, int (*operation)(int, int)) {
    // The parameter 'operation' is a pointer to a function that takes two ints and returns an int
    int result = operation(x, y); // Call the function through the pointer
    printf("Result of operation on %d and %d: %d\n", x, y, result);
}

// Function that returns a function pointer
// This shows advanced usage where functions can return other functions
int (*get_operation(char op))(int, int) {
    // Returns a pointer to a function that takes two ints and returns an int
    switch (op) {
        case '+': return add;
        case '-': return subtract;
        case '*': return multiply;
        case '/': return divide;
        default: return add; // Default to addition
    }
}

int main() {
    // Declare a function pointer
    // Syntax: return_type (*pointer_name)(parameter_types)
    int (*func_ptr)(int, int);
    
    // Assign the address of the add function to the pointer
    // Note: You can use &add or just add (both work in C)
    //func_ptr = add;
    //printf("Using function pointer for addition:\n");
    //perform_operation(10, 5, func_ptr);
	//printf("Direct call through function pointer: %d\n", func_ptr(10, 5));
	//printf("Address of add function: %p\n", func_ptr);
    
    // Reassign to different functions dynamically
    //func_ptr = subtract;
    //printf("Using function pointer for subtraction:\n");
    //perform_operation(10, 5, func_ptr);
    
    //func_ptr = multiply;
    //printf("Using function pointer for multiplication:\n");
   // perform_operation(10, 5, func_ptr);
    
    // Array of function pointers
    // This is useful for implementing menus or command systems
    int (*operations[4])(int, int) = {add, subtract, multiply, divide};
    char operators[4] = {'+', '-', '*', '/'};
    
    printf("\nUsing array of function pointers:\n");
    for (int i = 0; i < 4; i++) {
        printf("Operation %c: ", operators[i]);
        perform_operation(20, 4, operations[i]);
    }
    
    // Using the function that returns a function pointer
    printf("\nUsing function that returns a function pointer:\n");
    int (*dynamic_op)(int, int) = get_operation('*');
    perform_operation(15, 3, dynamic_op);
    
    // Direct call through returned function pointer
    printf("Direct call through returned pointer: %d\n", get_operation('+')(7, 3));
    
    return 0;
}