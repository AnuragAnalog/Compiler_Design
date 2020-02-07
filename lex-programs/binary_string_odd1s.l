%{
int ones = 0, zeroes = 0;
%}

%%
[1] {ones++; printf("Encountered 1\n");}
[0] {zeroes++; printf("Encountered 0\n");}
.   {printf("Invalid letter"); return 0;}
end return 0;
%%

int yywrap(){}
int main(){

yylex();
if (ones%2)
{
    printf("Odd zeroes\n");
}
return 0;
}