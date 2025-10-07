#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char expr[100], c;
    int i = 0;

	printf("Enter expression: ");
    while ((c = getchar()) != '$' && c != '\n') {
        expr[i++] = c;
    }
    expr[i] = '\0';

	printf("\n%-10s%-20s%-10s\n", "Symbol", "Address", "Type");

    for (int j = 0; expr[j] != '\0'; j++) {
        c = expr[j];

        char *ptr = (char *)malloc(sizeof(char));
        *ptr = c;

        if (isalpha(c)) {
            printf("%-10c%-20p%-10s\n", c, (void *)ptr, "identifier");
        } else if (c == '+' || c == '-' || c == '*' || c == '=') {
            printf("%-10c%-20p%-10s\n", c, (void *)ptr, "operator");
        }
    }

    return 0;
}
