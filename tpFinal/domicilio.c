#include <stdio.h>
#include <stdlib.h>
#include "domicilio.h"
#include <string.h>
#include <conio.h>

void getCalle(char calle[])
{
    char calles[][30] = {"Avenida Colón", "Avenida Independencia", "Avenida Juan B. Justo","San Martín", "Avenida Luro", "Güemes", "Rivadavia",
                       "Avenida Constitución", "Alberti", "Alem","Castelli", "Rawson","Moreno","Córdoba","Jujuy","Avenida Juan José Paso", "Gascón", "Falucho",
                       "Avenida Mario Bravo","Olavarría","Mitre","Salta","La Rioja","Buenos Aires","Hipólito Yrigoyen","Alvarado","Balcarce",
                       "Peña","Garay","Primera Junta","Brandsen","Ayacucho","Tripulantes del Fournier","French","3 de Febrero","11 de Septiembre","9 de Julio",
                       "25 de Mayo","Bolívar","Brown","San Luis","Catamarca","Santiago del Estero","Avellaneda","Formosa","Vieytes","Gascón","Bermejo","Las Heras"
                      };

    strcpy(calle,calles[rand()%(sizeof(calles)/30)]);
}

int getNro()
{
return (rand()%9000)+1;
}

