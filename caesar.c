#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int k, string array[])
{
    // check if input data is single command line argument
    if (k != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    // check if input data contains only digit
    for (int i = 0, a = strlen(array[1]); i < a; i++)
    {
        if (isdigit(array[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    //string convert to integer
    int key = atoi(array[1]);
    
    //get plaintext
    string plaintext = get_string("plaintext: ");
    
    //print ciphertext
    printf("ciphertext: ");
    
    //encipher letter by letter
    for (int i = 0, b = strlen(plaintext); i < b; i++)
    {
        
        if (isupper(plaintext[i]))
        {
            int c = (((((plaintext[i] + key) - 65) % 26) + 65));
            printf("%c", c);
        }
        else if (islower(plaintext[i]))
        {
            int c = (((((plaintext[i] + key) - 97) % 26) + 97));
            printf("%c", c);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
