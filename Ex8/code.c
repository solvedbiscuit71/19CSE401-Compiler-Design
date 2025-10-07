#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 * From <stdlib.h>
	 * FILE* fopen(char* filename, char* mode) : open the file in the desired mode and returns a FILE pointer
	 * int fprint(FILE* stream, char* format, ...) : similar to printf, but writes to FILE pointer instead of stdout
	 * int fscanf(FILE* stream, char* format, ...) : similar to scanf, but reads from FILE pointer instead of stdin
	 * int feof(FILE* stream) : check for end-of-file indicator
	 * int fclose(FILE* stream) : close the file
 *
 * From <string.h>
	 * int strcmp(char* s1, char* s2) : compare two strings
 *
 */

/*
 * Supported IC representation (three-address coding)
 * + t1 t2 t3
 * - t1 t2 t3
 * * t1 t2 t3
 * / t1 t2 t3
 * load t1 {immediate}
 * uminus t1 t2
 * print t1
 *
 */

int main(int argc, char* argv[])
{
	char op[10], t1[10], t2[10], t3[10];
	FILE *in, *out;
	in = fopen(argv[1], "r");
	out = fopen(argv[2], "w");

	while (!feof(in)) {
		fscanf(in, "%s", op);
		if (strcmp("+", op) == 0) {
			fscanf(in, "%s%s%s\n", t1, t2, t3);
			fprintf(out, "LOAD %s,R1\n", t2);
			fprintf(out, "LOAD %s,R2\n", t3);
			fprintf(out, "ADD R1,R2\n");
			fprintf(out, "STORE R1,%s\n", t1);
		} else if (strcmp("-", op) == 0) {
			fscanf(in, "%s%s%s\n", t1, t2, t3);
			fprintf(out, "LOAD %s,R1\n", t2);
			fprintf(out, "LOAD %s,R2\n", t3);
			fprintf(out, "SUB R1,R2\n");
			fprintf(out, "STORE R1,%s\n", t1);
		} else if (strcmp("*", op) == 0) {
			fscanf(in, "%s%s%s\n", t1, t2, t3);
			fprintf(out, "LOAD %s,R1\n", t2);
			fprintf(out, "LOAD %s,R2\n", t3);
			fprintf(out, "MUL R1,R2\n");
			fprintf(out, "STORE R1,%s\n", t1);
		} else if (strcmp("/", op) == 0) {
			fscanf(in, "%s%s%s\n", t1, t2, t3);
			fprintf(out, "LOAD %s,R1\n", t2);
			fprintf(out, "LOAD %s,R2\n", t3);
			fprintf(out, "DIV R1,R2\n");
			fprintf(out, "STORE R1,%s\n", t1);
		} else if (strcmp("uminus", op) == 0) {
			fscanf(in, "%s%s\n", t1, t2);
			fprintf(out, "LOAD -%s,R1\n", t2);
			fprintf(out, "STORE R1,%s\n", t1);
		} else if (strcmp("print", op) == 0) {
			fscanf(in, "%s\n", t1);
			fprintf(out, "OUT %s\n", t1);
		} else if (strcmp("load", op) == 0) {
			fscanf(in, "%s%s\n", t1, t2);
			fprintf(out, "LOAD #%s,R1\n", t2);
			fprintf(out, "STORE R1,%s\n", t1);
		} else {
			printf("Invalid op %s\n", op);
			break;
		}
	}

	fclose(in);
	fclose(out);
	return 0;
}
