#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "domicilio.h"

int getId(int id)
{
    id += 1;

    return id;
}
void getNombre(char nombre[])
{
    char nombres[][30]= {"Alejandro","Beatriz","Carlos","Daniela","Eduardo","Fernanda","Gabriel","Helena","Ignacio","Julieta","Kevin","Lorena","Mateo",
                         "Natalia","Oscar","Patricia","Quentin","Ricardo","Sofía","Tomás","Úrsula","Víctor","Wendy","Ximena","Yago","Zulema","Andrés","Belén",
                         "Camilo","Diana"
                        };
    strcpy(nombre,nombres[rand()%(sizeof(nombres)/30)]);
}

void getApellido(char apellido[])
{
    char apellidos[][30]=
    {
        "García","Martínez","Rodríguez","López","Hernández","González","Pérez","Sánchez","Ramírez","Cruz","Flores","Rivera",
        "Gómez","Torres","Díaz","Álvarez","Jiménez","Morales","Ortiz","Reyes","Ruiz","Vargas","Mendoza","Castillo","Romero","Fernández",
        "Silva","Ramos","Chávez","Herrera"
    };
    strcpy(apellido, apellidos[rand()%(sizeof(apellidos)/30)]);
}


//Generador de DNIS randoms
void getDNI(char numerosDeDNI[])
{

    for (int i = 0; i < 10; i++)
    {
        numerosDeDNI[i] = (rand() % 38000000) + 8000000; // Genera un número de hasta 8 dígitos (0-99999999)
    }
}



//Telefonos randoms FUNCIONANDO !!!!
void getTelefono(stCliente cliente[])
{
    int dim = 12;
    int enteroDni[12];
    int vEnteroDni = 12;
    char nTelefono[dim];


    int i;
    stCliente nuevoCliente;
    for(i=0; i<vEnteroDni; i++)
    {
        if(i == 0)
        {
            enteroDni[i] = 2;
        }
        else if(i == 1)
        {
            enteroDni[i] = 2;
        }
        else if(i == 2)
        {
            enteroDni[i] = (rand()%3)+1;
        }
        else if(i == 4)
        {
            enteroDni[i] = (rand()%3)+4;
        }else
        {
        enteroDni[i] = rand()%9;
        }
    }
    for(i = 0; i < dim; i++)
    {
        nTelefono[i] = enteroDni[i] + '0';
    }
    nTelefono[i] = '\0';
    nTelefono[3] = '-';
    nTelefono[7] = '-';

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

//    getNombre(a.nombre);
//    getApellido(a.apellido);
    getDNI(a.dni);
//    getEmail(a.email);
    getTelefono(a.telefono);  //ok

    return a;
}












