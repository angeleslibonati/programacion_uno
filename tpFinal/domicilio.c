#include <stdio.h>
#include <stdlib.h>
#include "domicilio.h"
#include <string.h>
#include <conio.h>

void getCalle(char calle[])
{
    char calles[][30] = {"Avenida Col�n", "Avenida Independencia", "Avenida Juan B. Justo","San Mart�n", "Avenida Luro", "G�emes", "Rivadavia",
                       "Avenida Constituci�n", "Alberti", "Alem","Castelli", "Rawson","Moreno","C�rdoba","Jujuy","Avenida Juan Jos� Paso", "Gasc�n", "Falucho",
                       "Avenida Mario Bravo","Olavarr�a","Mitre","Salta","La Rioja","Buenos Aires","Hip�lito Yrigoyen","Alvarado","Balcarce",
                       "Pe�a","Garay","Primera Junta","Brandsen","Ayacucho","Tripulantes del Fournier","French","3 de Febrero","11 de Septiembre","9 de Julio",
                       "25 de Mayo","Bol�var","Brown","San Luis","Catamarca","Santiago del Estero","Avellaneda","Formosa","Vieytes","Gasc�n","Bermejo","Las Heras"
                      };

    strcpy(calle,calles[rand()%(sizeof(calles)/30)]);
}

int getNro()
{
return (rand()%9000)+1;
}

