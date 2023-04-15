#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


int main() {
	char hello[] = "Hello World";
	int* helloPtr = &hello;

	printf("%d\n", *helloPtr);
	return 0;
}
