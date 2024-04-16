#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matriz[5][12], suma = 0, promedio, max, min, mes, anio, mes2, anio2;

    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            matriz[i][j] = rand() % 40001 + 10000;
        }
    }

    puts("Matriz");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // c) sacar promedio

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            suma = suma + matriz[i][j];
        }

        promedio = suma / 12;

        printf("\nPromedio del ano %d\n", i + 1);
        printf("%d", promedio);
    }

    // d) maximo y minimo

    min = matriz[0][0];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (matriz[i][j] <= min)
            {
                min = matriz[i][j];
                anio = i;
                mes = j;
            }
            if (matriz[i][j] >= max)
            {
                max = matriz[i][j];
                anio2 = i;
                mes = j;
            }
        }
    }

    printf("\n\n Valor minimo en el anio %d y el mes %d es: %d", anio + 1, mes + 1, min);
    printf("\n Valor maximo en el anio %d y el mes %d es: %d", anio2 + 1, mes2 + 1, max);

    return 0;
}
