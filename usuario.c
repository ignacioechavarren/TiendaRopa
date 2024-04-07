#include "usuario.h"
#include "prenda.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define CARRITO_MAX 5

void imprimirUsuario(Usuario usuario) {
	printf("id: %d\n", usuario.id);
	printf("nombre: %s\n", usuario.nombre);
	printf("contraseña: %s\n", usuario.contrasenya);
}

void anyadirAlCarrito(Usuario *usuario, Prenda prenda) {
	if (usuario->numPrendas < MAX_ITEMS) {
		usuario->carrito[usuario->numPrendas] = prenda;
		usuario->numPrendas++;
		printf("prenda (%d) añadido/a\n", prenda.id);
	} else {
		printf("no hay espacio en el carrito\n");

	}
}

void mostrarCarrito(Usuario usuario) {
	int opcion;
	if (usuario.numPrendas == 0) {
		printf("el carrito esta vacio\n");
	} else {
		for (int i = 0; i < usuario.numPrendas; i++) {
			imprimirPrenda(usuario.carrito[i]);
			printf("\n");
		}
		printf("comprar prendas del carrito (0. si/1. no): ");
		fflush(stdout);
		scanf("%d", &opcion);
		if (opcion == 0) {
			printf("procesando compra...\n");
			FILE *archivo;
			archivo = fopen("archivo.txt", "a");
			for (int i = 0; i < usuario.numPrendas; i++) {
				char str[100];
				sprintf(str, "%s - %.2f €\n", usuario.carrito[i].tipo,
						usuario.carrito[i].precio);
				char *input = str;
				fprintf(archivo, "%s", input);
			}
			fclose(archivo);
			printf("compra almacenada\n");
		} else {
			printf("saliendo...\n");
		}
	}
}

void mostrarHistorial(Usuario usuario) {
	FILE *archivo;
	char c;
	archivo = fopen("archivo.txt", "r");

	while ((c = fgetc(archivo)) != EOF) {
	        printf("%c", c);
	    }

	fclose(archivo);
}

/*void setNombre(Usuario* usuario, const char* nombre){
 strncpy(usuario ->nombre, nombre, MAX_NOMBRE_LENGTH);
 usuario -> nombre[MAX_NOMBRE_LENGTH - 1] = '\0' //Asegurar la terminacion nula
 }

 void setID(Usuario* usuario, int id) {
 usuario->id = id;
 }

 void setContrasenya(Usuario* usuario, const char* contrasenya){
 strncpy(usuario ->contrasenya, contrasenya, MAX_CONTRASENYA_LENGTH);
 usuario -> contrasenya[MAX_CONTRASENYA_LENGTH - 1] = '\0' //Asegurar la terminacion nula
 }


 const char* getNombre(const Usuario* usuario) {
 return usuario->nombre;
 }

 int getID(const Usuario* usuario){
 return usuario->id;
 }

 const char* getContrasenya(const Usuario* usuario){
 return usuario->contrasenya;
 }*/
