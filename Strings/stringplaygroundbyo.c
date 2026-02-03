#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int my_strlen(char* str) {
	int length = 0;
	while (str[length] != '\0') {
		length++;
	}
	return length;
}


bool my_strcmp(char* s1, char* s2) {
	int length = 0;
	int l1 = my_strlen(s1);
	int l2 = my_strlen(s2);
	if(l1 != l2) {
		return false;
	}
	while (s1[length] != '\0') {
		if(s1[length] != s2[length]) {
			return false;
		}
		length++;
	}
	return true;
}

char * my_strcpy(char* dest, const char* src) {
	char* originalDest = dest;
	while (*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0'; // Null-terminate the destination string
	return originalDest;
}

int main(int argc, char* argv[]) {

	char* inputString;
	char* inputString2;
	int n = 5;
	
	// Allocate memory for the string
	inputString = (char*)malloc(n * sizeof(char));
	if (inputString == NULL) {
		printf("Memory allocation failed!\n");
		return 1;
	}

	inputString2 = (char*)malloc(n * sizeof(char));
	if (inputString2 == NULL) {
		printf("Memory allocation failed!\n");
		return 1;
	}
	
	printf(" Enter a string of no more than 4 charectars \n");
	scanf("%4s", inputString);
	printf(" You entered: %s \n", inputString);
	printf(" Memory address of inputString is %p \n", (void*)inputString);

	printf(" Enter another string of no more than 4 charectars \n");
	scanf("%4s", inputString2);
	printf(" You entered: %s \n", inputString2);
	printf(" Memory address of inputString2 is %p \n", (void*)inputString2);
	//for (int i = 0; i < n; i++)
	//{
	//	printf("\n Value at position %d is %c",i,inputString[i]);
	//	printf("\n Memory address reserved for the char position is %p", (void*)&inputString[i]);
	//}
	int strlength = my_strlen(inputString);
	printf("Length of the string is: %d\n", strlength);

	printf("Comparing the two strings...\n");
	if (my_strcmp(inputString, inputString2)) {
		printf("The strings are equal.\n");
	} else {
		printf("The strings are not equal.\n");
	}

	printf("Copying the first string to the second string...\n");
	printf("%s\n", my_strcpy(inputString2, inputString));

	free(inputString);
	free(inputString2);
	return 0;
}