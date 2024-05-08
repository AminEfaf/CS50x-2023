#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // reciving info from user
    long cardNum = get_long("Please enter the card number: ");
    int i = 0;
    long count = cardNum;

    while (count > 0)
    {
        count /= 10;
        i++;
    }

    // check if info is right or not
    if (i != 13 && i != 15 && i != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    int firstSum = 0, secondSum = 0;
    long x = cardNum;
    int total = 0;
    int firstMod, secondMod, d1 = 0, d2 = 0;

    do
    {
        firstMod = x % 10;
        x = x / 10;
        firstSum += firstMod;

        secondMod = x % 10;
        x = x / 10;
        secondMod *= 2;
        if (secondMod > 9)
        {
            d1 = secondMod % 10;
            d2 = secondMod / 10;
            secondMod = d1 + d2;
        }

        secondSum += secondMod;
    }
    while (x > 0);

    total = firstSum + secondSum;

    // check if its divideble by 10 or not
    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // extracting first 2 digits
    long firstTwo = cardNum;
    do
    {
        firstTwo /= 10;
    }
    while (firstTwo > 100);

    // check if its for american express
    if (i == 15 && (firstTwo == 34 || firstTwo == 37))
    {
        printf("AMEX\n");
    }
    else
    {

        // check if its for MASTERCARD
        if (i == 16 && (firstTwo == 51 || firstTwo == 52 || firstTwo == 53 || firstTwo == 54 || firstTwo == 55))
        {
            printf("MASTERCARD\n");
        }
        else
        {

            // extracting first digit
            long first = cardNum;
            do
            {
                first /= 10;
            }
            while (first > 10);

            // check if its for VISA
            if ((i == 13 || i == 16) && (first == 4))
            {
                printf("VISA\n");
            }
            else
            {

                printf("INVALID\n");
                return 0;
            }
        }
    }
}
