#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int matriz[5][12];
 
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
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
