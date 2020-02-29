/*****************************************************************/
/*   HAS-A54     |    SINF    |      MIEEC     |     2019/20     */
/*****************************************************************/

#include <stdio.h>
#include "Mote.h"
#include <math.h>
/**
 * Le as mensagens das motes e guarda na variavel mesage
 * 
 * Message - apontador para apontador, guarda as mensagens de todas as motes
 * n - Numero de motes
 * */
void ReadMotes(char **message ,int n){
    char trash[80];
    fgets(trash,80,stdin);
    for(int i=0;i<n;i++)
        fgets(message[i],80,stdin);
}

void DataConverter(char *message,Mote *mote){
    mote->ID=hex2dec(message[15],message[16],message[18],message[19]);
    mote->temperatura=hex2dec(message[48],message[49],message[51],message[52])*0.01-39.6;
    mote->humidade=hex2dec(message[54],message[55],message[57],message[58])*0.0367-2.0468-1.5955*pow(10,-6)*pow(hex2dec(message[54],message[55],message[57],message[58]),2);
    mote->luminosidade=0.625*pow(10,6)*(hex2dec(message[36],message[37],message[39],message[40])/4096)*(1.5/100000)*1000;
}


int main(){


}
