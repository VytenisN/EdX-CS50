// program to crack passwords up to 5 letters hashed with crypt() and CS50's salt "50"

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
    char test[6] ;  // initialize empty string for generating test passwords

    // *Uncomment 2 lines below in order to create new hashes
    //string z = crypt(argv[1], "50");
    //printf ("%s\n", z);

    int size = 0; // set the length of testword

    for ( int iiiii = 65 ; iiiii < 123; iiiii++) // loop for 5 letter passwords
    {
        if (iiiii == 91) iiiii = 97;  // jump over irrelevant characters in ASCI table
        for ( int iiii = 65 ; iiii < 123; iiii++) // loop for 4 letter passwords
        {
            if (iiii == 91) iiii = 97;  // jump over irrelevant characters in ASCI table
            for ( int iii = 65 ; iii < 123; iii++) // loop for 3 letter passwords
            {
                if (iii == 91) iii = 97;  // jump over irrelevant characters in ASCI table
                for ( int ii = 65 ; ii < 123; ii++)  // looping for 2 letter passwords
                {
                    if (ii == 91) ii = 97;  // jump over irrelevant characters in ASCI table
                    for ( int i = 65 ; i < 123; i++)  // main loop for changing letters
                    {
                        //if (size == 5) test[size-2] = (char) iiiiii;
                        if (size == 4) test[size-4] = (char) iiiii; //if letter is needed put it to the beggining. Move right another one is added
                        if (size >= 3) test[size-3] = (char) iiii;  //if letter is needed put it to the beggining. Move right another one is added
                        if (size >= 2) test[size-2] = (char) iii;   //if letter is needed put it to the beggining. Move right another one is added
                        if (size >= 1) test[size-1] = (char) ii;    //if letter is needed put it to the beggining. Move right another one is added

                        if (i == 91) i = 97;  // jump over irrelevant characters in ASCI table
                        test[0+size] = (char) i;
                        test[1+size] = '\0';
                        if (strcmp(crypt(test, "50"), argv[1])  == 0) //checking if test hash and input hash are equal
                        {
                            printf("%s Yessssss\n",test);
                            return 0;  // end testing if matching hash is found
                        }
                        printf("%s Not found\n",test );
                        if (size < 1 && i == 122) {size ++; i = 64;}         // repeat 1 letter loop
                        if (size < 2 && ii == 122) {size ++; ii = 64;}       // repeat 2 letter loop for both letters
                        if (size < 3 && iii == 122) {size ++; iii = 64;}     // repeat 3 letter loop for all letters
                        if (size < 4 && iiii == 122) {size ++; iiii = 64;}   // repeat 4 letter loop for all letters
                        if (size < 5 && iiiii == 122 ) {size ++; iiiii = 64;} // repeat 5 letter loop for all letters
                        if (size == 5 && iiiii == 122) {printf ("End of checking 5 letter password") ; return 0;} // if hash not found for 5 letters print message and end
                    }
                }
            }
        }
    }
}