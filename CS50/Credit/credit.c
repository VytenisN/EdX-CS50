//checking credit card types and numbers
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long long num;
    do
    {
        num = get_long_long("Number: "); //prompt for number
    }
    while (num <= 0);
    int nDigits = floor(log10(llabs(num))) + 1; //calculate number of digits
    int sum = 0;
    for (int z = 1; z < nDigits; z=z+2) //calculate sum 2x of every second number, starting from the 2nd last
    {
        int temp = (floor(fmod(num/(pow(10,z)), 10)))*2; //temporary variable to store in order to decide if it is double digit
        if (temp>9)
        {
            sum += (temp % 10) + ((temp/10)%10); // add both numbers if double is more than 9
        }
        else
        {
            sum += temp;
        }
    }
    for (int y = 0; y < nDigits; y = y +2) //add to sum of every second number, starting from the last
    {
        sum+= floor(fmod(num/ (pow(10, y)), 10));
    }
    if (sum % 10 == 0)   //if number is valid check for conditions on all cards
    {
        if (nDigits == 16 && ((num / 100000000000000) % 100 == 55||(num / 100000000000000) % 100 == 54||(num / 100000000000000) % 100 == 53||(num / 100000000000000) % 100 == 52||(num / 100000000000000) % 100 == 51))
           printf("MASTERCARD\n");
        else if (nDigits == 15 && ((num / 10000000000000) % 100 == 37||(num / 10000000000000) % 100 == 34))
           printf("AMEX\n");
        else if ((nDigits == 13 || nDigits==16) && ((num / 1000000000000) % 10 == 4 || (num / 1000000000000000) % 10 == 4))
           printf("VISA\n");
    }
    else printf("INVALID\n"); // else return INVALID
}