#ifndef USUARIO_H_
#define USUARIO_H_

#define MAX_NOMBRE_LENGTH 100
#define MAX_CONTRASENYA_LENGTH 100

typedef struct{
	//id nombre contraseña admin
	int id;
	char nombre[MAX_NOMBRE_LENGTH];
	char contrasenya[MAX_CONTRASENYA_LENGTH];
}Usuario;

void setNombre(Usuario* usuario, const char* nombre);
void setID(Usuario* usuario, int id);
void setContrasenya(Usuario* usuario, const char* contrasenya);

const char* getNombre(const Usuario* usuario);
int getId(const Usuario* usuario);
const char* getContrasenya(const Usuario* usuario);


#endif /* USUARIO_H_ */
