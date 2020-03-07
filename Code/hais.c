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



int main(){
	char message[255];
	Mote motelida;
	Mote mote[500];
	MessageT mes;
	ReadMessageConfig("MsgCreatorConf.txt", &mes);

	while(1){
		ReadMotes(message,&motelida);
		mote[motelida.ID]=motelida;
		//controlo

	}

return 0;

}
