#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buff, **nombre;
    buff = (char *)malloc(100 * sizeof(char));

    for (int i = 0; i < 5; i++)
    {
        puts("Ingrese un nombre: ");
        gets(buff);

        **nombre = (char **)malloc(5 * sizeof(char));
        strcpy(nombre, buff);

        for (int j = 0; j < strlen(buff) + 1; j++)
        {
            *nombre = (char *)malloc((strlen(buff) + 1) * sizeof(char));
            strcpy(nombre, buff);
        }
    }

    return 0;
}
