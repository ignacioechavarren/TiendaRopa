/*
 * admin.h
 *
 *  Created on: 6 abr 2024
 *      Author: IGNAC
 */

#ifndef ADMIN_H_
#define ADMIN_H_

typedef struct
{
	int cAdmin;
	char nUsuario[30];
	char password[30];
} Admin;


void imprimirAdmin(Admin a);
Admin pedirAdmin();

#endif /* ADMIN_H_ */
