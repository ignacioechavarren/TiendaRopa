#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "prenda.h"
#include "marca.h"
#include "usuario.h"
#include "bd.h"

int main() {

	Usuario u;
	u.numPrendas = 0;
	sqlite3 *db;
	menuPrincipal(u, db);

	return 0;
}
