%option noyywrap

%{
#include <stdio.h>
%}

identifier [a-zA-Z][a-zA-Z0-9_]*

%%

int|float|double|char printf("'%s' is a dtype.\n", yytext);
while|for|do|if|else|break|continue|return|goto|switch|case printf("'%s' is a keyword.\n", yytext);
"#".*/\n printf("'%s' is a preprocessing directive\n", yytext);
"//".*/\n printf("'%s' is a comment.\n", yytext);
"{" printf("'%s' indicates start of block.\n", yytext);
"}" printf("'%s' indicates end of block.\n", yytext);
\".*\" printf("'%s' is a string.\n", yytext);
[0-9]+ printf("'%s' is a integer.\n", yytext);
"=" printf("'%s' indicates assignment\n", yytext);
"+"|"-"|"*"|"/"|"&"|"|"|"^"|"%" printf("'%s' is a operator\n", yytext);
{identifier} printf("'%s' is a identifier\n", yytext);
"&"{identifier} printf("'%s' is a pointer.\n", yytext);
";" {}
"\n" {}
. {}

%%

int main() {
	yylex();
	return 0;
}
