#ifndef PRENDA_H_
#define PRENDA_H_

typedef struct{
    int id;
    char* tipo;
    int talla;
    float precio;
}Prenda;

void imprimirPrenda(Prenda p);

#endif