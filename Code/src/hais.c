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

			printf("Buf else = %s %d %d\n",buf,(int)sizeof(buf),(int)strlen(buf));
			
			fwrite(buf,1,(int)strlen(buf),Ficheiro);
fclose(Ficheiro);

}


}*/

int main(){
	char message[255];
	Mote motelida,mote[500];
	MessageT mes;
	MessageT mes2;
	devisao dev[40];
	int numeroDivs;
	char trash[255];
	ReadMessageConfig("./Simuladores/sim2/MsgCreatorConf.txt", &mes);
	ReadMessageConfig("./Simuladores/sim1/MsgCreatorConf.txt", &mes2);
	devConfig("./src/DevConfig.txt",dev,&numeroDivs);
	devRules("./src/Rules.txt",dev,numeroDivs);
	fgets(trash,255,stdin);
	for(int i=0;i<mes.n;i++){
		ReadMotes(message,&motelida);
		mote[motelida.ID].temperatura=motelida.temperatura;
		mote[motelida.ID].humidade=motelida.humidade;
		mote[motelida.ID].luminosidade=motelida.luminosidade;
	}
	controlador(dev,numeroDivs,mote);
	while(1){
		//printf("temperatura %f id %d\n",mote[dev[0].sens[1].id].temperatura,dev[0].sens[1].id);
		for(int i=0;i<mes.n+1;i++){
			ReadMotes(message,&motelida);
			mote[motelida.ID].temperatura=motelida.temperatura;
			mote[motelida.ID].humidade=motelida.humidade;
			mote[motelida.ID].luminosidade=motelida.luminosidade;
		}
		controlador(dev,numeroDivs,mote);
		
		FILE *Ficheiro;
		int flag=0;
		int flag2=0;
		char buf[200];
		if(mote[5].temperatura<5 && !flag){
		
	
			sprintf(buf,"-n %d -l %d -f %d -c %d -s [%d,%d,%d] -d [['%c',%.1f,%.1f,%.1f],['%c',%.1f,%.1f,%d],['%c',%.1f,%.1f,%d]] -i %d",mes2.n,mes2.l,mes2.f,mes2.c,mes2.s.sc[0],mes2.s.sc[1],mes2.s.sc[2],mes2.d.m[0].c,mes2.d.m[0].s[0],mes2.d.m[0].s[1],mes2.d.m[0].s[2],mes2.d.m[1].c,mes2.d.m[1].s[0],mes2.d.m[1].s[1],1,mes2.d.m[2].c,mes2.d.m[2].s[0],mes2.d.m[2].s[1],(int)mes2.d.m[2].s[2],mes2.i);
			Ficheiro=fopen("./Simuladores/sim1/MsgCreatorConf.txt","w+");
			if(Ficheiro==NULL){
				printf("Nao abriu o ficheiro\n");
			}
			//printf("liga\n");
			//printf("Buf if = %s\n %d %d",buf,(int)sizeof(buf),(int)strlen(buf));
			fwrite(buf,1,(int)strlen(buf),Ficheiro);
			fclose(Ficheiro);
			flag=1;
			flag2=0;
		}
		if(mote[5].temperatura>5 && !flag2){
flag2=1;
//printf("desliga\n");
flag=0;
sprintf(buf,
"-n %d -l %d -f %d -c %d -s [%d,%d,%d] -d [['%c',%.1f,%.1f,%.1f],['%c',%.1f,%.1f,%d],['%c',%.1f,%.1f,%d]] -i %d",
mes2.n,
mes2.l,
mes2.f,
mes2.c,
mes2.s.sc[0],mes2.s.sc[1],mes2.s.sc[2],
mes2.d.m[0].c,mes2.d.m[0].s[0],mes2.d.m[0].s[1],mes2.d.m[0].s[2],
mes2.d.m[1].c,mes2.d.m[1].s[0],mes2.d.m[1].s[1],-1,
mes2.d.m[2].c,mes2.d.m[2].s[0],mes2.d.m[2].s[1],(int)mes2.d.m[2].s[2],
mes2.i);
Ficheiro=fopen("./Simuladores/sim1/MsgCreatorConf.txt","w+");
	if(Ficheiro==NULL){
		printf("Nao abriu o ficheiro\n");

	}
			//printf("Buf else = %s %d %d\n",buf,(int)sizeof(buf),(int)strlen(buf));
			
			fwrite(buf,1,(int)strlen(buf),Ficheiro);
fclose(Ficheiro);

		}




		for(int i=0;i<numeroDivs;i++){
			for(int j=0;j<dev[i].natuadores;j++){
				if(strcmp(dev[i].atua[j].estado,dev[i].atua[j].estadoreal)!=0){
					printf("atuador da devisao %s passou de %s a %s\n",dev[i].nome,dev[i].atua[j].estadoreal,dev[i].atua[j].estado);
					strcpy(dev[i].atua[j].estadoreal,dev[i].atua[j].estado);
				}
			}
		}
	
	}

return 0;
}
