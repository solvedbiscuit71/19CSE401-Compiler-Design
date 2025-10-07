#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
struct Operator {
    int i;
    char c;
} op[MAX];

char expr[MAX];
int size=0;
int opCount = 0;
char tempVar = 'Z';


void findOperators() {
	// Higher precedence
	for (int i=0; i<size; i++) {
		if (expr[i] == '/' || expr[i] == '*') {
			op[opCount].i = i;
			op[opCount].c = expr[i];
			opCount++;
		}
	}
	// Lower precedence
	for (int i=0; i<size; i++) {
		if (expr[i] == '+' || expr[i] == '-') {
			op[opCount].i = i;
			op[opCount].c = expr[i];
			opCount++;
		}
	}
}

char left(int p)
{
	for (int i=p-1; i>=0; i--) {
		if (isalpha(expr[i])) {
			char x = expr[i];
			expr[i] = '$';
			return x;
		}
	}
	return '$';
}

char right(int p)
{
	for (int i=p+1; i<size; i++) {
		if (isalpha(expr[i])) {
			char x = expr[i];
			expr[i] = '$';
			return x;
		}
	}
	return '$';
}

void generateCode() {
    for (int i = 0; i < opCount; i++) {
        printf("%c = %c %c %c\n", tempVar, left(op[i].i), op[i].c, right(op[i].i));
        expr[op[i].i] = tempVar--;
    }
	printf("%c = %c\n", expr[0], right(1));
}

int main() {
    printf("Enter expression: ");
	char c;
	while ((c = getchar()) != '\n') expr[size++] = c;
	expr[size] = '\0';

    printf("\nIntermediate Code\n");
    findOperators();
    generateCode();

    return 0;
}
