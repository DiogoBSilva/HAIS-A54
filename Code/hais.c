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

void controlador(Mote motelida){



}

int main(){
	char message[2555];
	Mote motelida;
	//Mote mote[500];
	MessageT mes;
	ReadMessageConfig("MsgCreatorConf.txt", &mes);
	FILE *Ficheiro;
	int flag=0;
	int flag2=0;
	while(1){
		ReadMotes(message,&motelida);
		char buf[50];
		//mote[motelida.ID]=motelida;
		


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

	}

return 0;

}
