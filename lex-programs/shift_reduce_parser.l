// A program to implement a shift reduce parser for a grammar which recognizes a valid expression which contain only + and - symbols.

%{
    int count = 0;
%}

%%
([+,-]?[1-9]+[+,-][1-9]+)+ {continue;}
. {printf("Invalid\n"); return 0;}
end return 0;
%%

int yywrap(void) {
    return 0;
}

int main()
{
    yylex();
    exit(0);
}
