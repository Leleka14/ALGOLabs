//Перетворити рядок так, щоб всі букви в ньому були відсортовані за зростанням.
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sort(int k, int b, char* a)
{
    int min,c;
    for(int i = k; i<b; i++)
    {

        min = i;
        for (int j = i+1; j<b; j++)
        {
            if (*(a+j)<*(a+min))
                min = j;
        }
        if (min!=i)
        {
            c = *(a+i);
            *(a+i) = *(a+min);
            *(a+min) = c;
        }
     }
}
int main(){
    char a[255];
    int i = 0;
    //ввід рядка
    do
    {
        a[i] = getchar();
        i++;
    }
    while (a[i-1]!='\n');

    int len = strlen(a);

    int k = 0, l = 0;
    //сортування слів відносно коду ASCII
    while( a[k]!='\n')
    {
        k++;
        if  (!isalpha(a[k]))
        {
            sort(l, k, a);
            l = k+1;
        }
    }
    for (i = 0; i<len-1; i++)
        printf ("%c", a[i]);
        printf("\n");
}
