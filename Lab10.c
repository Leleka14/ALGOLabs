//Сформувати двовимірний масив. Знищити з нього стовпець із заданим номером;
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int i,j;

int ** create(int SIZE1, int SIZE2);//створення та заповнення масиву
void print(int **array, int SIZE1, int SIZE2);//друк створеного масиву/знищення масивів
void kick (int ** array, int del,int SIZE1, int SIZE2);//видалення заданого рядка


int main()
{
    int SIZE1, SIZE2, del;
    scanf("%d %d", &SIZE1,&SIZE2);//ввід розміру масиву
    int ** array;
    array = create(SIZE1,SIZE2);//створення та заповнення
    print(array, SIZE1, SIZE2);//друк
    printf("Delete a column with number(1-%d): ", SIZE2);
    scanf("%d", &del);//задання номера стовбця для видалення
    del = del-1;
    kick(array, del, SIZE1, SIZE2);//видалення та друк фінального варіанту
}


int** create(int SIZE1, int SIZE2)
{
    srand((int) time (NULL));
    int **array;
    array = (int **) malloc(SIZE1 * sizeof(int*));
    for (i = 0; i<SIZE1; i++)
    {
        array[i] = (int *) malloc(SIZE2 * sizeof(int));
    }//виділення потрібної пам'яті
    for (i = 0; i<SIZE1; i++)
        for(j = 0; j<SIZE2; j++)
        {
            array[i][j] = rand()%27;//заповнення випадковими числами
        }
        return array;
}

void print(int **array, int SIZE1, int SIZE2)
{
    for (i = 0; i<SIZE1; i++)
    {
        for(j = 0; j<SIZE2; j++)
        printf("%2d ", array[i][j]);
        printf("\n");
    }//вивід на екран
}

void kick (int ** array, int del, int SIZE1, int SIZE2)
{
    int **array_upd;
    int o = 0;
    array_upd = (int **) malloc(SIZE1 * sizeof(int*));
    for (i = 0; i<SIZE1; i++)
        array_upd[i] = (int *) malloc((SIZE2-1) * sizeof(int));
        //виділення пам'яті
        for (i = 0; i<SIZE1; i++)
            for(j = 0, o = 0; j<SIZE2-1; j++)
            {
                if (o>SIZE2-1) break;
                if (o==del) o++;
                array_upd[i][j] = array[i][o];
                o++;
            }//заповнення
            for (i = 0; i<SIZE1; i++)
            {
                for(j = 0; j<SIZE2-1; j++)
                {
                    printf("%2d ", array_upd[i][j]);
                }
                printf("\n");
            }//друк
            for (i = 0; i<SIZE1; i++)
            {
                free(array[i]);  //знищення масивів
                free(array_upd[i]);
            }
}
