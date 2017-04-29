#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define P 20
#include<conio.h>




void inicioEstado(EPersona registro[])
{
    int i;

    for(i=0; i<P; i++)
    {
        registro[i].estado=0;
    }
}





int menu(char mensaje[],char error[])
{
    int auxiliar1;
    int auxiliar2;

    printf("%s",mensaje);
    auxiliar2=scanf("%d",&auxiliar1);
    fflush(stdin);

    while(auxiliar2==0 ||(auxiliar1<1||auxiliar1>5))
    {
        printf("%s",error);
        fflush(stdin);
        auxiliar2=scanf("%d",&auxiliar1);
    }

    return auxiliar1;
}





void ingreso(EPersona registro[])
{
    int i;
    int auxiliar;

    for(i=0; i<P; i++)
    {
        if(registro[i].estado==0)
        {
            registro[i].estado=1;
            printf("Ingrese Nombre y Apellido: ");
            fflush(stdin);
            gets(registro[i].nombre);

            printf("Ingrese la  edad: ");
            fflush(stdin);
            auxiliar=scanf("%d",&registro[i].edad);

            while(auxiliar==0 || (registro[i].edad<1 || registro[i].edad>100))
            {
                printf("Error, Ingrese la edad nuevamente: ");
                fflush(stdin);
                auxiliar=scanf("%d",&registro[i].edad);
            }

            printf("Ingrese el numero DNI: ");
            fflush(stdin);
            auxiliar=scanf("%d",&registro[i].dni);

            while(auxiliar==0)
            {
                printf("Error, reingrese el DNI nuevamente: ");
                fflush(stdin);
                auxiliar=scanf("%d",&registro[i].dni);
            }

            break;
        }
    }
}





int borrar(EPersona registro[])
{
    int i;
    int bandera=0;
    int borrar;
    char pregunta;

    printf("\nIngrese en numero de DNI de la persona a borrar: ");
    fflush(stdin);
    scanf("%d",&borrar);

    for(i=0; i<P; i++)
    {
        if(registro[i].dni==borrar)
        {
            printf("\nEsta a punto de borrar a %s. Desea continuar? (Digite s=si o n=no)\n\n",registro[i].nombre);
            pregunta=getche();

            if(pregunta == 's')
            {
                registro[i].estado=0;
                printf("\n\nLa persona fue borrada exitosamente\n\n");
            }

            else
            {
                printf("\n\nLa persona no fue borrada\n\n");
            }

            bandera=1;
            break;
        }
    }

    if(bandera==0)
    {
        printf("\nLa persona con ese DNI no se encuentra registrada\n\n");
    }

    return registro[i].estado;
}





void imprimir(EPersona registro[])
{
    EPersona datos;
    int i;
    int r;

    for(i=0; i<P-1; i++)
    {
        for(r=i+1; r<P; r++)
        {
            if(stricmp(registro[i].nombre,registro[r].nombre)>0)
            {
                datos = registro[r];
                registro[r]= registro[i];
                registro[i]= datos;
            }
        }
    }

    for(i=0; i<P; i++)
    {
        if(registro[i].estado==1)
        {
            printf("%s-----%d-----%d\n",registro[i].nombre,registro[i].edad,registro[i].dni);
        }
    }
}





void grafico(EPersona registro[],int a, int b, int c, int d)
{
    int i;
    int bandera;

    for(i=0; i<P; i++)
    {

        bandera=0;

        if(registro[i].estado==1)
        {
        if(registro[i].edad<=18)
        {
            a++;
        }

        else
        {
            if(registro[i].edad>35)
            {
                c++;
            }
            else
            {
                b++;
            }
        }
        }
    }

    if(a >= b && a >= c)
    {
        d=a;
    }

    else
    {
        if(b >= a && b >= c)
        {
            d=b;
        }
        else
        {
            d=c;
        }
    }

    for(i=d; i>0; i--)
    {
        if(i<10)
        {
            printf("%02d|",i);
        }

        else
        {
            printf("%02d|",i);
        }

        if(i<=a)
        {
            printf("*");
        }

        if(i<=b)
        {
            bandera=1;
            printf("\t*");
        }

        if(i<=c)
        {
            if(bandera==0)
            {
                printf("\t\t*");
            }

            if(bandera==1)
            {
                printf("\t*");
            }
        }

        printf("\n\n");

    }

    printf("--+-----");
    printf("\n  |<18\t19-35\t>35 \n");

}
