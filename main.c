#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pInicial[64]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,
                12,4,62,54,46,38,30,22,14,6,64,56,48,
                40,32,24,16,8,57,49,41,33,25,17,9,1,
                59,51,43,35,27,19,11,3,61,53,45,37,29,
                21,13,5,63,55,47,39,31,23,15,7};
int tEliminacionP[56]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,
                     10,2,59,51,43,35,27,19,11,3,60,52,44,
                     36,63,55,47,39,31,23,15,7,62,54,46,38,
                     30,22,14,6,61,53,45,37,29,21,13,5,28,
                     20,12,4};
int tCompresionC[48]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,
                    12,4,26,8,16,7,27,20,13,2,41,52,31,
                    37,47,55,30,40,51,45,33,48,44,49,39,56,
                    34,53,46,42,50,36,29,32};
int cPExpansion[48]={32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,
                   12,13,12,13,14,15,16,17,16,17,18,14,20,
                   21,20,21,22,23,24,25,24,25,26,27,28,29,
                   28,29,30,31,32,1};
int cS4[4][16]={7,13,14,3,0,6,9,10,1,2,8,5,
                11,12,4,15,13,8,11,5,6,15,0,3,
                4,7,2,12,1,10,14,9,10,6,9,0,
                12,11,7,13,15,1,3,14,5,2,8,
                4,3,15,0,6,10,1,13,8,9,4,5,
                11,12,7,2,14};
int tPermutaD[32]={16,7,20,21,29,12,28,17,1,15,23,26,5,18,
                   31,10,2,8,24,14,32,27,3,9,19,13,30,6,
                   22,11,4,25};
int pFinal[64]={40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,
                31,38,6,46,14,54,22,62,30,37,5,45,13,53,
                21,61,29,36,4,44,12,52,20,60,28,35,3,43,
                11,51,19,59,27,34,2,42,10,50,18,58,26,
                33,1,41,9,49,17,57,25};
char cero[4]={'0','0','0','0'};
char uno[4]={'0','0','0','1'};
char dos[4]={'0','0','1','0'};
char tres[4]={'0','0','1','1'};
char cuatro[4]={'0','1','0','0'};
char cinco[4]={'0','1','0','1'};
char seis[4]={'0','1','1','0'};
char siete[4]={'0','1','1','1'};
char ocho[4]={'1','0','0','0'};
char nueve[4]={'1','0','0','1'};
char A[4]={'1','0','1','0'};
char B[4]={'1','0','1','1'};
char C[4]={'1','1','0','0'};
char D[4]={'1','1','0','1'};
char E[4]={'1','1','1','0'};
char F[4]={'1','1','1','1'};

void menu();

//Binario a decimal
unsigned long long binToDec(int *Bin, int tam){
    int decimal=0;
    int mult=1;//multiplicador
    int caracter;
    for(int i=tam-1;i>=0;i--){
        caracter=Bin[i];
        if(caracter==1)
            decimal+=mult;
        mult=mult*2;
    }
    return decimal;
}

int main() {
    menu();
    return 0;
}

void menu(){
    int opc;
    char entrada[16];
    int eBin[64],x=0;
    int permutation[64];
    int PerFin[64];
    int key[56];
    int lPermutation[32],rPermutation[32];
    while(opc!=5){
        printf("\t\t ***** Menu *****\n");
        printf("1.-Ingresar dato\n2.-Cajas P\n3.-Generador de claves\n4.-Cajas S\n5.-Salir\n");
        fflush(stdin);
        scanf("%i",&opc);
        fflush(stdin);
        switch(opc){
            case 1:
                //Hexadecimal a binario
                printf("Ingrese 16 caracteres Hexadecimales: ");
                fgets(entrada,17,stdin);
                for(int i=0;i<strlen(entrada);i++){
                    if(entrada[i]=='0'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(cero[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='1'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(uno[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='2'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(dos[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='3'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(tres[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='4'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(cuatro[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='5'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(cinco[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='6'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(seis[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='7'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(siete[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='8'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(ocho[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='9'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(nueve[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='A' || entrada[i]=='a'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(A[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='B' || entrada[i]=='b'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(B[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='C' || entrada[i]=='c'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(C[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='D' || entrada[i]=='d'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(D[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='E' || entrada[i]=='e'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(E[j]-'0');
                            x++;
                        }
                    }else if(entrada[i]=='F' || entrada[i]=='f'){
                        for(int j=0;j<4;j++){
                            eBin[x]=(F[j]-'0');
                            x++;
                        }
                    }
                }
                printf("La tabla de entrada es: \n");
                for(int i=0;i<64;i++){
                    printf("%i ",eBin[i]);
                    if(i==7||i==15||i==23||i==31||i==39||i==47||i==55||i==63)
                        printf("\n");
                }
                break;
            case 2:
                printf("\t\t +++++ Menu de permutaciones +++++\n");
                int opc2;
                while(opc2!=3){
                    printf("1.-Permutacion inicial\n2.-Permutacion final\n3.-Salir\n");
                    fflush(stdin);
                    scanf("%i",&opc2);
                    fflush(stdin);
                    switch(opc2){
                        case 1:
                            //Permutación Inicial
                            for(int i=0;i<64;i++)
                                permutation[i]=eBin[pInicial[i]-1];
                            printf("Tabla de permutacion inicial\n");
                            for(int i=0;i<64;i++){
                                printf("%i ",permutation[i]);
                                if(i==7||i==15||i==23||i==31||i==39||i==47||i==55||i==63)
                                    printf("\n");
                            }
                            break;
                        case 2:
                            //Permutación final
                            for(int i=0;i<64;i++)
                                PerFin[i]=permutation[pFinal[i]-1];
                            printf("Tabla de permutacion final\n");
                            for(int i=0;i<64;i++){
                                printf("%i ",PerFin[i]);
                                if(i==7||i==15||i==23||i==31||i==39||i==47||i==55||i==63)
                                    printf("\n");
                            }
                            break;
                        case 3:
                            break;
                    }
                }
            case 3:
                //Llave
                //Eliminamos la periodicidad
                for(int i=0;i<56;i++){
                    key[i]=eBin[tEliminacionP[i]-1];
                    //printf("%i\n",key[i]);
                }
                int L[28],R[28];
                //L y R
                for(int i=0;i<28;i++){
                    L[i]=key[i];
                    R[i]=key[28+i];
                    //printf("%i\t%i\n",L[i],R[i]);
                }
                //Recorrimientos
                //L y R
                int auxL=0, auxR=0;
                for(int i=0;i<28;i++){
                    if(i==0) {
                        auxL=L[i];
                        auxR=R[i];
                        L[i]=L[i+1];
                        R[i]=R[i+1];
                    }else if(i==27) {
                        L[i]=auxL;
                        R[i]=auxR;
                    }else{
                        L[i]=L[i+1];
                        R[i]=R[i+1];}
                    //printf("%i\t%i\n",L[i],R[i]);
                }
                //Se rehace Key a partir de L y R desplazadas
                for(int i=0;i<56;i++){
                    if(i<28)
                        key[i]=L[i];
                    else
                        key[i]=R[i-28];
                    //printf("%i\n",key[i]);
                }
                //Se aplica la tabla de compresion de clave
                int cClave[48];
                for(int i=0;i<48;i++){
                    cClave[i]=key[tCompresionC[i]-1];
                    //printf("%i\n",cClave[i]);
                }
                printf("Clave Generada\n");
                for(int i=0;i<48;i++){
                    printf("%i ",cClave[i]);
                    if(i==7||i==15||i==23||i==31||i==39||i==47)
                        printf("\n");
                }
                break;
            case 4:
                //Clave de ronda (Caja S)
                //Separamos la entrada permutada en 32 bits de lado Derecho e Izquierdo
                for(int i=0;i<32;i++){
                    lPermutation[i]=permutation[i];
                    rPermutation[i]=permutation[i+32];
                    //printf("%i\t%i\n",lPermutation[i],rPermutation[i]);
                }
                //Caja P de Expansión (R_i) de 32 a 48 bits
                int R_i[48];
                for(int i=0;i<48;i++){
                    R_i[i]=rPermutation[cPExpansion[i]-1];
                    //printf("%i\n ",R_i[i]);
                }
                //XOR entre R_i y cClave
                int B[48];
                for(int i=0;i<48;i++){
                    if(R_i[i]==cClave[i])
                        B[i]=0;
                    else
                        B[i]=1;
                    //printf("%i\n",B[i]);
                }
                //Coordenadas de S4
                int aux[6],auxf[2],auxc[4],cont=0,cont2=0;
                int f[8],c[8];
                for(int i=0;i<48;i++){
                    aux[cont]=B[i];
                    cont++;
                    if(i==5||i==11||i==17||i==23||i==29||i==35||i==41||i==47) {
                        for (int j = 0; j < 2; j++)
                            auxf[j] = aux[j * 5];//Obtenemos la Fila
                        f[cont2]=binToDec(auxf,2);
                        //printf("Decimal: %i\n",f[cont2]);
                        for (int k = 0; k < 4; k++)
                            auxc[k] = aux[k + 1];//Obtenemos la Columnas
                        c[cont2]=binToDec(auxc,4);
                        //printf("DEcimal %i\n",c[cont2]);
                        cont=0;
                        cont2++;
                    }
                }
                //Localizamos los valores en S4
                int valor=0,func[4],function[32],z=3;
                cont=0;
                for(int i=0;i<8;i++){
                    valor=cS4[f[i]][c[i]];
                    //printf("%i\n",valor);
                    //Dec a Bin
                    if(valor==0){
                        for(int j=0;j<4;j++)
                            func[j]=0;
                    }
                    while(valor>0){
                        func[z]=valor%2;
                        z--;
                        valor=valor/2;
                        //printf("%i\n",z);
                    }
                    //printf("0:%i  1:%i   2:%i   3:%i\n",func[0],func[1],func[2],func[3]);
                    if(z==0){
                        func[z]=0;
                    }else if(z==1){
                        for(int j=0;j<2;j++)
                            func[j]=0;
                    }else if(z==2){
                        for(int j=0;j<3;j++)
                            func[j]=0;
                    }
                    //printf("%i %i %i %i\n",func[0],func[1],func[2],func[3]);
                    //Llenamos los 32 bits de la funcion f es decir R
                    for(int j=0;j<4;j++){
                        function[cont]=func[j];
                        cont++;
                    }
                    z=3;
                }
                //Aplicamos a R la tabla de permutacion directa para obtener Ri,ki
                int Ri_Ki[32];
                for(int i=0;i<32;i++){
                    Ri_Ki[i]=function[tPermutaD[i]-1];
                    //printf("%i\n",Ri_Ki[i]);
                }

                //XOR de Ri_Ki con lPermutation
                int nRPermutation[32];
                for(int i=0;i<32;i++){
                    if(Ri_Ki[i]==lPermutation[i])
                        nRPermutation[i]=0;
                    else
                        nRPermutation[i]=1;
                    //printf("%i\n",nRPermutation[i]);
                }

                //Reacomodo de permutadas (Pre-salida)
                int PreSalida[64];
                for(int i=0;i<32;i++){
                    PreSalida[i]=rPermutation[i];
                    PreSalida[i+32]=nRPermutation[i];
                    //printf("%i\n",PreSalida[i]);
                }
                printf("Pre Salida\n");
                for(int i=0;i<64;i++){
                    printf("%i ",PreSalida[i]);
                    if(i==7||i==15||i==23||i==31||i==39||i==47||i==55||i==63)
                        printf("\n");
                }
                break;
            case 5:
                break;
        }
    }
}