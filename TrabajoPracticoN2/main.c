#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define C 20

int main()
{
    char seguir='s';
    int opcion=0;
    int menores;
    int medio;
    int mayores;
    int mayorTotal;


    EPersona registro[C];

    inicioEstado(registro);

    while(seguir=='s')
    {
        printf("1- Agregar una persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                    ingreso(registro);

                    break;

            case 2:
                    borrar(registro);

                    break;

            case 3:
                    imprimir(registro);

                    break;

            case 4:
                    menores=0;
                    medio=0;
                    mayores=0;
                    grafico(registro,menores,medio,mayores,mayorTotal);

                    break;

            case 5:
                    seguir = 'n';

                    break;

        }

    }

    return 0;
}
