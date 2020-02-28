#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardnum;
    do
    {
        cardnum = get_long("Credit Card Number: ");
    }
    while (cardnum < 1);

    long headnum = cardnum;
    int count = 2;
    while (headnum > 100)
    {
        headnum /= 10;
        count ++;
    }
    long sumnum = cardnum;
    int sum = 0;
    for (int i = 1; i <= count; i++)
    {
        int digit = sumnum % 10;
        if (i % 2 == 0)
        {
            if (digit * 2 > 9)
            {
                sum += (digit * 2 - 9);
            }
            else
            {
                sum += digit * 2;
            }

        }
        else
        {
            sum += digit;
        }
        sumnum /= 10;
    }
    if (sum % 10 == 0)
    {
        if ((count == 13 || count == 16) && (headnum / 10 == 4))
        {
            printf("VISA\n");
        }
        else if ((count == 16) && (headnum > 50 && headnum < 56))
        {
            printf("MASTERCARD\n");
        }
        else if ((count == 15) && (headnum == 34 || headnum == 37))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
