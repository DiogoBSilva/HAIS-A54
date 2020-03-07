/*****************************************************************/
/*   HAS-A54     |    SINF    |      MIEEC     |     2019/20     */
/*****************************************************************/

/**
*
*Esta biblioteca inclui todas os prototipos das funções do sistema
*
**/
/**
*ReadConfig
**/
int Hex2Dec(char p1,char p2,char p3,char p4);
int ReadMessageConfig(char *nomeFicheiro,MessageT *mes);
int DecodeS(char *str,MessageT *mes);
int DecodeD(char *str,MessageT *mes);
int DecodeMessage(char *str,MessageT *mes);

/**
*LerSensor
**/
void ReadMotesMessage(char *message);
int hex2dec(char p1,char p2,char p3,char p4);
void DataConverter(char *message,Mote *mote);
void ReadMotes(char *message,Mote *mote);
