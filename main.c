#include <stdio.h>

int pInicial[]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,
                12,4,62,54,46,38,30,22,14,6,64,56,48,
                40,32,24,16,8,57,49,41,33,25,17,9,1,
                59,51,43,35,27,19,11,3,61,53,45,37,29,
                21,13,5,63,55,47,39,31,23,15,7};
int tEliminacionP[]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,
                     10,2,59,51,43,35,27,19,11,3,60,52,44,
                     36,63,55,47,39,31,23,15,7,62,54,46,38,
                     30,22,14,6,61,53,45,37,29,21,13,5,28,
                     20,12,4};
int tCompresionC[]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,
                    12,4,26,8,16,7,27,20,13,2,41,52,31,
                    37,47,55,30,40,51,45,33,48,44,49,39,56,
                    34,53,46,42,50,36,29,32};
int cPExpansion[]={32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,
                   12,13,12,13,14,15,16,17,16,17,18,14,20,
                   21,20,21,22,23,24,25,24,25,26,27,28,29,
                   28,29,30,31,32,1};

int main() {
    int entrada[64]={0,0,0,1,0,1,1,0,1,0,1,1,1,1,0,1,
                     0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,
                     0,1,0,1,1,0,1,0,0,0,1,0,1,0,0,
                     1,1,1,0,0,0,1,0,1,0,0,1,1,1,1,
                     0,1,1};
    int llave[64]={1,1,1,0,0,0,0,1,1,0,1,0,0,1,0,0,
                   1,0,1,1,1,0,1,1,1,0,0,1,1,0,1,
                   1,1,1,0,0,0,0,1,0,1,1,1,0,0,0,
                   1,1,0,0,1,0,0,1,0,0,1,0,1,1,1,
                   0,1,1};

    //Permutación
    int permutation[64];
    for(int i=0;i<64;i++){
        permutation[i]=entrada[pInicial[i]-1];
        //printf("%i ",permutation);
    }

    //Llave
    //Eliminamos la periodicidad
    int key[56];
    for(int i=0;i<56;i++){
        key[i]=llave[tEliminacionP[i]-1];
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

    //Clave de ronda (Caja S)
    //Separamos la entrada permutada en 32 bits de lado Derecho e Izquierdo
    int lPermutation[32],rPermutation[32];
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
    return 0;
}
