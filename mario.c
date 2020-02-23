#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    // range in 1 to 8
    while (n < 1 || n > 8);
    // how many times to run
    for (int i = 0; i < n; i++)
    {
        // right spaces
        for (int s = n - i; s > 1; s--)
        {
            printf(" ");
        }
        //right pyramids
        for (int h = 0; h < i + 1; h++)
        {
            printf("#");
        }
        // gap
        printf("  ");
        //left pyramids
        for (int hh = 0; hh < i + 1; hh++)
        {

            printf("#");
        }       
        printf("\n");
    }
  
}
