#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/********* DEFINED CONTSANTS *********/
#define MAX       1024

/********* FUNCTION DECLARATION *********/
bool is_file_empty(FILE *fp);
void remove_spaces(FILE *ifp, FILE *ofp);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
    char       *ifile = NULL, *ofile = NULL;
    FILE       *ifp = NULL, *ofp = NULL;

    if (argc != 3)
    {
        fprintf(stderr, "Syntax: %s <infile> <outfile>\n", argv[0]);
        exit(1);
    }

    ifile = argv[1];
    ofile = argv[2];

    ifp = fopen(ifile, "r");

    if (ifp == NULL)
    {
        printf("File does not exist\n");
        printf("Or it may not have the required permissions\n");
        exit(2);
    }

    ofp = fopen(ofile, "w");

    remove_spaces(ifp, ofp);

    fclose(ifp);
    fclose(ofp);

    exit(0);
}

/********* FUNCTION DEFINITION *********/
bool is_file_empty(FILE *fp)
{
    char       check;

    check = fgetc(fp);
    rewind(fp);
    if (check == EOF)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void remove_spaces(FILE *ifp, FILE *ofp)
{
    int        i, j;
    char       outline[MAX], line[MAX];

    if (is_file_empty(ifp))
    {
        printf("The given input file is an empty file\n");
        exit(3);
    }

    while (fgets(line, MAX, ifp))
    {
        i = 0, j = 0;
        outline[j] = '\0';
        while (line[i] != '\0')
        {
            if (line[i] != ' ' && line[i] != '\t')
            {
                outline[j] = line[i];
                j = j + 1;
            }
            i = i + 1;
        }
        outline[j] = '\0';
        fprintf(ofp, "%s", outline);
    }

    return ;
}