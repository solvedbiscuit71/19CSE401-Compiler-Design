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

	// Find common prefix
	char prefix[SIZE];
	int k=0;
	i=0, j=0;
	while (rule1[i] == rule2[j] && rule1[i] != '\0' && rule2[j] != '\0') {
		prefix[k++] = rule1[i];
		++i, ++j;
	}
	prefix[k] = '\0';

	// If rule1 == rule2
	printf("---\n");
	if (rule1[i] == '\0' && rule1[i] == '\0') {
		printf("A -> %s\n", prefix);
		return 0;
	}

	// Otherwise
	printf("A -> %sA'\n", prefix);
	if (rule1[i] == '\0') {
		printf("A' -> %s\n", (char*)rule2+j);
	} else if (rule2[i] == '\0') {
		printf("A' -> %s\n", (char*)rule1+i);
	} else {
		printf("A' -> %s|%s\n", (char*)rule1+i, (char*)rule2+j);
	}
	return 0;
}
