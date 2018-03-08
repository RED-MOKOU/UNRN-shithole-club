/*5) Escriba y ejecute un programa que mantenga información de números complejos (usando el tipo de datos definido en el trabajo práctico 0). Se desea tener 2 matrices de complejos (de 10 filas por 10 columnas) y realizar la suma y resta de dichas matrices. Implemente con funciones.*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 10

typedef struct
{
    int real, imag;
}tipoComplejo;

int inicializarMatrizCompleja (tipoComplejo c, int mreal[DIM][DIM], int mimag[DIM][DIM])
{
    int i, j;
    for (i = 0; i < DIM; i++)
        for (j = 0; j < DIM; j++)
            {
                c.real=rand() %10;
                c.imag=rand() %10;
                mreal[i][j] = c.real;
                mimag[i][j] = c.imag;
            }

    return 0;
}

int imprimirComplejo (tipoComplejo c, int mreal[DIM][DIM], int mimag[DIM][DIM])
{
    int i, j;
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            printf("(%d + %di) ", mreal[i][j], mimag[i][j]);
        }

        printf("\n");
    }
    return 0;
}

int sumarMatrizCompleja(tipoComplejo c, int mreal1[DIM][DIM],
    int mreal2[DIM][DIM], int mimag1[DIM][DIM], int mimag2[DIM][DIM],
    int mresr[DIM][DIM], int mresi[DIM][DIM])
{
    int i, j;
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            mresr[i][j] = mreal1[i][j] + mreal2[i][j];
            mresi[i][j] = mimag1[i][j] + mreal2[i][j];
        }
    }
    return 0;
}

int restarMatrizCompleja(tipoComplejo c, int mreal1[DIM][DIM], int mreal2[DIM][DIM], int mimag1[DIM][DIM], int mimag2[DIM][DIM], int mresr[DIM][DIM], int mresi[DIM][DIM])
{
    int i, j;
    for (i = 0; i < DIM; i++)
    {
        for (j = 0; j < DIM; j++)
        {
            mresr[i][j] = mreal1[i][j] - mreal2[i][j];
            mresi[i][j] = mimag1[i][j] - mreal2[i][j];
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    int mreal1[DIM][DIM], mimag1[DIM][DIM], mreal2[DIM][DIM], mimag2[DIM][DIM], mresr[DIM][DIM], mresi[DIM][DIM];
    tipoComplejo c;
    inicializarMatrizCompleja(c, mreal1, mimag1);
    imprimirComplejo(c, mreal1, mimag1);
    printf("\n");
    inicializarMatrizCompleja(c, mreal2, mimag2);
    imprimirComplejo(c, mreal2, mimag2);
    printf("\n");
    sumarMatrizCompleja(c, mreal1, mimag1, mreal2, mimag2, mresr, mresi);
    imprimirComplejo(c, mresr, mresi);
    printf("\n");
    restarMatrizCompleja(c, mreal1, mimag1, mreal2, mimag2, mresr, mresi);
    imprimirComplejo(c, mresr, mresi);

}
