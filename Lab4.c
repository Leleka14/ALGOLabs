#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int i, j, n;
    printf("Elements in array?");
    scanf("%i", &i);
    int array[i];
    srand(time(NULL));
    for(j = 0; j < i; j++)
    {
        array[j] = rand()%20;
    }
    for(j = 0; j < i; j++)
    {
        printf("%i ", array[j]);
    }
    printf("\n");
    printf("Delete element with number?");
    scanf("%i", &n);
    int k = 0, m = 0;
    int array2[i];
    for(j = 0; j < i; j++)
    {
        if(array[j] != n)
        {
            k++;
            array2[m] = array[j];
            m++;
        }
        else
        {
            continue;
        }
    }
    for(j = 0; j < m; j++)
    {
        printf("%i ", array2[j]);
    }
    printf("\n");
    for(j = 0; j < k; j++)
    {
        if(array2[j]%2 != 0)
        {
            printf("%i ", array2[j]);
        }
        else
        {
            printf("0 ");
            printf("%i ", array2[j]);
        }
    }
    printf("\n");
}
