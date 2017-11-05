#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MyroC.h>
#include <time.h>
#include "commands.h"

#define INITIAL_SIZE 16
#define GROWTH_FACTOR 2


//Ensures that the given buffer can accept additional elements.

char* ensure_capacity(char *buf, int *sz, int pos) {
    if (*sz == pos) {
        // N.B. realloc grows or shrinks its input buffer to the given size,
        // returning an updated pointer to the new buffer.  The elements of the
        // old buffer are copied automatically to the new buffer.
        char *newbuf = (char*) realloc(buf, *sz * GROWTH_FACTOR);
        if (newbuf == NULL) {
            free(buf);
            *sz = 0;
            return NULL;
        } else {
            *sz *= GROWTH_FACTOR;
            return newbuf;
        }
    } else {
        return buf;
    }
}


// Returns a heap-allocated line of input from the user or NULL if the
// allocation fails.  The caller of this function owns the resulting string.

char* fetchline(FILE *f) {
    int pos = 0;
    int sz  = INITIAL_SIZE;
    char *buf = (char*) malloc(sizeof(char) * sz);
    if (buf == NULL) { return NULL; }
    char ch = fgetc(f);
    if (ch == EOF) {
        free(buf);
        return NULL;
    }
    while (ch != '\n') {
        buf = ensure_capacity(buf, &sz, pos);
        if (buf == NULL) { return NULL; }
        buf[pos++] = ch;
        ch = fgetc(f);
    }
    buf = ensure_capacity(buf, &sz, pos);
    if (buf == NULL) { return NULL; }
    buf[pos++] = '\0';
    return buf;
}


// readfile:
// reads the file filename and executes scribbler commands

void readfile(char* filename)
{
  FILE *fp;
  fp = fopen(filename, "r");
  if (fp == NULL){ //checks if the file exists
    printf("The file does not exist!\n");
  }
  else
    {
      char* line=fetchline(fp);
      while(line != NULL){
        char* proc = strtok(line, " ");
        if (strcmp(proc, "forward") == 0){
          double par1 = strtod(strtok(NULL, " "), NULL);
          forward(par1);
        }else if(strcmp(proc, "turn") == 0){
          int par2 = atoi(strtok(NULL, " "));
          char *par3 = strtok(NULL, " ");
          turn(par2, par3);
        }else if(strcmp(proc, "spin") == 0){
          char *par4 = strtok(NULL, " ");
          spin(par4);
        }else if(strcmp(proc, "beep") == 0){
          beep();
        }else if(strcmp(proc, "ditty") == 0){
          ditty();
        }else if(strcmp(proc, "song") == 0){
          song();
        }else{ 
          printf("Not a valid function!\n");
        }
        line= fetchline(fp);
      }
      fclose(fp);
    }
}

// readfile_and_log
// reads the file filename, executes the commands, and log the information into the file logfile

void readfile_and_log(char* filename, char* logfile)
{
  FILE *fp;
  fp = fopen(filename, "r");
  FILE *lg;
  lg = fopen(logfile, "w");
  if (fp == NULL){ //checks if the file exists
    printf("The file does not exist!\n");
  }
  else
    {
      time_t curtime;
      char* line = fetchline(fp);
      while(line != NULL){
    
        time(&curtime);
        int leftlight = rGetLightTxt("left",2);
        int rightlight = rGetLightTxt("right",2);
        int average = (leftlight + rightlight)/2;
        char* proc = strtok(line, " ");
        if (strcmp(proc, "forward") == 0){
          char* temp=strtok(NULL, " ");
          double par1 = strtod(temp, NULL);
          fputs(ctime(&curtime), lg);
          fputs(" ", lg);
          fputs(proc, lg);
          fputs(" ",lg);
          forward(par1);
          fputs(temp, lg);
          fputs(" ", lg);
        }else if(strcmp(proc, "turn") == 0){
          char* temp1 = strtok(NULL, " ");
          int par2 = atoi(temp1);
          char *par3 = strtok(NULL, " ");
          turn(par2, par3);
          fputs(ctime(&curtime), lg);
          fputs(" ", lg);
          fputs(proc, lg);
          fputs(" ",lg);
          fputs(temp1, lg);
          fputs(" ",lg);
          fputs(par3, lg);
          fputs(" ", lg);
        }else if(strcmp(proc, "spin") == 0){
          char *par4 = strtok(NULL, " ");
          spin(par4);
          fputs(ctime(&curtime), lg);
          fputs(" ", lg);
          fputs(proc, lg);
          fputs(" ",lg);
          fputs(par4, lg);
          fputs(" ", lg);
        }else if(strcmp(proc, "beep") == 0){
          beep();
          fputs(ctime(&curtime), lg);
          fputs(" ", lg);
          fputs(proc, lg);
          fputs(" ", lg);
        }else if(strcmp(proc, "ditty") == 0){
          ditty();
          fputs(ctime(&curtime), lg);
          fputs(" ", lg);
          fputs(proc, lg);
          fputs(" ", lg);
        }else if(strcmp(proc, "song") == 0){
          song();
          fputs(ctime(&curtime), lg);
          fputs(" ", lg);
          fputs(proc, lg);
          fputs(" ", lg);
        }else{
          printf("Not a valid function!\n");
        }
        fprintf(lg, "%d %d %d\n",leftlight,rightlight, average);
        line = fetchline(fp);
      }
      fclose(fp);
    }
  fclose(lg);
}

// Main function:

int main(int argc, char** argv)
{
  rConnect("/dev/rfcomm0");

  printf("Please press Enter to start.\n");
  char test[50];
  while(strcmp(test, "\n")!=0){
    fgets(test, 2, stdin);
  }
  char test1[50];
  printf("Please press Enter again to execute the commands.\n");
  while(strcmp(test1, "\n") != 0)
    {
      rMotors(.25, .25);
      fgets(test1, 10, stdin);
    }
  rStop();

  if(argc==2){  // when the user gives a file to read only
    readfile(argv[1]);
      }
  else if(argc==4){  // when the user givers a file to read and to log
    if (strcmp(argv[1], "-log") == 0){
    readfile_and_log(argv[3], argv[2]);
    }
    else{
      printf("erroneous flag\n");
    }
  }

  rForward(1.0,2.0);
  rDisconnect();
  
  return 0;
    
}
