#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto;

typedef struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos;  // El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
} Cliente;

void cargarClientes(Cliente **c, int cantC);
void cargarProductos(Producto **p, int *cantP);
void mostrar(Cliente **c, int cantC);
float totalProducto(Producto p);

int main()
{
    Cliente **c;
    int cantC = 0;

    printf("\nIngrese la cantidad de clientes: ");
    scanf("%d", &cantC);

    c = (Cliente **)malloc(cantC * sizeof(Cliente *));

    cargarClientes(c, cantC);

    mostrar(c, cantC);

    return 0;
}

void cargarClientes(Cliente **c, int cantC)
{
    char *buff;
    int cantP = 0;

    buff = (char *)malloc(50 * sizeof(char)); // Asigno memoria dinamica al buffer para 50 caracteres

    srand(time(NULL));

    for (int i = 0; i < cantC; i++)
    {
        c[i] = (Cliente *)malloc(sizeof(Cliente));

        printf("\nCliente %d\n", i);
        c[i]->ClienteID = i;

        fflush(stdin);
        puts("Ingrese el nombre: ");
        gets(buff);

        c[i]->NombreCliente = (char *)malloc((strlen(buff) + 1) * sizeof(char)); // Asigno memoria a cada nombre ingresado, con la longitud + 1 para el '/0'
        strcpy(c[i]->NombreCliente, buff);

        c[i]->CantidadProductosAPedir = 1 + rand() % 5;

        cantP = c[i]->CantidadProductosAPedir;

        cargarProductos(&(c[i]->Productos), &cantP);
    }
    free(buff);
}

void cargarProductos(Producto **p, int *cantP)
{
    char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
    int k = 0;

    *p = (Producto *)malloc(*cantP * sizeof(Producto));

    for (int j = 0; j < *cantP; j++)
    {
        (*p + j)->ProductoID = j;
        (*p + j)->Cantidad = 1 + rand() % 10;

        k = rand() % 5; // genero un indice aleatorio para el tipo
        (*p + j)->TipoProducto = (char *)malloc(strlen(TiposProductos[k]) + 1);

        strcpy((*p + j)->TipoProducto, TiposProductos[k]);

        (*p + j)->PrecioUnitario = (10 + rand() % 90001)/1000.0f;
    }
}

void mostrar(Cliente **c, int cantC)
{
    float total;
    for (int i = 0; i < cantC; i++)
    {
        total=0;
        printf("\n-CLIENTE ID %d-\n", c[i]->ClienteID);
        printf("Nombre: ");
        puts(c[i]->NombreCliente);
        printf("\nCantidad de productos: %d\n", c[i]->CantidadProductosAPedir);

        puts("\n-PRODUCTOS-");
        for (int j = 0; j < c[i]->CantidadProductosAPedir; j++)
        {
            printf("\nProducto ID %d\n", c[i]->Productos[j].ProductoID);
            printf("\nCantidad: %d\n", c[i]->Productos[j].Cantidad);
            printf("Tipo: ");
            puts(c[i]->Productos[j].TipoProducto);
            printf("Precio unitario: %.2f\n", c[i]->Productos[j].PrecioUnitario);
            printf("Total producto: %.2f\n", totalProducto(c[i]->Productos[j]));
            total+=totalProducto(c[i]->Productos[j]);
        }
        printf("\nTOTAL A PAGAR: %.2f\n", total);
    }
}

float totalProducto(Producto p)
{
    float total;
    total = p.Cantidad * p.PrecioUnitario;
    return total;
}