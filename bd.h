
#ifndef BBDD_H_
#define BBDD_H_

#include "sqlite3.h"

#include "prenda.h"
#include "usuario.h"
#include "admin.h"

void crearTablas(sqlite3 *db);
void obtenerAdmin(sqlite3 *db, char *nUsuario, Admin *a);
void obtenerUsuario(sqlite3 *db, char *nombre, Usuario *u);
void obtenerPrenda(sqlite3 *db, int *id, Prenda *p);
void registrarUsuario(sqlite3 *db, char *nombre, char *contrasenya);
void registrarAdmin(sqlite3 *db, char *nUsuario, char *password);
int verPrendas(sqlite3 *db);
void cambiarContrasenaUsuario(sqlite3 *db, char *nombre, char *contrasenya);
void cambiarContrasenaAdmin(sqlite3 *db, char *nUsuario, char *password);
void eliminarUsuario(sqlite3 *db, char *nombre);
void verUsuarios(sqlite3 *db);
void anyadirPrenda(sqlite3 *db, int *id, char *tipo,  int talla, float precio);
void eliminarPrenda(sqlite3 *db, int *id);








#endif /* BBDD_H_ */
