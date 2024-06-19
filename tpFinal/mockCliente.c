#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "domicilio.h"
#include "mockDomicilio.h"
#include <ctype.h>


//ID autoincremental
int id (FILE * archi)
{
    stCliente cliente;
    int id;
    fseek(archi, 0, 2);
    int cant = ftell(archi)/sizeof(stCliente);

    if(cant > 0)
    {
        id = cant + 1;
    }
    else
    {
        id = 1;
    }

    return id;
}

//Nombre
void getNombre(char nombre[])
{
    char nombres[][30]= {"Alejandro","Beatriz","Carlos","Daniela","Eduardo","Fernanda","Gabriel","Helena","Ignacio","Julieta","Kevin","Lorena","Mateo",
                         "Natalia","Oscar","Patricia","Quentin","Ricardo","Sofia","Tomas","Ursula","Victor","Wendy","Ximena","Yago","Zulema","Andres","Belen",
                         "Camilo","Diana"
                        };
    strcpy(nombre,nombres[rand()%(sizeof(nombres)/30)]);
}

//Apellido
void getApellido(char apellido[])
{
    char apellidos[][30]=
    {
        "Garcia","Martinez","Rodríguez","Lopez","Hernandez","Gonzalez","Perez","Sanchez","Ramirez","Cruz","Flores","Rivera",
        "Gomez","Torres","Diaz","Alvarez","Jimenez","Morales","Ortiz","Reyes","Ruiz","Vargas","Mendoza","Castillo","Romero","Fernandez",
        "Silva","Ramos","Chavez","Herrera"
    };
    strcpy(apellido, apellidos[rand()%(sizeof(apellidos)/30)]);
}


//Genera un mail a partir del nombre y apellido del cliente
void getEmail(char mail[],char nombre[], char apellido[])
{
    char mailCompleto[30];
    char dominio[] = {"@mail.com"};
    strcat(mail,tolower(nombre));
    strcat(mail,apellido);
    strcat(mail,dominio);
    for(int i = 0; i < strlen(mail); i++)
    {
        mailCompleto[i] = tolower(mail[i]);

    }
    mailCompleto[strlen(mail)] = '\0';
    strcpy(mail, mailCompleto);
}



// Función que genera el número de cliente
void getNumeroCliente(char dni, int id) {
    char numeroCliente[50];

    // Concatenamos "DNI-ID"
    strcpy(numeroCliente, dni);
    strcat(numeroCliente, "-");
    strcat(numeroCliente, id);

}



//Generador de DNIS randoms
void getDNI(char dni[])
{

    char dniChar[8];
    int vletra = 8;
    int i;

    for(i = 0; i < vletra; i++)
    {
        dniChar[i] = rand()%9 + '0';
    }
    // asigna en el ultimo caracter un \0 para transformar el arreglo de char en una cadena de caracteres;
    dniChar[i] = '\0';

    return strcpy(dni,dniChar);
}


//Telefonos randoms
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
        }
        else
        {
            nTelefono[i] = (rand()%9)+ '0';
        }
    }
    nTelefono[i] = '\0';
    nTelefono[3] = '-';
    nTelefono[7] = '-';

    strcpy(cliente, nTelefono);
}



stCliente getClienteRandom(FILE* archi)
{
    stCliente a;

    a.id = id(archi);
    getNumeroCliente(a.dni, a.id);
    getApellido(a.apellido);
    getDNI(a.dni);
    getTelefono(a.telefono);
    getEmail(a.email, a.nombre, a.apellido);
    a.domicilio = getDomicilioRandom();


    return a;
}










