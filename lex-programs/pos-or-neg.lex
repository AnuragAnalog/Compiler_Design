%{
int total = 0;
%}

%%
^[-][0-9]+ {total++; printf("Negative\n");}

[0-9]+ {total++; printf("Positive\n");}
%%

int yywrap(){}
int main(){

yylex();
printf("Total numbers = %s", total);
return 0;
}