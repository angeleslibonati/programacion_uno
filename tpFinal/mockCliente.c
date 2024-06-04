#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

//Numero de cliente
int getNumeroCliente()
{
    return (rand()%900)+100;
}

//Nombre
void getNombre(char nombre[])
{
    char nombres[][30]= {"Ayelen","Angeles","Dario","Federico","Eduardo","Fernanda","Gabriel","Helena","Ignacio","Julieta","Kevin","Lorena","Mateo",
                         "Natalia","Oscar","Patricia","Quentin","Ricardo","Sofía","Tomás","Úrsula","Víctor","Wendy","Ximena","Yago","Zulema","Andrés","Belén",
                         "Camilo","Diana"
                        };
    strcpy(nombre,nombres[rand()%(sizeof(nombres)/30)]);
}

//Apellido
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

//Generador de DNI
void getDNI(char numerosDeDNI[])
{

    for (int i = 0; i < 10; i++)
    {
        numerosDeDNI[i] = rand() % 46000000; // Genera un número de hasta 8 dígitos (0-99999999)
    }
}///pasar dni a char

//Emails
void getEmail(char email[])
{
    char emails[][30] =
    {
        "keila_alima@hotmail.com", "juan.perez@gmail.com", "carlos.rodriguez@outlook.com","maria.hernandez@hotmail.com", "pedro_gomez@gmail.com", "luis.martinez@outlook.com",
        "ana.lopez@hotmail.com", "laura_gonzalez@gmail.com", "david.sanchez@outlook.com","sara_ramirez@hotmail.com", "fernando_rios@gmail.com", "gloria.mendez@outlook.com",
        "julian_diaz@hotmail.com", "pablo.castillo@gmail.com", "silvia_fernandez@outlook.com","lucia_garcia@hotmail.com", "alberto.rodriguez@gmail.com", "claudia_ramos@outlook.com",
        "jorge_santos@hotmail.com", "veronica_gomez@gmail.com", "mario_lopez@outlook.com","sofia_martinez@hotmail.com", "ricardo_molina@gmail.com", "paola_cruz@outlook.com",
        "andres_reyes@hotmail.com", "cristina_dominguez@gmail.com", "patricia_vargas@outlook.com","diego_ruiz@hotmail.com", "lorena_gonzalez@gmail.com", "javier_flores@outlook.com"
    };
    strcpy(email, emails[rand() % (sizeof(emails) / sizeof(emails[10]))]);
}

//Telefonos randoms
void getTelefono(stCliente cliente[])
{
    int dim = 12;
    int enteroDni[12];
    int vEnteroDni = 12;
    char nTelefono[dim];
    int i;
    stCliente nuevoCliente;

    for(i=0; i< vEnteroDni; i++)
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
            //Para que el "15" del telefono no sea diferente a 4, 5 o 6.
            enteroDni[i] = (rand()%3)+4;
        }
        else
        {
            enteroDni[i] = rand()%9;
        }
    }
    for(i = 0; i < dim; i++)
    {
        nTelefono[i] = enteroDni[i] + '0';
    }
    //Pasando a char
    nTelefono[i] = '\0';
    //Pisando valores para que haya guiones
    nTelefono[3] = '-';
    nTelefono[7] = '-';

    strcpy(cliente, nTelefono);
}


stCliente getClienteRandom()
{
    stCliente a;
    getNumeroCliente(a.nroCliente);
    getNombre(a.nombre);
    getApellido(a.apellido);
    getDNI(a.dni);
    getEmail(a.email);
    getTelefono(a.telefono);

    return a;
}












