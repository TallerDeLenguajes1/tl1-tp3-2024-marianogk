#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarNombres(char **nombres);
void mostrarNombres(char **nombres);

int main()
{
    char *buff, **nombres;

    nombres = (char **)malloc(5 * sizeof(char *)); // Asigno memoria a la lista de 5 nombres

    cargarNombres(nombres);
    mostrarNombres(nombres);

    return 0;
}

void cargarNombres(char **nombres)
{
    char *buff;

    buff = (char *)malloc(100 * sizeof(char)); // Asigno memoria dinamica al buffer para 100 caracteres

    for (int i = 0; i < 5; i++)
    {
        puts("Ingrese un nombre: ");
        gets(buff);

        nombres[i] = (char *)malloc((strlen(buff) + 1) * sizeof(char)); // Asigno memoria a cada nombre ingresado, con la longitud + 1 para el '/0'
        strcpy(nombres[i], buff);
    }
}

void mostrarNombres(char **nombres)
{
    for (int i = 0; i < 5; i++)
    {
        printf("\nNombre %d: ", i + 1);
        puts(nombres[i]);
    }
}