#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    do
    {
        dollars = get_float("how much change is owed: ");
    }
    while (dollars < 0);
    int cents = round(dollars * 100);

    int quaters = cents / 25;
    int dimes = (cents % 25)/10;
    int nickels = ((cents % 25) % 10)/5;
    int pennies = (((cents % 25) %10) %5);

    printf("%d\n", quaters+dimes+nickels+pennies);
    
}
