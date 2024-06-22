#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


#include "domicilio.h"
#include "mockDomicilio.h"
#include "cliente.h"
#include "mockCliente.h"
#include "mockMovimiento.h"
#include "movimiento.h"
#include "cuenta.h"
#include "mockCuenta.h"


void imprimirCabecera(char cabecera[]);
void imprimeOpcionMenuPrincipal ();
void iniciarMenu();
int ingresaOpcion ();
int ingresaID ();
int switchMenuPrincipal ();
void imprimeOpcionesSubMenu ();
void switchSubMenuCliente ();
void imprimeOpcionSubMenuModificar ();
void swithcSubMenuCuenta ();
void switchSubMenuMovimiento ();
void imprimirOpcionListado();
void switSubMenuListado();
void swithcSubMenuModificarCliente (stCliente cliente);


#endif // MENU_H_INCLUDED
