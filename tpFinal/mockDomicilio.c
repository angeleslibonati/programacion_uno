#include <stdio.h>
#include <stdlib.h>
#include "domicilio.h"
#include <string.h>
#include <conio.h>
#include "mockMovimiento.h"
#include "domicilio.h"
#include "cliente.h"
#include "mockCliente.h"
#include "mockDomicilio.h"
#include "menu.h"
#include "movimiento.h"
#include "mockMovimiento.h"
#include "cuenta.h"
#include "mockCuenta.h"





void getCalleMarDelPlata(char marDelPlata[])
{
   char calles[][30] = {
    "Avenida Colon", "Avenida Independencia", "Avenida Juan B. Justo", "San Martin","Avenida Luro", "Guemes", "Rivadavia", "Avenida Constitucion", "Alberti", "Alem",
    "Castelli", "Rawson", "Moreno", "Cordoba", "Jujuy","Avenida Juan José Paso", "Gascon", "Falucho", "Avenida Mario Bravo", "Olavarria",
    "Mitre", "Salta", "La Rioja", "Buenos Aires", "Hipolito Yrigoyen","Alvarado", "Balcarce", "Tucuman", "Garay", "Primera Junta"
};


    strcpy(marDelPlata,calles[rand()%(sizeof(calles)/30)]);
}

void getCalleMiramar(char miramar[])
{
    char calles[][30] = {"Av 9", "Av 26", "Avenida 23", "Av Costanera", "Calle 21","Calle 22", "Calle 23",
                         "Calle 24", "Calle 25","Calle 26","Calle 27", "Calle 28", "Calle 29", "Calle 30", "Calle 31","Calle 32",
                         "Calle 33","Calle 34", "Calle 35","Calle 36","Calle 37", "Calle 38", "Calle 39", "Calle 40", "Calle 41",
                         "Calle 42", "Calle 43","Calle 44", "Calle 45","Calle 46"
                        };
    strcpy(miramar, calles[rand()%(sizeof(calles)/30)]);
}

void getCalleLaPlata(char laPlata[])
{
    char calles[][30] = {"Avenida 7", "Avenida 13", "Avenida 44", "Avenida 51", "Avenida 60","Calle 8", "Calle 9", "Calle 10",
                         "Calle 11", "Calle 12","Calle 14", "Calle 15", "Calle 16", "Calle 17", "Calle 18","Calle 19", "Calle 20", "Calle 21",
                         "Calle 22", "Calle 23","Avenia 44","Avenia 520"
                        };

    strcpy(laPlata, calles[rand()%(sizeof(calles)/30)]);
}
void getCalleSantaClaraDelMar(char santaClaraDelMar[])
{
    char calles[][30] = {"Av Montevideo", "Av Tucuman", "Av San Martin", "Avenida Punta Mogotes", "Entre Rios",
                         "Misiones", "Buenos Aires", "Cordoba", "Corrientes", "Santa Fe","Mendoza","Chaco", "Formosa", "San Juan", "Salta",
                         "Santiago del Estero", "Tierra del Fuego", "Catamarca", "La Rioja", "San Luis"
                        };


    strcpy(santaClaraDelMar, calles[rand()%(sizeof(calles)/30)]);
}

//funcion getNro genera un char a partir de una secuencia random de enteros.
void getNro(char calle[])
{

    int random = (rand()%3)+2;
    char letra[random];
    int vletra = random;
    int i;

    for(i = 0; i < vletra;i++)
    {
        letra[i] = ((rand()%8)+1 )+'0';
    }
    // asigna en el ultimo caracter un \0 para transformar el arreglo de char en una cadena de caracteres;
    letra[i] = '\0';

    return strcpy(calle,letra);
}

// funcion que integra un switch que es ejecuatada por una opcion aleatoria, por el cual devuelve nombres estaticos y como tambien llama
// a funciones que retornan numeros de calles y nombres de calles aleatorios.-
stDomicilio getDomicilioRandom()
{
    stDomicilio d;
    int opcion = (rand()%4)+1;
    char nroCalle;

    switch(opcion)
    {
    case 1:
        getCalleMarDelPlata(d.calle);
        strcpy(d.cpos,"7600");
        strcpy(d.localidad,"Mar del Plata");
        getNro(d.nro);
        strcpy(d.provincia,"Buenos Aires");
        break;
    case 2:
        getCalleMiramar(d.calle);
        strcpy(d.cpos,"7607");
        strcpy(d.localidad,"Miramar");
        getNro(d.nro);
        strcpy(d.provincia,"Buenos Aires");
        break;
    case 3:
        getCalleSantaClaraDelMar(d.calle);
        strcpy(d.cpos,"7107");
        strcpy(d.localidad,"Santa Clara del Mar");
        getNro(d.nro);
        strcpy(d.provincia,"Buenos Aires");
        break;
    case 4:
        getCalleLaPlata(d.calle);
        strcpy(d.cpos,"1900");
        strcpy(d.localidad,"La Plata");
        getNro(d.nro);
        strcpy(d.provincia,"Buenos Aires");
        break;
    }
    return d;
}



