#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int aleatorioVec(int min, int max);
int repetidosVec(int v[], int tam,int num);
void cargarVector(int v[], int tam);
void mostrarVector(int v[], int tam);
void cargaAlternados(int v[], int w[], int r[], int tam);


int main(){
    srand(time(0));

    int tam=5;
    int v[tam];
    int r[tam];

    cargarVector(v,tam);
    mostrarVector(v, tam);

    int w[tam];
    cargarVector(w,tam);
    mostrarVector(w,tam);

    cargaAlternados(v, w, r, tam);
    mostrarVector(r,2*tam);


    return 0;
}

int aleatorioVec(int min, int max){
    int ale;

    ale= min+ rand()%(max-min+1);
    return ale;
};

int repetidosVec(int v[], int tam, int num){
    int rep=0;
    for(int i=0; i<tam; i++){
        if(v[i]==num)
            rep=1;
    }
    return rep;
};

void cargarVector(int v[], int tam){
    int rep;
    int ale;
    for(int i=0; i<tam; i++){
        v[i]= -1;

        do{
            ale=aleatorioVec(0,9);
            rep= repetidosVec(v,tam, ale);
        }while (rep==1);
        v[i]=ale;
    }

};



void mostrarVector(int v[], int tam){
    printf("||");
    for(int i=0; i<tam; i++){
        printf(" %d ", v[i]);
    }
    printf("||\n");
};

void cargaAlternados(int v[], int w[], int r[], int tam){
    int pos=0;
    for(int i=tam-1; i>-1; i--){

        r[pos]=v[i];
        pos=pos+1;
        r[pos]=w[i];
        pos=pos+1;
    }


};
