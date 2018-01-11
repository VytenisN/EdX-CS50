// program to crack passwords up to 5 letters hashed with crypt()

#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main (int argc, string argv[])
{
    //checking if a single hash is entered into command line
    if (argc !=2) 
    {
        printf("Paste a single hash:");
        return 1;
    }
    char test[6] ;
    
    // *Uncomment 2 lines below in order to create new hashes
    //string z = crypt(argv[1], "50");
    //printf ("%s\n", z);
    for ( int ii = 65, j = 0; ii < 123; ii++)
    {
        for ( int i = 65; i < 123; i++)  //all the possible combos in ASCII
        {

            if (j==1) test[0] = (char) ii;
            test[0+j] = (char) i;
            test[1+j] = '\0';
            if (strcmp(crypt(test, "50"), argv[1])  == 0) //checking if strings are equal
            {
                printf("%s Yessssss\n",test);
                return 0;
            }
            printf("%s Not found\n",test );
            if (j < 2 && i==122) { j++; i = 64;}
        }

    }

}