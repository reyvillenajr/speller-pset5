# speller-pset5(CS50 Project)
NOTE: Copying this data and using it for your submission will breach CS50's academic honesty policy (https://cs50.harvard.edu/x/2020/honesty/). Make sure you learn the material and provide the solution yourself. It's worth it!

This is my solution for the CS50 speller problem set, using C. https://cs50.harvard.edu/x/2020/psets/5/speller/ This problem set required implementing a program that spell-checks a file (from a list of words, i.e., the dictionaries provided by CS50).

This was produced as a part of CS50 - Introduction to Computer Science. Uploading my solution to Github is considered reasonable in terms of the academic honesty policy. (https://www.reddit.com/r/cs50/comments/63235w/is_this_reasonable/)

This problem required the implementation of the following functions (all within dictionary.c);

load.
hash.
size.
check.
unload.

To enhance the speed at which words in a provided text could be spell-checked against the dictionaries;

1. The dictionaries were opened in the function load and added to a character array.
2. The character array consisted of linked lists, so each word was loaded into the linked list and then hashed through using the hash function, which provided a hash value.
3. Size returns the number of nodes/words added through increasing at each iteration of the while loop contained within the load function.
4. The load function checks each node against each word in the hash table with the corresponding index to return true if it is present.
5. Unload frees all of the data contained within the hash table by iterating through the hash table.

Note* There are additional files omitted from this repository which are the dictionaries and sample texts, additionally, there is a makefile which compiles the speller and dictionary files.
