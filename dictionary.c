// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int TABLE_SIZE = 50000;

// Hash table
node *table[TABLE_SIZE];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO:
    
    // returns true if found else return false
    int index = hash(word);
    // make a cursor node which points to the head of the hash table
    node *cursor = table[index];
    // for loop to go through the list til the final node is reached.
    for (node *temp = cursor; temp != NULL; temp = temp->next)
    {
        if (strcasecmp(temp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hashvalue = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hashvalue += tolower(word[i]);
        hashvalue = (hashvalue * tolower(word[i])) % TABLE_SIZE;
    }
    return hashvalue;
}

int counter = 0;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO:
    // This function returns true if all data loaded into hash table, - false if there is an error.
    // Stores all data in a hash table, the hash function assigns an index to each word.

    // First, to add new data to hash table, allocate memory for nodes then add data to the node.
    // This format copies words into the character array strcpy(n->word, "hello"); to set next
    // pointer n->next = NULL;

    // OPEN DICTIONARY FILE and read the contents.
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "There has been an error");
        return false;
    }

    // wordlist is a character array of the words.
    char wordlist[LENGTH + 1];
    // while fscanf != EOF print the words into the character array words.
    while (fscanf(file, "%s", wordlist) != EOF)
    {
        // Keep track of how many nodes are being made
        counter++;
        // for each new node allocate memory
        node *newNode = malloc(sizeof(node));
        // check for null
        if (newNode == NULL)
        {
            return 1;
        }
        // Initialize the new node by copying the word to the next node.
        strcpy(newNode->word, wordlist);
        newNode->next = NULL;
        // Add to the hash table each element of the hash table is a linked list!
        // if index != NULL newNode->word points to the old head of the list
        int index = hash(wordlist);
        // if the index is not yet assigned, put the newest node at the head of this index
        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        // if the index is assigned point the existing head node at the table[index] & then make the
        // new node the head.
        else
        {
            // makes the next the new head
            newNode->next = table[index];
            // head points to the new node
            table[index] = newNode;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO:
    // keep track of how many nodes have been added
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO:
    // for each of hash table 'buckets' the memory must be freed.
    node *tmp = NULL;
    node *cursor = NULL;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}