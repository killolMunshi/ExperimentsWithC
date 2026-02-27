#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    struct Test1 {
        int a;
        char b;
    };

    struct Test2 {
        int* a;
        char* b;
    };
    
    struct Test1 t1;
    struct Test1 *t2 = &t1;
	printf("Size of struct Test1 is %zu bytes\n", sizeof(struct Test1));
	printf("Memory address of t1 is %p\n", &t1);
    printf("Memory address of t1.a is %p\n",&(t2->a));
    printf("Memory address of t1.a is %p\n", &(t2->b));

    t1.a = 10;
    t1.b = 'k';
    printf("Value of a %d\n", t1.a);
    printf("Value of b %c\n", t1.b);

    int n;
	printf("Enter the number of structs you want to create: \n");
    scanf("%d", &n);

    // Outer malloc: Allocate the array of structs (each struct gets its own memory block)
    struct Test2* array = (struct Test2*)malloc(n * sizeof(struct Test2));
    if (array == NULL) {
        printf("Memory allocation failed for array!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        // Inner malloc: Allocate memory for the data each pointer points to
        // (This is separate from the struct's own memory)
        array[i].a = (int*)malloc(sizeof(int));
        array[i].b = (char*)malloc(sizeof(char));
        
        if (array[i].a == NULL || array[i].b == NULL) {
            printf("Memory allocation failed for pointers in struct %d!\n", i);
            // In a real program, free previously allocated memory here
            return 1;
        }
        
        // Assign values to the allocated memory
        *array[i].a = t2->a + i;  // Increment based on t1.a
        *array[i].b = 'A' + i;    // Unique char for each struct
        
        printf("Struct number %d and values in it are %d and %c\n", i, *(array[i].a), *(array[i].b));
        
        // Optional: Print addresses to show they're separate
        printf("  Struct %d address: %p\n", i, &array[i]);
        printf("  array[%d].a points to: %p\n", i, array[i].a);
        printf("  array[%d].b points to: %p\n", i, array[i].b);
    }

    // Cleanup: Free inner allocations first, then the array
    for (int i = 0; i < n; i++) {
        free(array[i].a);
        free(array[i].b);
    }
    free(array);

    // Now add the linked list implementation
    printf("\n--- Linked List Implementation ---\n");
    
    // Define the linked list node structure
    struct Node {
        int data;
        struct Node* next;
    };
    
    // Create the head of the linked list
    struct Node* head = NULL;
    struct Node* current = NULL;
    
    // Create 5 nodes with integer data
    for (int i = 1; i <= 5; i++) {
        // Allocate memory for new node
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        
        // Set data and next pointer
        newNode->data = i * 10;  // Store multiples of 10: 10, 20, 30, 40, 50
        newNode->next = NULL;
        
        // Link the node to the list
        if (head == NULL) {
            // First node becomes head
            head = newNode;
            current = head;
        } else {
            // Append to the end
            current->next = newNode;
            current = newNode;
        }
    }
    
    // Traverse and print the linked list
    printf("Linked List Contents:\n");
    current = head;
    while (current != NULL) {
        printf("Data: %d\n", current->data);
        current = current->next;
    }
    
    // Free the allocated memory
    current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}