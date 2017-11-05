#include <stdio.h>
#include <stdlib.h>
#include "plist.h"


//* Constructors

// Make a new node:

pnode_t* make_node(char *name, pnode_t *next)
{
  pnode_t *ret = (pnode_t *) malloc(sizeof(pnode_t));

  ret->name = name;
  ret->next = next;

  return ret;
}

// Make a new empty list:

plist_t* make_list()
{
  plist_t *lst = (plist_t*) malloc(sizeof(plist_t));
  lst->first = NULL;
  return lst;
}


//* Destructors

// frees the memory of the given node:

void free_node(pnode_t *node)
{
  free(node);
}

void free_list(plist_t *list)
{
  pnode_t *temp = list->first;
  while (temp != NULL)
    {
      pnode_t *next = temp->next;
      free_node(temp);
      temp = next;
    }
  free(list);
}

//* Operations

//insert a new name at the end of the list:

void list_insert(plist_t *list, char *name)
{
  pnode_t *new_node = make_node(name, NULL);
  pnode_t *cur = list->first;
  if (cur == NULL)
    {
      list->first = new_node;
    }
  else {
    while (cur->next != NULL)
      {
        cur = cur->next;
      }
    cur->next = new_node;
  }
}

//removes the given name from the list, returning true if the name is found and removed and false otherwise:

bool list_remove(plist_t *list, char *name)
{
  pnode_t *cur = list->first;
  if (cur == NULL){
    //when nothing's on the list, false
    return false;
  }else if (!strcmp(cur->name, name))
    {
      //when the name is equal to the first element of the list
      list->first = cur->next;
      free(cur);
      return true;
    }else
    {
      while (cur->next != NULL)
        {
          if (!strcmp(cur->next->name, name))
            {
              pnode_t *temp = cur->next;
              cur->next = cur->next->next;
              free(temp);
              return true;
            }
          cur = cur->next;
        }
      return false;
    }
}

//returns the number of elements in the list:

int list_size(plist_t *list)
{
  int sz = 0;
  pnode_t *cur = list->first;
  while (cur != NULL)
    {
      sz++;
      cur = cur->next;
    }
  return sz;
}

//print out the target ring:

void printAsTargetRing(plist_t *list)
{
  pnode_t *cur = list->first;
  if (cur == NULL)
    {
      printf("There are no targets left!\n");
    }else if (cur->next == NULL)
    {
      printf("%s is the final person remaining!\n", cur->name);
    }else
    {
      printf("Target Ring:\n");
      while (cur != NULL)
        {
          printf("\t%s is stalking ", cur->name);
          cur = cur->next;
          if (cur != NULL){
            printf("%s\n", cur->name);
          }else{
            printf("%s\n", list->first->name);
          }
        }
    }
}

//print out the tagged list:

void printAsTaggedList(plist_t *list)
{
  pnode_t *cur = list->first;
  if (cur == NULL)
    {
      printf("No people have been tagged yet!\n");
    }else{
    printf("Tagged List:\n");
    while (cur != NULL)
      {
        printf("\t%s\n", cur->name);
        cur = cur->next;
      }
  }
}

