#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;


void inicioEstado(EPersona registro[]);//Inicio de la busqueda mediante el array


int menu(char mensaje[],char error[]);//Elijo las opciones


void ingreso(EPersona registro[]);//Ingreso datos, DNI, etc:


int borrar(EPersona registro[]);//Borrar a una persona por medio del DNI.


void imprimir(EPersona registro[]);//Imprimo en orden alfabetico todas las personas que fueron cargadas al programa


void grafico(EPersona registro[],int a, int b,int c,int d);//Realizo un grafico con las edades menores a 18, entre 19 y 35 y mayores a 35


#endif // FUNCIONES_H_INCLUDED
