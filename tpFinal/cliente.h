#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "domicilio.h"

typedef struct
{
    int id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
    stDomicilio domicilio; /// Falta archivo de domicilio
    char telefono[12];
    int eliminado; /// 0 si está activo - 1 si está eliminado


}stCliente;

stCliente cargaCliente(); // OK
void muestraCliente(stCliente cliente); // OK
void cargaArchivoClientesRandoms(char nombreArchivo[], int cantidad);
void muestraArchivoClientes(char nombreArchivo[]);


//int cuentaRegistroArchivo(char nombreArchivo[], int tamEstructura);
void altaCliente(char archivo[]);
//void bajaCliente(char archivo[], int numCliente);
//void modificaCliente(char archivo[], int numCliente);
//void consultaCliente(char archivo[], int numCliente);
//int verificaNroCliente(char archivo[], int dato);
//int buscaIdCliente(FILE * archivo, int numId);
int bajaCliente (char nombreArchivo[], int numId);
stCliente buscarClientePorId(char nombreArchivo [], int numId);
int  modificaNombre(FILE * archi,int id, char nombre[]);
int  modificaMail(FILE * archi,int id, char mail[]);
int  modificaDni(FILE * archi,int id, char dni[]);
int  modificaTelefono(FILE* archi,int id, char telefono[]);
int  modificaDomicilio(FILE * archi,int id, char domicilio[]);
void imprimirCabecera(char cabecera[]);
void swithcSubMenuModificarCliente (FILE* archi, int id, int opcion);
void modificaCliente(char nombreArchivo[], int id, int opcion);




#endif // CLIENTE_H_INCLUDED
