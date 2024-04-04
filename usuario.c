#include "usuario.h"
#include <string.h>

void setNombre(Usuario* usuario, const char* nombre){
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
}
