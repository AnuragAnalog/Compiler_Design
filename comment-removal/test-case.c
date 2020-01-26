// C program to illustrate 
// use of multi-line comment 
#include <stdio.h> 
int main(void) 
{
    int      a = 5; // This is a comment
    // Single line Welcome user comment

    /* This is a multi line comment // embedded comment
    this part is written only for testing
    the program accuracy */ a = 9;
    printf("Welcome to /* some */ GeeksforGeeks %d\n", a); 
    return 0; 
}