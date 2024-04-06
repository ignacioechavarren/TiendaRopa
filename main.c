#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "prenda.h"
#include "marca.h"
#include "usuario.h"

int main() {

	Usuario u;
	u.numPrendas=0;

	Prenda p;
	p.id = 1;
	p.precio = 2.555;
	p.talla = 44;
	strcpy(p.tipo, "pantalon");

	Prenda p1;
	p1.id = 2;
	p1.precio = 90.9;
	p1.talla = 2;
	strcpy(p1.tipo, "camiseta");

	anyadirAlCarrito(&u,p);
	anyadirAlCarrito(&u,p1);
	mostrarCarrito(u);

	return 0;
}
