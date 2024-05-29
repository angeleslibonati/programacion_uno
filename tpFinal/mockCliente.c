#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

int getFileNumber()
{
    return (rand()%900)+100;
}

void getName(char name[])
{
    char names[][30]= {"Alejandro","Beatriz","Carlos","Daniela","Eduardo","Fernanda","Gabriel","Helena","Ignacio","Julieta","Kevin","Lorena","Mateo",
                       "Natalia","Oscar","Patricia","Quentin","Ricardo","Sofía","Tomás","Úrsula","Víctor","Wendy","Ximena","Yago","Zulema","Andrés","Belén",
                       "Camilo","Diana"
                      };
    strcpy(name,names[rand()%(sizeof(names)/30)]);
}

void getLastName(char lastName[])
{
    char lastNames[][30]=
    {
        "García","Martínez","Rodríguez","López","Hernández","González","Pérez","Sánchez","Ramírez","Cruz","Flores","Rivera",
        "Gómez","Torres","Díaz","Álvarez","Jiménez","Morales","Ortiz","Reyes","Ruiz","Vargas","Mendoza","Castillo","Romero","Fernández",
        "Silva","Ramos","Chávez","Herrera"
    };
    strcpy(lastName, lastNames[rand()%(sizeof(lastNames)/30)]);
}

char* getNamePro()
{
    char* name = (char*) malloc(sizeof(char)*30);
    char names[][30]= {"Alejandro","Beatriz","Carlos","Daniela","Eduardo","Fernanda","Gabriel","Helena","Ignacio","Julieta","Kevin","Lorena","Mateo",
                       "Natalia","Oscar","Patricia","Quentin","Ricardo","Sofía","Tomás","Úrsula","Víctor","Wendy","Ximena","Yago","Zulema","Andrés","Belén",
                       "Camilo","Diana"
                      };
    strcpy(name,names[rand()%(sizeof(names)/30)]);
    return name;
}

void getDNI(char dni[])
{
    char dnis[][10] =
    {
        "40.099.124", "32.765.543", "45.876.321", "50.123.987", "33.456.789",
        "29.876.543", "44.321.654", "41.987.230", "36.543.210", "39.654.987"
    };
    strcpy(dni, dnis[rand() % (sizeof(dnis) / sizeof(dnis[0]))]);
}

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

void getTelefono(char telefono[])
{
    char telefonos[][12] =
    {
        "2235376766", "2234567894", "2234235697", "2231234523", "2237896543",
        "2236789763", "2234354657", "2235348129", "2235876124", "2234546023",
        "2234365678", "2234536578"
    };
    strcpy(telefono, telefonos[rand() % (sizeof(telefonos) / sizeof(telefonos[12]))]);
}

stCliente getClienteRandom()
{
    stCliente a;
    a.id = getFileNumber();
    getName(a.nombre);
    strcpy(a.nombre,getNamePro());
    getLastName(a.apellido);
    getDNI(a.dni);
    getEmail(a.email);
    getTelefono(a.telefono);

    return a;
}
