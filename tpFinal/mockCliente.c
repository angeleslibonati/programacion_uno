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

//Generador de DNIS randoms
void getDNI(char dniNumbers[]) {

    for (int i = 0; i < 10; i++) {
        dniNumbers[i] = rand() % 100000000; // Genera un número de hasta 8 dígitos (0-99999999)
    }
}

//Muestra de DNI randoms
void muestraDNIsRandom(char nombreArchivo[]) {
    for (int i = 0; i < 10; i++) {
        printf("%08d\n", nombreArchivo[i]); // Imprime con ceros a la izquierda si es necesario
    }
}

//Emails no tan randoms
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
void getTelefono(char nombreArchivo[]) {

    for (int i = 0; i < 12; i++) {
        int areaCode = rand() % 900 + 100;       // Genera un código de área de 3 dígitos (100-999)
        int centralCode = rand() % 900 + 100;  // Genera los siguientes 3 dígitos (100-999)
        int endCode = rand() % 10000;         // Genera los últimos 4 dígitos (0000-9999)

        // Guarda el número de teléfono en el array de cadenas
        sprintf(nombreArchivo[i], "%03d-%03d-%04d", areaCode, centralCode, endCode);
    }
}

//Muestra de Telefonos Randoms
void mostrarTelefonosRandoms(char nombreArchivo[]) {
    for (int i = 0; i < 12; i++) {
        printf("%s\n", nombreArchivo[i]);
    }
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












