#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "domicilio.h"
#include "mockDomicilio.h"
#include <ctype.h>

int getId(int id)
{
    id += 1;

    return id;
}
void getNombre(char nombre[]) // OKKKK
{
    char nombres[][30]= {"Alejandro","Beatriz","Carlos","Daniela","Eduardo","Fernanda","Gabriel","Helena","Ignacio","Julieta","Kevin","Lorena","Mateo",
                         "Natalia","Oscar","Patricia","Quentin","Ricardo","Sofia","Tomas","Ursula","Victor","Wendy","Ximena","Yago","Zulema","Andres","Belen",
                         "Camilo","Diana"
                        };
    strcpy(nombre,nombres[rand()%(sizeof(nombres)/30)]);
}

void getApellido(char apellido[]) //OKKKKK
{
    char apellidos[][30]=
    {
        "Garcia","Martinez","Rodríguez","López","Hernandez","Gonzalez","Perez","Sanchez","Ramirez","Cruz","Flores","Rivera",
        "Gomez","Torres","Diaz","Alvarez","Jimenez","Morales","Ortiz","Reyes","Ruiz","Vargas","Mendoza","Castillo","Romero","Fernandez",
        "Silva","Ramos","Chavez","Herrera"
    };
    strcpy(apellido, apellidos[rand()%(sizeof(apellidos)/30)]);
}

void getEmail(stCliente c)
{
    int i;

    char correos[][30]= {"@mail.com.ar"};
    strcat(c.nombre, c.apellido);

    char mail[30];




}


//Generador de DNIS randoms OKKK
void getDNI(char dni[])
{

    char dniChar[8];
    int vletra = 8;
    int i;

    for(i = 0; i < vletra;i++)
    {
        dniChar[i] = rand()%9 + '0';
    }
    // asigna en el ultimo caracter un \0 para transformar el arreglo de char en una cadena de caracteres;
    dniChar[i] = '\0';

    return strcpy(dni,dniChar);
}



//Telefonos randoms FUNCIONANDO !!!!
void getTelefono(stCliente cliente[])
{
    int vTelefono = 11;
    char nTelefono[12];


    int i;
    stCliente nuevoCliente;
    for(i=0; i<vTelefono; i++)
    {
        if(i == 0)
        {
            nTelefono[i] = 2 + '0';
        }
        else if(i == 1)
        {
            nTelefono[i] = 2+ '0';
        }
        else if(i == 2)
        {
            nTelefono[i] = ((rand()%3)+1)+ '0';
        }
        else if(i == 4)
        {
            nTelefono[i] = ((rand()%3)+4)+ '0';
        }else
        {
        nTelefono[i] = (rand()%9)+ '0';
        }
    }
    nTelefono[i] = '\0';
    nTelefono[3] = '-';
   // nTelefono[7] = '-';

    strcpy(cliente, nTelefono);
}


//Muestra de Telefonos
void mostrarTelefonos(char telefonos[])
{
    for (int i = 0; i < 12; i++)
    {
        printf("%s\n", telefonos[i]);
    }
}


stCliente getClienteRandom()
{
    stCliente a;


    getId(a.id);
    getNombre(a.nombre);
    getApellido(a.apellido);
    getDNI(a.dni);
    getTelefono(a.telefono);
    //getEmail(a);
    a.domicilio = getDomicilioRandom();


    return a;
}










