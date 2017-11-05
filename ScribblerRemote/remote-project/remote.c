#include <stdio.h>
#include "commands.h"
#include <string.h>
#include <MyroC.h>

void readcmd(char *str,int *a){
	char c;
	int i =0;
	while ((c=fgetc(stdin))!=' ' && c!='\n' && i<15){
		str[i]=c;
		i++;
	}
	str[i]='\0';
	if (c==' '){
		scanf("%d",a);
                while ((c=fgetc(stdin))!='\n');
	}
}

int main(void){

	char cmd[15];
	int par;

        rConnect("/dev/rfcomm0");
        
	while (strcmp(cmd,"quit")){
		par = -1;
		printf("Enter a command: ");
		readcmd(cmd,&par);
		printf("You entered %s\n",cmd);
		printf("Par is %d\n",par);

		if(!strcmp(cmd,"turnaround")) turnaround();
		else if(!strcmp(cmd,"sing")) sing();
		else if(!strcmp(cmd,"rightangleleft")) rightangleleft();
		else if(!strcmp(cmd,"rightangleright")) rightangleright();
		else if(!strcmp(cmd,"backandforth")) backandforth();

		else if(!strcmp(cmd,"forward"))
		{
			if(par==-1) printf("Lack parameter!\n");
			else forward(par);
		}
		else if(!strcmp(cmd,"backward"))
		{
			if(par==-1) printf("Lack parameter!\n");
			else backward(par);
		}
		else if(!strcmp(cmd,"turnleft"))
		{
			if(par==-1) printf("Lack parameter!\n");
			else turnleft(par);
		}
		else if(!strcmp(cmd,"turnright"))
		{
			if(par==-1) printf("Lack parameter!\n");
			else turnright(par);
		}
		else if(!strcmp(cmd,"beep"))
		{
			if(par==-1) printf("Lack parameter!\n");
			else beep(par);
		}
		else if(!strcmp(cmd,"help"))help();
		else if(!strcmp(cmd,"quit"));
		else printf("Invalid command!\n");
	}

        rDisconnect();
	quit();

	return 0;
}
