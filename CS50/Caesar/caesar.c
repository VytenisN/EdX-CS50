#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) //checking if a single number is entered as a key
    {
        printf("Put a single positive number\n");
        return 1;
    }
    int key = atoi(argv[1]); // converting number in string to int
    string txt = get_string("Please enter text to cypher: ");
    printf ("plaintext: %s\n", txt); //print plaintext
    printf ("ciphertext: ");
    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        if (isalpha(txt[i])) //checking is it alphanumeric
        {
            if (isupper(txt[i]))
            {
                printf("%c", ((txt[i] + key - 65) % 26) + 65) ; // for uppercase letters converting to ASCI and back
            }
            else
            {
                printf("%c", ((txt[i] + key - 97) % 26) + 97); // for lowercase letters converting to ASCI and back
            }
        }
        else printf("%c", txt[i]);    // if char is not alphanumeric than print the original one
    }
    printf ("\n");
}