#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;//initialize input
    do // do one time and if input is out of range do again
    {
        h = get_int ("Height: ") ;  //get height
    }
    while (h < 0 || h > 23);
    for (int i = 0; i < h; i++)
    {
        printf("%*s%s", h-i-1, "", "##"); //print needed spaces and two hashes for the pattern
        for (int j = 0; j < i; j++)
        {
            printf("#"); //print remaining hashes for completing the pyramid
        }
        printf("\n"); //new line
    }
}