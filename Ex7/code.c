#include <stdio.h>
#include <string.h>

#define MAX 20
#define SIZE 100

/*
 * int strcmp(char* s1, char* s2) : compare two strings
 * char* strchr(char* s, char c) : find the first occurence of character in string, return pointer
 */

char expr[MAX][SIZE];

int main() {
	int n;
    printf("Enter Num. of Expression(1-20): ");
    scanf("%d", &n);

	if (n > MAX) {
		printf("Maximum supported expression is 20. Given %d\n", n);
		return 1;
	}

	for (int i=0; i<n; i++)
		scanf("%s", expr[i]);

    printf("\nGiven IC:\n");
    for(int i = 0; i < n; i++)
        printf("%s\n", expr[i]);


	for (int i = 0; i < n-1; i++)
	{
		char c = expr[i][0];
		int used = 0;
		for (int j = 0; j < n && !used; j++)
			used = strchr(expr[j]+2, c) != NULL;
		if (!used)
			expr[i][0] = '\0';
	}

    printf("\nRemoved unused variable:\n");
    for(int i = 0; i < n; i++) {
		if (expr[i][0] == '\0') continue;
		printf("%s\n", expr[i]);
	}
	
	for (int i=0; i<n-1; i++)
	{
		if (expr[i][0] == '\0') continue;
		for (int j=i+1; j<n; j++) {
			if (expr[j][0] == '\0') continue;
			if (strcmp(expr[i]+2, expr[j]+2) == 0) {
				for (int k=j+1; k<n; k++) {
					if (expr[k][0] == '\0') continue;
					char* p = strchr(expr[k], expr[j][0]);
					if (p) *p = expr[i][0];
				}
				expr[j][0] = '\0';
			}
		}
	}

    printf("\nRemoved repeated computation:\n");
    for(int i = 0; i < n; i++) {
		if (expr[i][0] == '\0') continue;
		printf("%s\n", expr[i]);
    }

    return 0;
}
