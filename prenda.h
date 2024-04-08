#ifndef PRENDA_H_
#define PRENDA_H_

typedef struct{
    int id;
    char tipo[80];
    int talla;
    float precio;
}Prenda;

void imprimirPrenda(Prenda p);
void modificarPrecio(Prenda *p, float precio);
Prenda pedirPrenda();

#endif
