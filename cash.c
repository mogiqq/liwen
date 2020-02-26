#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        // get float number
        dollars = get_float("how much change is owed: ");
    }
    // check if dollars is non negative
    while (dollars < 0);
    // round dollars as integer
    int cents = round(dollars * 100);
    // check how many coins require
    int quaters = cents / 25;
    int dimes = (cents % 25) / 10;
    int nickels = ((cents % 25) % 10) / 5;
    int pennies = (((cents % 25) % 10) % 5);

    printf("%d\n", quaters + dimes + nickels + pennies);
    
}
