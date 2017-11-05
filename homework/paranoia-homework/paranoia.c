#include <stdio.h>
#include <stdlib.h>
#include "plist.h"

//* Two auxiliary functions:

//reads a line of input from the user, storing the first k characters of the input into a char array assumed to be of size k+1:

void readline(char *buf, int k)
{
  int count = 0;
  char car = getchar();
  while (count < k && car != '\n'){
    buf[count] = car;
    car = getchar();
    count++;
  }
  buf[count] = '\0';
  while(car != '\n'){
    car = getchar();
  }
}

// given a string, allocates a copy of the string on the heap and returns a pointer to it:

char* stralloc(char *str)
{
  char* string = (char *) malloc(sizeof(char)*(strlen(str)+1));
  strcpy(string, str);
  return string;
}


//* main function:

int main()
{
  plist_t *targets = make_list();
  plist_t *tagged = make_list();

  printf("Please enter the name of a player (press enter to begin game): ");

  char buf[21];
  readline(buf, 20);
  while(buf[0] != '\0'){
    list_insert(targets, stralloc(buf));
    printf("Enter another player's name: ");
    readline(buf, 20);
  }
  
  printAsTargetRing(targets);
  printAsTaggedList(tagged);
 
  while (list_size(targets) > 0){
    printf("\nThere are %d people left!\n", list_size(targets));
    printf("Enter a target: ");
    readline(buf, 20);
    if (!list_remove(targets, buf)){
      //if the name is not included in the targets
      printf("%s is not a target!\n", buf);
    }else{
      printf("%s was tagged!\n", buf);
      list_insert(tagged, stralloc(buf));
    }

    printAsTargetRing(targets);
    printAsTaggedList(tagged);
  }

  free_list(targets);
  free_list(tagged);

  return 0;
}

      
    

    
