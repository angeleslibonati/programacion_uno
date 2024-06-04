#ifndef MOVIMIENTO_H_INCLUDED
#define MOVIMIENTO_H_INCLUDED


typedef struct
{
    int id; //campo unico y auto incrementable
    int idCuenta;  //id de la cuenta. Relacion con stCuenta.
    char detalle [100];  //descripcion de operacion.
    float importe;
    int anio;
    int mes;  //validar del 1 al 12 (segun mes)
    int dia;  //validar del 1 al... (segun cantidad de dias, por mes)
    int eliminado; // "0" es activo. "1" eliminado.



}stMovimiento;

void extraccionDepositoDinero (char nombreArchivo[],stMovimiento movBancario, float importe, int idCuenta);
void opcionMovimiento (float importe, stCuenta cuenta, char nombreArchivo[],int idCuenta);
int modificacionImporte (int importe, char nombreArchivo[], int id);
stMovimiento buscaMovimiento (int id, FILE * archi);
int bajaMovimiento (int id, char nombreArchivo[]);
stMovimiento consultaMovimiento (int id, char nombreArchivo[]);
void listadoMovimientoCuenta (int idCuenta, char nombreArchivo[]);
void listadoMovimientoMes (int idCuenta, int dia, int mes, int anio, char nombreArchivo[]);
void muestraUnMovimiento (stMovimiento movBancario);


#endif // MOVIMIENTO_H_INCLUDED
