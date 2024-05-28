#include <stdio.h>
#include <stdlib.h>
#include "domicilio.h"
#include <string.h>
#include <conio.h>
#include <time.h>
#include "mockDomicilio.h"

int main()
{
    srand(time(NULL));


    stDomicilio d;
    d = getDomicilioRandom();
    muestraUnDomicilio(d);









    return 0;


}

