/*****************************************************************/
/*   HAS-A54     |    SINF    |      MIEEC     |     2019/20     */
/*****************************************************************/

#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Mote.h"
#include <math.h>
#include "Message.h"
#include "inclu.h"
#include "Deviso.h"
//#define debug

int devConfig(char *filename,devisao *dev,int *numeroDivs,Mote *mote){
	if(filename==NULL){
		printf("Nome do ficheiro foi NULL\n");
		return -1;
	}
	FILE *Ficheiro=fopen(filename,"r");
	if(Ficheiro==NULL){
		printf("Nao conseguio abrir o ficheiro\n");

	}
	char *token;
	int contdiv=0;	
	char buff[300],sensores[300],atuadores[300];
	while(fgets(buff,300,Ficheiro)!=NULL){
		token = strtok(buff,":");//Retira o nome da divisao
		strcpy(dev[contdiv].nome,token);
		#ifdef debug
			printf("Nome da divisao %d -> %s\n",contdiv,dev[contdiv].nome);
		#endif//debug
		token = strtok(NULL,":");//Retira todos os sensores
		strcpy(sensores,token);
		#ifdef debug
			printf("Nome dos sensores %s\n",sensores);
		#endif//debug
		token = strtok(NULL,":");//Retira todos os Atuadores
		strcpy(atuadores,token);
		#ifdef debug
			printf("Nome dos atuadores %s\n",atuadores);
		#endif//debug

		
		token = strtok(atuadores,",");//Separar atuadores
		int natuadores =0;
		while(token!=NULL){
				strcpy(dev[contdiv].atua[natuadores].nome,token);
				strcpy(dev[contdiv].atua[natuadores].estado,"OFF\0");		
				token = strtok(NULL,",");
				natuadores++;
		}
		dev[contdiv].atua[natuadores-1].nome[strlen(dev[contdiv].atua[natuadores-1].nome)-1]='\0';
		dev[contdiv].natuadores=natuadores;
		#ifdef debug
		for(int i=0;i<dev[contdiv].natuadores;i++){
				printf("Atuador %s Estado %s\n",dev[contdiv].atua[i].nome,dev[contdiv].atua[i].estado);
		}
		#endif//debug	
		
		int contsensor = 0;
		char id[10];	
		char tiposense[10];	
		token = strtok(sensores,",");
		while(token!=NULL){
			int contid=0;
			int conttiposense=0;
			for(int i=0;i<(int)strlen(token);i++){
				if(isdigit(token[i])){
					id[contid]=token[i];
					contid++;
				}
				else{
					tiposense[conttiposense]=token[i];
					conttiposense++;
				}

			}
			tiposense[conttiposense]='\0';id[contid]='\0';
			#ifdef debug
				printf("Tipo sensor %s id %d\n",tiposense,atoi(id));
			#endif//debug
		
			strcpy(dev[contdiv].sens[contsensor].nome,token);
			strcpy(dev[contdiv].sens[contsensor].senstipo,tiposense);
			dev[contdiv].sens[contsensor].id=atoi(id);
			token = strtok(NULL,",");
			contsensor++;
		}
		dev[contdiv].nregras=0;
		contdiv++;
	}
fclose(Ficheiro);
*numeroDivs=contdiv;
	return 1;
}


int devRules(char *filename,devisao *dev,int numeroDivs){
	
	if(filename==NULL){
		printf("Nome do ficheiro foi NULL\n");
		return -1;
	}
	FILE *Ficheiro=fopen("Rules.txt","r");
	if(Ficheiro==NULL){
		printf("Nao abriu o ficheiro\n");
		return -1;
	}
	char buff[200],regra[200],*token;
		#ifdef debug
			printf("Numero de divisoes %d\n",numeroDivs);
		#endif//debug
	while(fgets(buff,200,Ficheiro)!=NULL){
		strcpy(regra,buff);	
		token = strtok(buff,":");
		#ifdef debug
			printf("Regra %s\n",regra);
		#endif//debug
		#ifdef debug
			printf("Nome div %s %s\n",token,dev[0].nome);
		#endif//debug
		for(int i=0;i<numeroDivs;i++){
			if(strcmp(dev[i].nome,token)==0){
				strcpy(dev[i].regras[dev[i].nregras],regra+(int)strlen(token)+1);
				dev[i].regras[dev[i].nregras][strlen(dev[i].regras[dev[i].nregras])-1]='\0';
				dev[i].nregras++;
				break;			
			}
			
		}
	}

	#ifdef debug
	for(int i=0;i< numeroDivs;i++){
		printf("entrei\n");
		for(int j=0;j<dev[i].nregras;j++){
			printf("Divisao %s Regra %s\n",dev[i].nome,dev[i].regras[j]);	
		}
	}
	#endif//debug
	return 1;
}
