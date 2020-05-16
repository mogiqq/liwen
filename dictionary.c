// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
//the highest unsigned 16 bit integer is 65535. which is 2^16 - 1, because we have 0000000000000000
//max hashtable size 2^16
const unsigned int N = 65536;

// Hash table
node *table[N];

int counter = 0;

// Hashes word to a number
//https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn/
unsigned int hash(const char *word)
{
    // TODO
    unsigned int hash = 0;

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // << 2 is equivalent to multiplying by 4 ( 22 ). But the shift operation is more efficient (and faster) than using x*4
        hash = (hash << 2) ^ tolower(word[i]);
    }
    //returns a value in the range (0, N)
    return hash % N;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    //hash word to obtain hash value
    //access linked list at that index in the hash table
    //check if the word is in dictionary
    //start with cursor set to first item in the linked list
    unsigned int hashvalue = hash(word);
    node *cursor = table[hashvalue];

    while (cursor != NULL)
    {
        if (strcasecmp(cursor -> word, word))
        {
            return true;
        }
        cursor = cursor -> next;
    }
    return false;
}

// Loads dictionary into memory, returning true if successful else false
// taking the dictionary and loading it into a hash table
bool load(const char *dictionary)
{
    // TODO
    //open dictionary file
    FILE *dicf = fopen(dictionary, "r");

    //check if value is NULL
    if (dicf == NULL)
    {
        fprintf(stderr, "could not open the file %s.\n", dictionary);
        return 1;
    }

    // temp array for word
    char word[LENGTH + 1];

    // scan word by word in dictionary
    while (fscanf(dicf, "%s", word) != EOF)
    {
        // allocate memory
        node *n = malloc(sizeof(node));

        // check if memory is empty
        if (n == NULL)
        {
            fclose(dicf);
            return false;
        }

        //copy the word into node
        strcpy(n -> word, word);

        //frist n point to node
        n -> next = NULL;

        //hash word
        unsigned int index = hash(word);

        //insert node into hash table at that location
        n -> next = table[index];
        table[index] = n;

        //increment counter for each word in dictionary to return in SIZE
        counter++;
    }
    fclose(dicf);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor -> next;
            free(tmp);
        }
    }
    return true;

}
