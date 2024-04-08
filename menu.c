#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "usuario.h"
#include "bd.h"
#include "sqlite3.h"


void menuPrincipal(Usuario usuario, sqlite3 *db) {
	int opcion;
	printf("\n-------------\nTIENDA DEUSTO\n-------------\n");
	printf(
			"Es usted cliente o administrador(0/1/2):\n0.Cliente\n1.Administrador\n2.Salir del programa \n");
	fflush(stdout);

	scanf("%d", &opcion);
	do {
		switch (opcion) {
		case 0:
			inicioCliente(usuario,db);
		case 1:
			inicioAdmin(usuario,db);
		case 2:
			printf("saliendo...");
			exit(0);
		default:
			printf("introduzca un numero entre 0 y 2\n");
		}
	} while (opcion != 2);
}

void inicioCliente(Usuario usuario, sqlite3 *db) {

	int opcion;
	printf("\n--------------\nINICIO CLIENTE\n--------------\n");
	printf(
			"Elija una opcion(0/1/2):\n0.Registrarse\n1.Iniciar Sesion\n2.Volver \n");
	fflush(stdout);

	scanf("%d", &opcion);
	do {
		switch (opcion) {
		case 0:
			//llamada al metodo de registro
			menuCliente(usuario,db);
		case 1:
			//llamada al metodo de inicio de sesion
			menuCliente(usuario,db);
		case 2:
			menuPrincipal(usuario,db);
		default:
			printf("introduzca un numero entre 0 y 2\n");
		}
	} while (opcion != 2);
}

void inicioAdmin(Usuario usuario, sqlite3 *db) {

	int opcion;
	printf("\n------------\nINICIO ADMIN\n------------\n");
	printf(
			"Elija una opcion(0/1/2):\n0.Registrarse\n1.Iniciar Sesion\n2.Volver \n");
	fflush(stdout);

	scanf("%d", &opcion);
	do {
		switch (opcion) {
		case 0:
			//llamada al metodo de registro
			menuAdmin();
		case 1:
			//llamada al metodo de inicio de sesion
			menuAdmin();
		case 2:
			menuPrincipal(usuario, db);
		default:
			printf("introduzca un numero entre 0 y 2\n");
		}
	} while (opcion != 2);
}

void menuAdmin(Usuario usuario, sqlite3 *db) {
	int opcion;
	printf("\n------------\nMENU ADMIN\n------------\n");
	printf(
			"Elija una opcion(0/1/2/3/4/5/6):\n0.Añadir articulo\n1.Eliminar articulo\n2.modificar articulo\n3.Ver carrito\n4.Ver historial de compras\n5.Ver articulos por tipo\n6.Cerrar sesion\n");
	fflush(stdout);

	scanf("%d", &opcion);
	do {
		switch (opcion) {
		case 0:

		case 1:

		case 2:

		case 3:

		case 4:

		case 5:

		case 6:
			menuPrincipal(usuario, db);
		default:
			printf("introduzca un numero entre 0 y 6\n");
		}
	} while (opcion != 6);

}

void menuCliente(Usuario usuario, sqlite3 *db) {
	Prenda prenda;
	int opcion;
	printf("\n------------\nMENU CLIENTE\n------------\n");
	printf(
			"Elija una opcion(0/1/2/3):\n0.Comprar\n1.Carrito\n2.Historial de compra\n3.Cerrar Sesion\n");
	fflush(stdout);

	scanf("%d", &opcion);

		switch (opcion) {
		case 0:
			//verPrendas(db);
			//scanf
			anyadirAlCarrito(&usuario, prenda);
			menuCliente(usuario,db);
		case 1:
			mostrarCarrito(usuario);
			menuCliente(usuario,db);
		case 2:
			mostrarHistorial(usuario);
			menuCliente(usuario,db);
		case 3:
			menuPrincipal(usuario,db);
			break;
		default:
			printf("introduzca un numero entre 0 y 3\n");
		}

}

