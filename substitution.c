#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int k, string array[])
{
    int a = strlen(array[1]);
    // check if input data is single command line argument
    if (k != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    // check if number of characters is less than 26
    if (a != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    
    // check if characters contain digit(s)
    for (int i = 0; i < a; i++)
    {
        if (isdigit(array[1][i]))
        {
            printf("Key must contain alphabetic characters\n");
            return 1;
        }
        
        // check if characters repeat
        for (int j = i + 1; j < a; j++)
        {
            if (array[1][i] == array[1][j])
            {
                printf("Key must not contain repeated characters.\n");
            }
        }
    }
    
    //get plaintext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    
    int b = strlen(plaintext);
    for (int i = 0; i < b; i++)
    {
        if (isupper(plaintext[i]))
        {
            int c = (plaintext[i] - 65);
            printf("%c", array[1][c]);
        }
        else if (islower(plaintext[i]))
        {
            int c = (plaintext[i] - 97);
            printf("%c", array[1][c]);
        }
        else
        {
            printf("%c", array[1][i]);
        }
    }
    printf("\n");
}