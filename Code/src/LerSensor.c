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
void ReadMotesMessage(char *message);
/**
 * Le as mensagens das motes e guarda na variavel mesage
 * 
 * Message - apontador guarda a mensagem da mote
 *
 * */

int hex2dec(char p1,char p2,char p3,char p4);
/**
*Convete 4 valores hexadecimais em decimal
*
*p1 - Char, primeiro hexadecimal
*p2 - Char, segundo hexadecimal
*p3 - Char, terceio hexadecimal
*p4 - Char, quarto hexadecimal
*
*/

void DataConverter(char *message,Mote *mote);
/**
*Converte os valores em hexadecimal para os valores fisicos
*
*message - mensagem da mote
*mote - struct contendo os valores da mote
*/
void ReadMotes(char *message,Mote *mote);
/**
*Le as motes e converte para os seu valores fisicos 
*
*message - mensagem da mote
*mote - struct contendo os valores da mote
*/
void ReadMotesMessage(char *message){
        fgets(message,255,stdin);
	//printf("Mensage lida %s\n",message);
}

void DataConverter(char *message,Mote *mote){
	//ID
	mote->ID=hex2dec(message[15],message[16],message[18],message[19]);
	//printf("Mote id= %d\n",mote->ID);
	
	//Temperatura
	float dec=(float)hex2dec(message[48],message[49],message[51],message[52]);
	float temp=(dec)*0.01-39.6;
	mote->temperatura= (dec)*0.01-39.6;
	//printf("Temperatura real = %f\n",mote->temperatura);
	
	//humidade
	dec=hex2dec(message[54],message[55],message[57],message[58]);
    float humidade= 0.036700*dec-1.59550*0.0000010*dec*dec-2.04680;
	//printf("Humidade sem compesar = %f\n",humidade);
	
	mote->humidade=(temp-25)*(0.01+0.00008*dec)+humidade;
	//printf("Humidade real = %f\n",mote->humidade);

	//Luz
	dec=hex2dec(message[36],message[37],message[39],message[40]);
	//printf("dec = %d\n",dec);
	mote->luminosidade=0.625*pow(10,6)*((dec*1.0)/4096.0)*(1.5/100000)*1000;
	//printf("Luz real %f\n",mote->luminosidade);
}

int hex2dec(char p1,char p2,char p3,char p4){
    char *ptr;
    char aux2[4];
    aux2[0]=p1;aux2[1]=p2;aux2[2]=p3;aux2[3]=p4;
    return (int)strtol(aux2,&ptr,16);
}
void ReadMotes(char *message,Mote *mote){
	ReadMotesMessage(message);
	DataConverter(message,mote);
}


