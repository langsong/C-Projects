#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//* Structures

//define the structure of pnode:

typedef struct node
{
  char *name;
  struct node *next;
} pnode_t;

//define the structure of plist:

typedef struct list
{
  pnode_t *first;
} plist_t;

//* Functions:

//make a new pnode on the heap:

pnode_t* make_node(char *name, pnode_t *next);

//allocates a new empty list on the heap:

plist_t* make_list();

//frees the given node:

void free_node(pnode_t *node);

//frees the given list:

void free_list(plist_t *list);

//inserts the given name into the end of the list:

void list_insert(plist_t *list, char *name);

//removes the given name from the list, returning true if the name is found and removed and false otherwise:

bool list_remove(plist_t *list, char *name);

//returns the number of elements in the list:

int list_size(plist_t *list);

//print the target ring:

void printAsTargetRing(plist_t *list);

//print the tagged list:

void printAsTaggedList(plist_t *list);

// reads a line of input from the user, storing the first k characters of the input into a char array assumed to be of size k+1:

void readline(char *buf, int k);

//allocates a copy of the string on the heap and returns a pointer to it:

char* stralloc(char *str);

