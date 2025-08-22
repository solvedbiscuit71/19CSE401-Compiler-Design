#include <stdio.h>

#define SIZE 50

int get_index(char c) {
	switch (c) {
		case 'S':
			return 0;
		case 'A':
			return 1;
		case 'B':
			return 2;
		case 'i':
			return 0;
		case '+':
			return 1;
		case '*':
			return 2;
		case '$':
			return 3;
	}
	return -1;
}

char* lookup(char (*table)[4][5], char A, char t) {
	int i=get_index(A);
	int j=get_index(t);
	if (i == -1 || j == -1)
		return NULL;
	return table[i][j];
}

int main() {
	char table[3][4][5] = {
		"A", "", "", "",
		"Bi", "", "", "",
		"", "A+", "A*", "e"
	};

	char stack[SIZE] = "$S";
	char buf[SIZE];
	printf("Enter: ");
	scanf("%s", buf);

	int i=1, j=0, k;
	char* rule;
	printf("%s \t\t %s\n", "stack", "buffer");
	while (buf[j] != '\0') {
		printf("%s \t\t %s", stack, (char*)buf+j);

		// top is non-terminal
		if ('A' <= stack[i] && stack[i] <= 'Z') {
			rule = lookup(table, stack[i], buf[j]);

			// Invalid symbol
			if (rule == NULL) {
				printf("\nFAILED (invalid symbol).\n");
				break;

			// No production rule
			} else if (rule[0] == '\0') {
				printf("\nFAILED (no production rule).\n");
				break;

			// epsilon production
			} else if (rule[0] == 'e') {
				stack[i--] = '\0';

			// regular production
			} else {
				k=0;
				while (rule[k] != '\0') {
					stack[i++] = rule[k++];
				}
				stack[i--] = '\0';
			}
			printf("\t (replace %s)\n", rule);

		// top is terminal
		} else {
			// equal
			if (stack[i] == buf[j]) {
				// if '$'
				if (stack[i] == '$') {
					printf("\nSUCCESS.\n");
					break;
				
				// otherwise
				} else {
					stack[i--] = '\0';
					j++;
				}
				printf("\t (pop)\n");

			// not equal
			} else {
				printf("\nFAILED (not-equal).\n");
				break;
			}
		}
	}
	return 0;
}
