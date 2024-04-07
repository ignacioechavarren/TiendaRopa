#include "bd.h"
#include <stdio.h>
#include <string.h>

//int crearTablas(sqlite3 *db){
void crearTablas(sqlite3 *db){
	sqlite3_stmt *stmt1;
	sqlite3_stmt *stmt2;
	sqlite3_stmt *stmt3;
	sqlite3_stmt *stmt4;
	sqlite3_stmt *stmt;

	char sql1[] = "create table usuario(id int, nombre varchar(20), contrasenya varchar(20), precio float)";
	char sql2[] = "create table admin(nUsuario varchar(30), password varchar(30))";
	char sql3[] = "create table prenda(id int, tipo varchar(80), talla int, precio float )";
	//creo que esta sobra no? 
    // igual poner algo de carrito o así
    char sql4[] = "create table venta(dia int, mes varchar(15), anyo int, usu varchar(20), codarti varchar(20))";


	sqlite3_prepare_v2(db, sql1, strlen(sql1), &stmt1, NULL) ;
	sqlite3_step(stmt1);
	sqlite3_finalize(stmt1);

	sqlite3_prepare_v2(db, sql2, -1, &stmt2, NULL) ;
	sqlite3_step(stmt2);
	sqlite3_finalize(stmt2);

	sqlite3_prepare_v2(db, sql3, -1, &stmt3, NULL) ;
	sqlite3_step(stmt3);
	sqlite3_finalize(stmt3);

	sqlite3_prepare_v2(db, sql4, -1, &stmt4, NULL) ;
	sqlite3_step(stmt4);
	sqlite3_finalize(stmt4);

	char sql[] = "insert into admin values('admin','admin', 1)";
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);


}

void obtenerAdmin(sqlite3 *db, char *nUsuario, Admin *a){
	sqlite3_stmt *stmt;
	char sql[100];
	int resul;
	sprintf(sql,"select * from admin where nUsuario = '%s'",nUsuario);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	resul = sqlite3_step(stmt);
	if(resul == SQLITE_ROW) {
		strcpy(a->nUsuario, (char*)sqlite3_column_text(stmt, 0));
		strcpy(a->password, (char*)sqlite3_column_text(stmt, 1));

	}else{
		strcpy(a->nUsuario,"");
		printf("Admin no encontrado\n");
	}

}

void obtenerUsuario(sqlite3 *db, char *nombre, Usuario *u){
	sqlite3_stmt *stmt;
	char sql[100];
	int resul;
	sprintf(sql,"select * from usuario where nombre = '%s'",nombre);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	resul = sqlite3_step(stmt);
	if(resul == SQLITE_ROW) {
		strcpy(u->nombre, (char*)sqlite3_column_text(stmt, 0));
		strcpy(u->contrasenya, (char*)sqlite3_column_text(stmt, 1));
		u->numPrendas = sqlite3_column_int(stmt, 3);
	}else{
		printf("Usuario no encontrado\n");
		strcpy(u->nombre,"");
	}

}



void obtenerPrenda(sqlite3 *db, int *id, Prenda *p){
	sqlite3_stmt *stmt;
	char sql[100];
	int resul;
	sprintf(sql,"select * from prenda where id = '%i'",id);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	resul = sqlite3_step(stmt);
	if(resul == SQLITE_ROW) {
		strcpy(p->id, (char*)sqlite3_column_text(stmt, 0));
		strcpy(p->tipo, (char*)sqlite3_column_text(stmt, 1));
		p->precio = sqlite3_column_double(stmt, 2);
		p->talla = sqlite3_column_int(stmt, 4);
	}else{
		printf("Prenda no encontrado\n");
		strcpy(p->id,"");
	}

}
void registrarUsuario(sqlite3 *db, char *nombre, char *contrasenya){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "insert into usuario values('%s', '%s')",nombre,contrasenya);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
	printf("Usuario registrado correctamente\n");
}


void registrarAdmin(sqlite3 *db, char *nUsuario, char *password){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "insert into admin values('%s', '%s')",nUsuario,password);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}


void verPrendas(sqlite3 *db){
	int resul;
	sqlite3_stmt *stmt;
	Prenda p;
	char sql[100];

	sprintf(sql,"select * from prenda");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;



	resul = sqlite3_step(stmt);
		while(resul == SQLITE_ROW){
			strcpy(p.id, sqlite3_column_int(stmt, 0));
			strcpy(p.tipo, (char*)sqlite3_column_text(stmt, 1));
			p.precio = sqlite3_column_double(stmt, 2);
			p.talla = sqlite3_column_int(stmt, 4);
			imprimirPrenda(p);
			resul = sqlite3_step(stmt);
		}
		sqlite3_finalize(stmt);
}

typedef struct {
    struct {
        int dia;
        char mes[20];
        int anyo;
    } f_compra;
    struct {
        char nombre[50];
    } usu;
    struct {
        char cod_pren[20];
    } pren;
} Compra;

void verComprasUsuario(sqlite3 *db, char *nombre){
    int resul;
    sqlite3_stmt *stmt;
    Compra c;
    char sql[100];

    sprintf(sql, "select * from compra where usu = '%s'", nombre);
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    resul = sqlite3_step(stmt);
    while (resul == SQLITE_ROW) {
        c.f_compra.dia = sqlite3_column_int(stmt, 0);
        strcpy(c.f_compra.mes, (char*)sqlite3_column_text(stmt, 1));
        c.f_compra.anyo = sqlite3_column_int(stmt, 2);
        strcpy(c.usu.nombre, (char*)sqlite3_column_text(stmt, 3));
        strcpy(c.pren.cod_pren, (char*)sqlite3_column_text(stmt, 4));


        verCompra(c);

        resul = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
}

void cambiarContrasenaUsuario(sqlite3 *db, char *nombre, char *contrasenya){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "update usuario set contrasenya='%s' where nombre='%s'", contrasenya, nombre);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void cambiarContrasenaAdmin(sqlite3 *db, char *nUsuario, char *password){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "update admin set password='%s' where nUsuario='%s'", password, nUsuario);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}


void eliminarUsuario(sqlite3 *db, char *nombre){
	sqlite3_stmt *stmt;
	char sql[100];
	sprintf(sql, "delete from usuario where nombre = '%s'", nombre);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void verUsuarios(sqlite3 *db){
	int resul;
	sqlite3_stmt *stmt;
	Usuario u;
	char sql[100];

	sprintf(sql,"select * from usuario");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;

	resul = sqlite3_step(stmt);
		while(resul == SQLITE_ROW){
		strcpy(u.nombre, (char*)sqlite3_column_text(stmt, 0));
		strcpy(u.contrasenya, (char*)sqlite3_column_text(stmt, 1));
		u.numPrendas = sqlite3_column_int(stmt, 3);
		printf("%s %s %i\n",u.nombre, u.contrasenya, u.numPrendas);
		resul = sqlite3_step(stmt);
	}
	sqlite3_finalize(stmt);


}
void verCarrito(sqlite3 *db){
	int resul;
	sqlite3_stmt *stmt;
	Compra c;
	char sql[100];

	sprintf(sql,"select * from venta");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;

	resul = sqlite3_step(stmt);
		while(resul == SQLITE_ROW){
			c.f_compra.dia = sqlite3_column_int(stmt, 0);
			strcpy(c.f_compra.mes, (char*)sqlite3_column_text(stmt, 1));
			c.f_compra.anyo = sqlite3_column_int(stmt, 2);
			strcpy(c.usu.nombre, (char*)sqlite3_column_text(stmt, 3));
			strcpy(c.pren.cod_pren, (char*)sqlite3_column_text(stmt, 4));

			verCompra(c);

			resul = sqlite3_step(stmt);
		}
	sqlite3_finalize(stmt);
}

void anyadirPrenda(sqlite3 *db, int *id, char *tipo,  int talla, float precio){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "insert into prenda values('%i', '%s', %i, %2.f)",id, tipo, talla, precio);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}

void modificarCarrito(sqlite3 *db, int stock, char *codarti){
	sqlite3_stmt *stmt;
	char sql[100];

	sprintf(sql, "update zapato set stock='%i' where cod_zap='%s'", stock, codarti);
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	sqlite3_step(stmt);
	sqlite3_finalize(stmt);
}
