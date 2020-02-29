

int hex2dec(char p1,char p2,char p3,char p4){
    char *ptr;
    char aux2[4];
    aux2[0]=p1;aux2[1]=p2;aux2[2]=p3;aux2[3]=p4;
    return (int)strtol(aux2,ptr,16);
}