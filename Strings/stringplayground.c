#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char* argv[]) {

	char str1[50] = "Hello, ";
	char str2[] = "World!";
	
	// Concatenate str2 to str1
	strcat(str1, str2);
	printf("Concatenated String: %s\n", str1);
	
	// Find length of the concatenated string
	size_t len = strlen(str1);
	printf("Length of Concatenated String: %zu\n", len);
	
	// Copying strings
	char str3[50];
	strcpy(str3, str1);
	printf("Copied String: %s\n", str3);
	
	// Comparing strings
	int cmp = strcmp(str1, str3);
	if(cmp == 0) {
		printf("str1 and str3 are equal.\n");
	} else {
		printf("str1 and str3 are not equal.\n");
	}


	return 0;
}