/*****************************************************************/
/*   HAS-A54     |    SINF    |      MIEEC     |     2019/20     */
/*****************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Mote.h"
#include <math.h>
#include "Message.h"
#include "inclu.h"

int ReadMessageConfig(char *nomeFicheiro,MessageT *mes);
/**
*Carrega as configuraçoes das motes
*
*nomeFicheiro - nome do ficheiro de configuaçao
*mes - struct onde a cofiguraçao fica guardada
*
**/

int DecodeS(char *str,MessageT *mes);
/**
*descodifica o parametro s
*
*str - mensagem contendo o vetor s
*mes - struct onde a cofiguraçao fica guardada
*
**/

int DecodeD(char *str,MessageT *mes);
/**
*descodifica o parametro d
*
*str - mensagem contendo a matiz d
*mes - struct onde a cofiguraçao fica guardada
*
**/

int DecodeMessage(char *str,MessageT *mes);
/**
*Descodifica a mensagem 
*
*str - mensagem recebida
*mes - struct onde a cofiguraçao fica guardada
*
**/

int ReadMessageConfig(char *nomeFicheiro,MessageT *mes){
	if(nomeFicheiro==NULL)
		return -1;

	FILE *Ficheiro=fopen(nomeFicheiro,"r");
	if(Ficheiro==NULL){
		printf("Nao abriu o ficheiro\n");
		return -1;
	}
	char buf[200];
	
	while(fgets(buf,200,Ficheiro)!=NULL){
        	//printf("Mensagem a tratar:\n%s\n",buf);
    		
		DecodeMessage(buf,mes);

	}
	fclose(Ficheiro);
	return 1;
}

int DecodeS(char *str,MessageT *mes){
	
	/* [d,d,d] -> 0d,d,d*/
	str[0]='0';
	str[strlen(str)-1]='\0';
	
	  
	char *token = strtok(str,",");
	
	for (int i=0;i<5;i++){

		if(token==NULL)
			break;
		mes->s.sc[i] = atoi(token);
		mes->s.cont = i+1;
		//printf("s[%d] = %d cont = %d\n",i,mes->s.sc[i],mes->s.cont);
		token = strtok(NULL,",");
	}
	return 1;
}	

int DecodeD(char *str,MessageT *mes){
	
	// ['c',d,d,d],['c',d,d,d],['c',d,d,d]]-> ['c',d,d,d],['c',d,d,d],['c',d,d,d]
	str[strlen(str)-1]='\0';
	
	//obter valores  
	char *token = strtok(str,",");
	int cont =0;

	while(token!=NULL){
		mes->d.m[cont].c = token[2];
		//printf("D[%d].c = %c\n",cont,mes->d.m[cont].c);
		token = strtok(NULL,",");
		mes->d.m[cont].s[0] = atof(token);
		//printf("D[%d].s[0] = %f\n",cont,mes->d.m[cont].s[0]);
		token = strtok(NULL,",");
		mes->d.m[cont].s[1] = atof(token);
		//printf("D[%d].s[1] = %f\n",cont,mes->d.m[cont].s[1]);
		token = strtok(NULL,",");	
		mes->d.m[cont].s[2] = atof(token);
		//printf("D[%d].s[2] = %f\n",cont,mes->d.m[cont].s[2]);
		token = strtok(NULL,",");
		cont++;
		mes->d.cont=cont;
	}
	
	return 1;
}	


int DecodeMessage(char *str,MessageT *mes){
	char *token;
	token = strtok(str," ");
	char paramS[200];
	char paramD[200];
	while(token!=NULL){
		switch (token[1]){
			case 'n':
				//printf("Token %s encontrado entrou em '-n'\n",token);
	 			token = strtok(NULL," ");
				mes->n = atoi(token);
				//printf("N = %d\n",mes->n);
				break;
			
			case 'l':
				//printf("Token %s encontrado entrou em '-l'\n",token);
	 			token = strtok(NULL," ");
				mes->l = atoi(token);
				//printf("L = %d\n",mes->l);
				break;	

			case 'c':
				//printf("Token %s encontrado entrou em '-c'\n",token);
	 			token = strtok(NULL," ");
				mes->c = atoi(token);
				//printf("C = %d\n",mes->c);
				break;	

			case 'f':
				//printf("Token %s encontrado entrou em '-f'\n",token);
	 			token = strtok(NULL," ");
				mes->f = atoi(token);
				//printf("F = %d\n",mes->f);
				break;	

			case 'i':
				//printf("Token %s encontrado entrou em '-i'\n",token);
	 			token = strtok(NULL," ");
				mes->i = atoi(token);
				//printf("I = %d\n",mes->i);
				break;	
			
			case 's':
				//printf("Token %s encontrado entrou em '-s'\nDecode no fim\n",token);
	 			token = strtok(NULL," ");
				strcpy(paramS,token);
				break;
			
			case 'd':	
				//printf("Token %s encontrado entrou em '-d'\nDecode no fim\n",token);
	 			token = strtok(NULL," ");
				strcpy(paramD,token+1);
				break;
		}
		token=strtok(NULL," ");
	}
	//printf("Decode S\n");
	DecodeS(paramS,mes);
	//printf("Decode D\n");	
	DecodeD(paramD,mes);
return 1;

}
