#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/********* DEFINED CONSTANTS *********/
#define   MAX        1024

/********* FUNCTION DECLARATION *********/
bool is_empty(FILE *fp);
void rm_comments(FILE *ifp, FILE *ofp);
void rm_comments_mul(FILE *ifp, FILE *ofp);

/********* MAIN STARTS HERE *********/
int main(int argc, char **argv)
{
    char       *ifile, *ofile;
    FILE       *ifp = NULL, *ofp = NULL;

    if (argc != 3)
    {
        fprintf(stderr, "Syntax: ./%s <in-name> <out-file>\n", argv[0]);
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

    rm_comments(ifp, ofp);

    exit(0);
}

/********* FUNCTION DEFINITION *********/
bool is_empty(FILE *fp)
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

void rm_comments(FILE *ifp, FILE *ofp)
{
    int        i, j;
    bool       single_comment = false, multi_comment = false;
    char       outline[MAX], line[MAX];

    if (is_empty(ifp))
    {
        printf("The given input file is an empty file\n");
        exit(3);
    }

    while (fgets(line, MAX, ifp))
    {
        i = 0, j = 0;
        if (single_comment)
        {
            single_comment = false;
        }

        outline[j] = '\0';          // Initializing the output line
        while (line[i] != '\n')
        {
            if (!multi_comment && !single_comment)
            {
                if (line[i] == '/' && line[i+1] == '/')
                {
                    single_comment = true;
                }
                else if (line[i] == '/' && line[i+1] == '*')
                {
                    multi_comment = true;
                }
                else
                {
                    outline[j] = line[i];
                    j = j + 1;
                }
            }
            else
            {
                if (multi_comment && (line[i] == '*' && line[i+1] == '/'))
                {
                    multi_comment = false;
                    i = i + 1;
                }
            }
            i = i + 1;
        }
        outline[j] = '\0';        // Null Char at the end of the line.
        if (strlen(outline) != 0 && !multi_comment)
        {
            fprintf(ofp, "%s\n", outline);
        }
    }

    fclose(ifp);
    fclose(ofp);

    return ;
}
