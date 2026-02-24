#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

    struct Test1 {
        int a;
        char b;
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

    return 0;
}