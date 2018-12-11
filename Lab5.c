#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n, j, i;
    printf("Ryadky array?");
    scanf("%i", &m);
    printf("Stovpzi array?");
    scanf("%i", &n);
    int array[m][n];
    for(j = 0; j < m; j++)
    {
        for(i = 0; i < n; i++)
        {
            printf("Array[%i][%i] = ", j+1, i+1);
            scanf("%i", &array[j][i]);
        }
    }
    for(j = 0; j < m; j++)
    {
        for(i = 0; i < n; i++)
        {
            printf("%i ", array[j][i]);
        }
        printf("\n");
    }
    printf("Transponovana\n");
    for(j = 0; j < m; j++)
    {
        for(i = 0; i < n; i++)
        {
            printf("%i ", array[i][j]);
        }
        printf("\n");
    }
    printf("Checking for symmetric...\n");
    int x = 0;
    for (j = 0; j < m; j++)
    {
        for(i = 0; i < n; i++)
        {
            if (j!=m  && array[j][i]!=array[i][j])
            {
                x = 1;
            }
        }
    }

    if (x == 1)
    {
        printf("It is not symmetric");
    }
    else
    {
        printf("It is symmetric");
    }
    printf("\n");
}
