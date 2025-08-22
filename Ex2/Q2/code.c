#include <stdio.h>

#define SIZE 50

int main() {
	printf("Enter production rules (A -> {rule1}|{rule2}):\n");
	printf("A -> ");

	char buf[SIZE];
	scanf("%s", buf);

	char rule1[SIZE], rule2[SIZE];
	int i=0,j;

	// Extract rule1 and rule2 from buf
	j=0;
	while (buf[i] != '|') rule1[j++] = buf[i++];
	rule1[j] = '\0';
	i++;

	j=0;
	while (buf[i] != '\0') rule2[j++] = buf[i++];
	rule2[j] = '\0';

	if (rule1[0] != 'A' && rule2[0] != 'A') {
		printf("No left recursion\n");
		return 0;
	}

	char *a, *b;
	if (rule1[0] == 'A') {
		b = (char*)rule1+1;
		a = (char*)rule2;
	} else {
		a = (char*)rule1+1;
		b = (char*)rule2;
	}

	printf("A -> %sA'\n", a);
	printf("A' -> %sA'|epsilon\n", b);
}
