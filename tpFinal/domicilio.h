#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

typedef struct
{
  char calle[30];
  char nro[6];
  char localidad[50];
  char provincia[40];
  char cpos[6];

}stDomicilio;

stDomicilio cargaUnDomicilio();
void muestraUnDomicilio(stDomicilio d);



#endif // DOMICILIO_H_INCLUDED
