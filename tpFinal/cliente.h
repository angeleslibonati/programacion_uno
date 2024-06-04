#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id; /// campo único y autoincremental
    int nroCliente;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char email[30];
//  stDomicilio domicilio; /// Falta archivo de domicilio
    char telefono[12];
    int eliminado; /// 0 si está activo - 1 si está eliminado
    //Falta hacer

}stCliente;

stCliente cargaCliente();
void muestraCliente(stCliente a);
void cargaArchClientesRandom(char nombreArchivo[], int cant);
void muestraArchivoClientes(char nombreArchivo[]);
void mostrarTelefonos(char telefonos[]);
void muestraDNI(char nombreArchivo[], stCliente a[]);


#endif // CLIENTE_H_INCLUDED
