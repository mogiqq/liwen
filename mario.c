#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    for (int i = 0; i < n; i++)
    {
        for (int s = n - i; s > 1; s--)
        {
            printf(" ");
        }
        for (int h = 0; h < i + 1; h++)
        {
            printf("#");
        }
        //for (int ss = 1; ss < i ; n - ss)
        //{
        printf("  ");
        //}
        for (int hh = 0; hh < i + 1; hh++)
        {

            printf("#");
        }       
    printf("\n");
    }
  
}
