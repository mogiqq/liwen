#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    string t = get_string("Text: ");
    
    //printf("%i letter(s)\n", count_letters(t));
    //printf("%i word(s)\n", count_words(t));
    //printf("%i sentence(s)\n", count_sentences(t));
    
    float letters = count_letters(t);
    float words = count_words(t);
    float sentences = count_sentences(t);
    
    float l = (letters / words)*100;
    float s = (sentences / words)*100;
    
    float index = 0.0588 * l - 0.296 * s - 15.8;
    
   // printf("%f, %f, %f\n",l, s, index);
    
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.f\n", round(index));
    }
        
}

int count_letters(string s)
{
    int sum = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            sum += 1;
        }
    }
    
    return sum;
}

int count_words(string s)
{
    int sum = 1;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isspace(s[i]))
        {
            sum += 1;
        }
    }
    return sum;
}

int count_sentences(string s)
{
    int sum = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if ((s[i] == '?' ) || (s[i] == '.') || (s[i] == '!'))
        {
            sum += 1;
        }
    }
   return sum;
    
}