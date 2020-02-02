#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/********* DEFINED CONSTANTS *********/
#define MAX        1024
#define INTMAX     10

/********* FUNCTION DECLARATION *********/
void int_operators(char *string);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
    char       *in_string = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "Syntax: %s <string>\n", argv[0]);
        exit(1);
    }

    in_string = argv[1];
    if (strlen(in_string) == 0)
    {
        printf("String shouldn't be empty\n");
        exit(-1);
    }

    int_operators(in_string);

    exit(0);
}

/********* FUNCTION DEFINITION *********/
void int_operators(char *string)
{
    int        i = 0, k = 0, j = 0, l = 0, chk = 0, integers[MAX];
    char       ints[INTMAX], operators[MAX];
    bool       cond_oper = false;

    cond_oper = (string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/');
    if (cond_oper)
    {
        printf("An arthimetic expression shouldn't start with operator\n");
        exit(2);
    }

    while (string[i] != '\0')
    {
        cond_oper = (string[i] == '+' || string[i] == '-' || string[i] == '*' || string[i] == '/');
        if (!cond_oper && (string[i] < '0' && string[i] > '9'))
        {
            printf("String should only contain digits or operators\n");
            exit(3);
        }

        while (string[i] >= '0' && string[i] <= '9')
        {
            ints[k] = string[i];
            k = k + 1;
            i = i + 1;
        }

        if (k != 0)
        {
           ints[k] = '\0';
           integers[j] = atoi(ints);
           j = j + 1;
           k = 0;
        }

        if (cond_oper)
        {
            operators[l] = string[i];
            i = i + 1;
            l = l + 1;
            if (chk == i-1)
            {
                printf("There shouldn't be consecutive operators\n");
                exit(4);
            }
            chk = i;
        }
    }

    if (cond_oper)
    {
        printf("An arthimetic expression shouldn't end with operator\n");
        exit(5);
    }

    printf("Operators in the expression: %s\n", operators);
    printf("Integers in the string:\n");
    for (i = 0; i < j; i++)
    {
        printf("%d ", integers[i]);
    }
    printf("\n");

    return ;
}