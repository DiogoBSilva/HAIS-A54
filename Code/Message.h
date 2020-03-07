/*****************************************************************/
/*   HAS-A54     |    SINF    |      MIEEC     |     2019/20     */
/*****************************************************************/

typedef struct{
	int cont;
	int sc[5];
} vec;

typedef struct{
	char c;
	float s[3];
} vec2;

typedef struct{
	vec2 m[5];
} matrix;

typedef struct{
	int n;
	int l;
	int f;
   	int c;
	int i;
	vec s;
	matrix d;
} MessageT;
