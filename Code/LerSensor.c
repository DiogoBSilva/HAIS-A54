/*****************************************************************/
/*   HAS-A54     |    SINF    |      MIEEC     |     2019/20     */
/*****************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Mote.h"
#include <math.h>
/**
 * Le as mensagens das motes e guarda na variavel mesage
 * 
 * Message - apontador para apontador, guarda as mensagens de todas as motes
 * n - Numero de motes
 * */
void ReadMotes(char *message ,int n){
    char trash[80];
    fgets(trash,80,stdin);
    for(int i=0;i<n;i++)
        fgets(message,80,stdin);

}
int hex2dec(char p1,char p2,char p3,char p4);
void DataConverter(char *message,Mote *mote){
    mote->ID=hex2dec(message[15],message[16],message[18],message[19]);
    mote->temperatura=hex2dec(message[48],message[49],message[51],message[52])*0.01-39.6;
    mote->humidade=hex2dec(message[54],message[55],message[57],message[58])*0.0367-2.0468-1.5955*pow(10,-6)*pow(hex2dec(message[54],message[55],message[57],message[58]),2);
    mote->luminosidade=0.625*pow(10,6)*(hex2dec(message[36],message[37],message[39],message[40])/4096)*(1.5/100000)*1000;
}

int hex2dec(char p1,char p2,char p3,char p4){
    char *ptr;
    char aux2[4];
    aux2[0]=p1;aux2[1]=p2;aux2[2]=p3;aux2[3]=p4;
    return (int)strtol(aux2,&ptr,16);
}

int main(){
	char message[80];
	Mote mote;
	ReadMotes(message ,1);
	DataConverter(message,&mote);
	printf("Temperatura %f\n",mote.temperatura);
char buf[200];
 	FILE *Ficheiro=fopen("MsgCreatorConf.txt","r");
 while(fgets(buf,200,Ficheiro)!=NULL){
        printf("%s %d\n",buf,(int)strlen(buf));
    }
    fclose(Ficheiro);
	char *token;
token = strtok(buf," ");
while(token!=NULL){
switch (token[1]){
	case 'n':
		printf("%s\n",token);
	 	token = strtok(NULL," ");
		printf("%d\n",atoi(token));
		break;	
	case 'l':
		printf("%s\n",token);
	 	token = strtok(NULL," ");
		printf("%d\n",atoi(token));
		break;	
	case 'c':
		printf("%s\n",token);
	 	token = strtok(NULL," ");
		printf("%d\n",atoi(token));
		break;	
	case 'f':
		printf("%s\n",token);
	 	token = strtok(NULL," ");
		printf("%d\n",atoi(token));
		break;
	case 'i':
		printf("%s\n",token);
	 	token = strtok(NULL," ");
		printf("%d\n",atoi(token));
		break;	
	case 's':
		printf("%s\n",token);
	 	token = strtok(NULL," ");
		printf("%s\n",token);

		/*char aux[80];
		strcpy(aux,token);
		aux[0]='0';
		aux[strlen(aux)-1]='\0';
		char *aux2;
		aux2 = strtok(aux,",");
		printf("%d\n",atoi(aux2));
		aux2 = strtok(NULL,",");
		printf("%d\n",atoi(aux2));
		aux2 = strtok(NULL,",");
		printf("%d\n",atoi(aux2));*/
		break;		
case 'd':
		printf("%s\n",token);
	 	token = strtok(NULL," ");
		printf("%s\n",token);
		//char aux[80];
		//strcpy(aux,token+2);
		//aux[strlen(aux)-2]='\0';
		//printf("%s\n",aux);
		/*char *aux2;
		aux2 = strtok(aux,",");
		printf("%s\n",aux2);
		aux2 = strtok(NULL,",");
		printf("%f\n",atof(aux2));
		aux2 = strtok(NULL,",");
		printf("%f\n",atof(aux2));
		aux2 = strtok(NULL,",");
		printf("%f\n",atof(aux2));
		aux2 = strtok(NULL,",");
		printf("%s\n",aux2);
		aux2 = strtok(NULL,",");
		printf("%f\n",atof(aux2));
		aux2 = strtok(NULL,",");
		printf("%f\n",atof(aux2));
		aux2 = strtok(NULL,",");
		printf("%f\n",atof(aux2));
aux2 = strtok(NULL,",");
		printf("%s\n",aux2);
		aux2 = strtok(NULL,",");
		printf("%f\n",atof(aux2));
		aux2 = strtok(NULL,",");
		printf("%f\n",atof(aux2));
		aux2 = strtok(NULL,",");
		printf("%f\n",atof(aux2));
		*/
		break;			
}

token=strtok(NULL," ");
}
}
