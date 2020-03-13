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

/*
void controlador(Mote motelida){
FILE *Ficheiro;

		if(motelida.temperatura<4 && !flag){
		
	
			sprintf(buf,
"-n %d -l %d -f %d -c %d -s [%d,%d,%d] -d [['%c',%.1f,%.1f,%.1f],['%c',%.1f,%.1f,%d],['%c',%.1f,%.1f,%.0f]] -i %d",
mes.n,
mes.l,
mes.f,
mes.c,
mes.s.sc[0],mes.s.sc[1],mes.s.sc[2],
mes.d.m[0].c,mes.d.m[0].s[0],mes.d.m[0].s[1],mes.d.m[0].s[2],
mes.d.m[1].c,mes.d.m[1].s[0],mes.d.m[1].s[1],1,
mes.d.m[2].c,mes.d.m[2].s[0],mes.d.m[2].s[1],mes.d.m[2].s[2],
mes.i);
			Ficheiro=fopen("MsgCreatorConf.txt","w+");
			if(Ficheiro==NULL){
				printf("Nao abriu o ficheiro\n");

			}
			printf("Buf if = %s\n %d %d",buf,(int)sizeof(buf),(int)strlen(buf));
			fwrite(buf,1,(int)strlen(buf),Ficheiro);
			fclose(Ficheiro);
flag=1;
flag2=0;
		}
if(motelida.temperatura>4 && !flag2){
flag2=1;
flag=0;
sprintf(buf,
"-n %d -l %d -f %d -c %d -s [%d,%d,%d] -d [['%c',%.1f,%.1f,%.1f],['%c',%.1f,%.1f,%d],['%c',%.1f,%.1f,%.0f]] -i %d",
mes.n,
mes.l,
mes.f,
mes.c,
mes.s.sc[0],mes.s.sc[1],mes.s.sc[2],
mes.d.m[0].c,mes.d.m[0].s[0],mes.d.m[0].s[1],mes.d.m[0].s[2],
mes.d.m[1].c,mes.d.m[1].s[0],mes.d.m[1].s[1],-1,
mes.d.m[2].c,mes.d.m[2].s[0],mes.d.m[2].s[1],mes.d.m[2].s[2],
mes.i);
Ficheiro=fopen("MsgCreatorConf.txt","w+");
	if(Ficheiro==NULL){
		printf("Nao abriu o ficheiro\n");

	}
			printf("Buf else = %s %d %d\n",buf,(int)sizeof(buf),(int)strlen(buf));
			
			fwrite(buf,1,(int)strlen(buf),Ficheiro);
fclose(Ficheiro);

}


}*/

int main(){
	char message[2555];
	Mote motelida,mote[500];
	MessageT mes;
	devisao dev[40];
	int numeroDivs;
	char trash[255];
	ReadMessageConfig("MsgCreatorConf.txt", &mes);
	devConfig("DevConfig.txt",dev,&numeroDivs,mote);
	devRules("Rules.txt",dev,numeroDivs);
	fgets(trash,255,stdin);
	for(int i=0;i<mes.n;i++){
		ReadMotes(message,&motelida);
		mote[motelida.ID].temperatura=motelida.temperatura;
		mote[motelida.ID].humidade=motelida.humidade;
		mote[motelida.ID].luminosidade=motelida.luminosidade;
	}
	//int flag=0;
	//int flag2=0;
	printf("temperatura %f\n",mote[1].temperatura);
	printf("temperatura %f\n",mote[2].temperatura);
	printf("temperatura %f\n",mote[3].temperatura);
	char buf[100][100];
	char buf2[100];
	 char buf4[100];
	char buf3[100];
	char op;

	while(1){
		printf("temperatura %f id %d\n",mote[dev[0].sens[1].id].temperatura,dev[0].sens[1].id);
		for(int i=0;i<numeroDivs;i++){
			for(int j=0;j<dev[i].nregras;j++){
				int result=1;
				printf("Regra %s \n",dev[i].regras[j]);
				printf("atr %s\n",dev[0].atua[0].nome);
				strcpy(buf2,dev[i].regras[j]);
				char *token = strtok(buf2," ");
				while(token!=NULL){
					printf("toke %s \n",token); 
					
					if (strcmp(token,"AND")==0 || strcmp(token,"OR")==0 ){
						if(strcmp(token,"OR")==0)
							result=1;	
					}
					else{
					int flag=0;
					int cooont=0;
					for(int t=0;t<strlen(token);t++){
						if(token[t]!='>'&&token[t]!='<'&&!flag){
							buf3[t]=token[t];
							buf3[t+1]='\0';
								printf("aqui %c\n",token[t]);
							
						}
						else {
							if(token[t]=='>' || token[t]=='<'){
								flag=1;
								op=token[t];	
								printf("aqui2\n");
							}
							else{
								buf4[cooont]=token[t];
								buf4[cooont+1]='\0';
								printf("aqui3\n");
								cooont++;
							}
						}
					}
					printf("teste %s %c %d\n",buf3,op,atoi(buf4));
					int contid=0;int conttiposense=0;
					char id[10],tiposense[100];
					for(int r=0;r<strlen(buf3);r++){
							if(isdigit(buf3[r])){
								id[contid]=buf3[r];
								contid++;
							}
						else{
							tiposense[conttiposense]=buf3[r];
							conttiposense++;
							}

						}
						tiposense[conttiposense]='\0';id[contid]='\0';
						printf("%s \n",tiposense);
					if(flag!=0 && op=='<'){
						
						if(strcmp(tiposense,"TEMP")==0){
							if(mote[atoi(id)].temperatura<atoi(buf4))
									result=1;
							else
								result=0;
						}
						if(strcmp(tiposense,"HUM")==0){
							if(mote[atoi(id)].humidade<atoi(buf4))
									result=1;
							else
								result=0;
						}
						if(strcmp(tiposense,"LIGHT")==0){
							if(mote[atoi(id)].humidade<atoi(buf4))
									result=1;
							else
								result=0;
						}
						
					}
					if(flag!=0 && op=='>'){
						
						if(strcmp(tiposense,"TEMP")==0){
							if((mote[atoi(id)].temperatura>atoi(buf4))&&result)
								result=1;
							else
								result=0;
						}
						if(strcmp(tiposense,"HUM")==0){
							if(mote[atoi(id)].humidade>atoi(buf4))
									result=1;
							else
								result=0;
						}
						if(strcmp(tiposense,"LIGHT")==0){
							if(mote[atoi(id)].humidade>atoi(buf4))
									result=1;
							else
								result=0;
						}
						
					}
					
					}
					token = strtok(NULL," ");	
				}
				printf("result %d\n ",result);	
			}
		}
		ReadMotes(message,&motelida);
		mote[motelida.ID].temperatura=motelida.temperatura;
		mote[motelida.ID].humidade=motelida.humidade;
		mote[motelida.ID].luminosidade=motelida.luminosidade;
	}

return 0;
}
