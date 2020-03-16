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
int controlador(devisao *dev,int numeroDivs,Mote *mote){
	char regracp[200];
	char sensename[200];
	char op;//operaçao logica a fazer
	char numero[100];
	
	for(int i=0;i<numeroDivs;i++){//precorre divisoes
		
		for(int j=0;j<dev[i].nregras;j++){//regras da divisao
			int contlogic=0; 
			int res[100];//resultado logico
			int result=1;
			strcpy(regracp,dev[i].regras[j]);//copia a regra
			char *token = strtok(regracp," ");//reparte a regra em pedaços
			#ifdef debug
				printf("Regra %s\n",dev[i].regras[j]);
			#endif//debug
			
			while(token!=NULL){//enquanto existir regras
				#ifdef debug
					printf("Token %s\n",token);
				#endif//debug
				
				if (strcmp(token,"AND")==0 || strcmp(token,"OR")==0 ){//se for AND ou OR
						if(strcmp(token,"OR")==0){// com or o resultado logico anterior nao conta
							res[contlogic]=result;//se a comparaçao a seguir for verdadeira a regra é V						
							contlogic++;
							result=1;
						}	
				}
				
				else{
					int parteNumerica=0;// flag para saber se ja entramos no numero ou nao 
					int contnum=0;// numero de algarismos
					for(int k=0;k<(int)strlen(token);k++){
						if(token[k]!='>'&&token[k]!='<'&&!parteNumerica){//Separa o nome do sens
							sensename[k]=token[k];
							sensename[k+1]='\0';
	
						}	
						else {
							if(token[k]=='>' || token[k]=='<' || token[k]=='='){
								parteNumerica=1;
								op=token[k];	
							}
							else{
								numero[contnum]=token[k];
								numero[contnum+1]='\0';
								contnum++;
							}

						}

					}
					
					#ifdef debug
						if(parteNumerica)
							printf("Regra %s %c %d\n",sensename,op,atoi(numero));
					#endif//debug
						
					//Analizar regras
					if(parteNumerica){
						int contid=0;int conttiposense=0;
						char id[100],tiposense[100];
						for(int k=0;k<(int)strlen(sensename);k++){
							if(isdigit(sensename[k])){
								id[contid]=sensename[k];
								contid++;
							}
							else{
								tiposense[conttiposense]=sensename[k];
								conttiposense++;
							}
	
						}	
						tiposense[conttiposense]='\0';id[contid]='\0';
						#ifdef debug
							printf("Tipo sense %s %d\n",tiposense,result);
						#endif//debug
						if(op=='<'){
							if(strcmp(tiposense,"TEMP")==0){
								if((mote[atoi(id)].temperatura<atoi(numero))&&result)
									result=1;
								else
									result=0;
							}
							if(strcmp(tiposense,"HUM")==0){
								if((mote[atoi(id)].humidade<atoi(numero))&&result)
									result=1;
								else
									result=0;
							}
							if(strcmp(tiposense,"LIGHT")==0){
								if((mote[atoi(id)].humidade<atoi(numero))&&result)
									result=1;
								else
									result=0;
							}
						}
						if(op=='>'){
							if(strcmp(tiposense,"TEMP")==0){
								if((mote[atoi(id)].temperatura>atoi(numero))&&result)
									result=1;
								else
									result=0;
							}
							if(strcmp(tiposense,"HUM")==0){
								if((mote[atoi(id)].humidade>atoi(numero))&&result)
									result=1;
								else
									result=0;
							}
							if(strcmp(tiposense,"LIGHT")==0){
								if((mote[atoi(id)].humidade>atoi(numero))&&result)
									result=1;
								else
									result=0;
							}
						}//if(op)
					}//if(parteNumerica)
					else{
						res[contlogic]=result;
						contlogic++;
						for(int l=0;l<contlogic;l++){
							#ifdef debug
								printf("Avaliaçao logica %d \n",res[l]);
							#endif//debug
							if(res[l]){
								token=strtok(sensename,":");
								#ifdef debug
									printf("Atuador %s \n",token);
								#endif//debug
								for(int k=0;k<dev[i].natuadores;k++){
									if(strcmp(dev[i].atua[k].nome,token)==0){
										token=strtok(NULL,":");	
										strcpy(dev[i].atua[k].estado,token);
										#ifdef debug
											printf("Atuador %s estado %s\n",dev[i].atua[k].nome,dev[i].atua[k].estado);
										#endif//debug
										break;
									}
								}	
								break;
							}
						}						
					}
					
				}//else do if (strcmp(token,"AND")==0 || strcmp(token,"OR")==0 )
				token = strtok(NULL," ");
			}//while(token!=NULL)
		}//For(j)
	}//For(i)
	return 1;
}//fim
