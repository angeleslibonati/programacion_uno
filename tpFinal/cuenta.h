#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED

typedef struct {
int id;
int idCliente;
int nroCuenta;
int tipoDeCuenta;
float costoMensual;
float saldo;
int eliminado;

} stCuenta;

stCuenta altaCuentaUsuario(FILE *  archi);
float costoMantenimiento(int tipoCuenta);
stCuenta buscaCuentaPorId (char nombreArchivo [], int idCuenta);
int cambioEstadoCuentaPorId (char nombreArchivo [], int idCuenta);
void listarCuentasPorCliente(char nombreArchivo [], int idCliente);
int contarCantRegistros(char nombreArchivo [], int tamStruc);//ver borrar
int id (FILE * archi);
void consultaCuentaPorId(char nombreArchivo [], int id);
int modificaTipoCuentaPorId(char nombreArchivo [], int id, int tipoCuenta);


#endif // CUENTA_H_INCLUDED
