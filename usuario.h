#ifndef USUARIO_H_
#define USUARIO_H_

#include "prenda.h"

#define MAX_NOMBRE_LENGTH 100
#define MAX_CONTRASENYA_LENGTH 100
#define MAX_ITEMS 5

typedef struct{
	//id nombre contraseña admin
	int id;
	char nombre[MAX_NOMBRE_LENGTH];
	char contrasenya[MAX_CONTRASENYA_LENGTH];
	Prenda carrito[MAX_ITEMS];
	int numPrendas;

}Usuario;

void imprimirUsuario(Usuario usuario);
void anyadirAlCarrito(Usuario *usuario, Prenda prenda);//añadir al carrito
void mostrarCarrito(Usuario usuario);

/*void setNombre(Usuario* usuario, const char* nombre);
void setID(Usuario* usuario, int id);
void setContrasenya(Usuario* usuario, const char* contrasenya);

const char* getNombre(const Usuario* usuario);
int getId(const Usuario* usuario);
const char* getContrasenya(const Usuario* usuario);*/


#endif /* USUARIO_H_ */
