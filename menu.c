#include <stdio.h>
#include <stdlib.h>

void menuPrincipal() {
	int opcion;
	printf("\n-------------\nTIENDA DEUSTO\n-------------\n");
	printf(
			"Es usted cliente o administrador(0/1/2):\n0.Cliente\n1.Administrador\n2.Salir del programa \n");
	fflush(stdout);

	scanf("%d", &opcion);
	do {
		switch (opcion) {
		case 0:
			inicioCliente();
		case 1:
			inicioAdmin();
		case 2:
			printf("saliendo...");
			break;
		default:
			printf("introduzca un numero entre 0 y 2\n");
		}
	} while (opcion != 2);
}

void inicioCliente() {

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
			menuCliente();
		case 1:
			//llamada al metodo de inicio de sesion
			menuCliente();
		case 2:
			menuPrincipal();
		default:
			printf("introduzca un numero entre 0 y 2\n");
		}
	} while (opcion != 2);
}

void inicioAdmin() {

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
			menuPrincipal();
		default:
			printf("introduzca un numero entre 0 y 2\n");
		}
	} while (opcion != 2);
}

void menuAdmin() {
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
			menuPrincipal();
		default:
			printf("introduzca un numero entre 0 y 6\n");
		}
	} while (opcion != 6);

}

void menuCliente() {
	int opcion;
	printf("\n------------\nMENU CLIENTE\n------------\n");
	printf(
			"Elija una opcion(0/1/2/3):\n0.Comprar\n1.Historial de compras\n2.Carrito\n3.Cerrar Sesion\n");
	fflush(stdout);

	scanf("%d", &opcion);
	do {
		switch (opcion) {
		case 0:

		case 1:

		case 2:

		case 3:
			menuPrincipal();
		default:
			printf("introduzca un numero entre 0 y 3\n");
		}
	} while (opcion != 3);

}

