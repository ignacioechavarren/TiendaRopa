#ifndef MENU_H_
#define MENU_H_

#include "usuario.h"
#include "bd.h"
#include "sqlite3.h"

void menuPrincipal(Usuario usuario, sqlite3 *db);
void inicioCliente(Usuario usuario, sqlite3 *db);
void inicioAdmin(Usuario usuario, sqlite3 *db);
void menuCliente(Usuario usuario, sqlite3 *db);
void menuAdmin(Usuario usuario, sqlite3 *db);


#endif /* MENU_H_ */
