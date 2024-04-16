#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matriz[5][12], suma = 0, promedio;

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

    // c) sacar promedio //

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            suma = suma + matriz[i][j];
        }

        promedio = suma / 12;

        printf("\nPromedio del ano %d\n",i+1);
        printf("%d",promedio);
    }

    

    return 0;
}
