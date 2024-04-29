#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarNombres(char **nombres, int cant);
void mostrarNombres(char **nombres, int cant);
void liberarMemoria(char **nombres, int cant);

int main()
{
    char *buff, **nombres;
    int cant;

    printf("\nIngrese la cantidad de nombres: ");
    scanf("%d", &cant);

    nombres = (char **)malloc(cant * sizeof(char *)); // Asigno memoria a la lista de nombres

    cargarNombres(nombres, cant);
    mostrarNombres(nombres, cant);
    liberarMemoria(nombres, cant);

    return 0;
}

void cargarNombres(char **nombres, int cant)
{
    char *buff;

    buff = (char *)malloc(100 * sizeof(char)); // Asigno memoria dinamica al buffer para 100 caracteres

    for (int i = 0; i < cant; i++)
    {
        fflush(stdin);
        puts("Ingrese un nombre: ");
        gets(buff);

        nombres[i] = (char *)malloc((strlen(buff) + 1) * sizeof(char)); // Asigno memoria a cada nombre ingresado, con la longitud + 1 para el '/0'
        strcpy(nombres[i], buff);
    }
}

void mostrarNombres(char **nombres, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        printf("\nNombre %d: ", i + 1);
        puts(nombres[i]);
    }
}

void liberarMemoria(char **nombres, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        free(nombres[i]); // Libero la memoria para cada nombre
    }
    free(nombres); // Libero la memoria asignada para el arreglo de nombres
}