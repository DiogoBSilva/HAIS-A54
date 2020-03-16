/*****************************************************************/
/*   HAS-A54     |    SINF    |      MIEEC     |     2019/20     */
/*****************************************************************/
#ifndef DEVISO
typedef struct{
	char nome[15];
	char estado[5];
	char estadoreal[5];
}atuadores;
typedef struct{
	char nome[15];
	char senstipo[15];
	int id;
	//Mote *mo;
}sensor;
typedef struct{
	sensor sens[50];
	atuadores atua[50];
	char regras[200][200];
	char nome[20];
	int nregras;
	int natuadores;
	int nsensores;
}devisao;
#define DEVISO
#endif
