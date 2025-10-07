%{
#define YYSTYPE double
#include <ctype.h>
#include <stdio.h>

int yylex();
void yyerror(char *s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'
%right UMINUS

%%

lines:
     lines expr '\n' { printf("%g\n",$2); }
    | lines '\n'
    | 
    ;

expr:
    expr'+'expr {$$=$1+$3;}
    | expr'-'expr {$$=$1-$3;}
    | expr'*'expr {$$=$1*$3;}
    | expr'/'expr {$$=$1/$3;}
    | '('expr')' {$$=$2;}
    | '-'expr%prec UMINUS {$$=-$2;}
    | NUMBER
    ;

%%

int yylex()
{
    int c;
    while((c=getchar())==' ');
    if((c=='.') || (isdigit(c)))
    {
        ungetc(c,stdin);
        scanf("%lf",&yylval);
        return NUMBER;
    }
    return c;
}

void yyerror(char *s)
{
	printf("stderr: %s\n", s);
}

int main()
{
    yyparse();
    return 1;
}
