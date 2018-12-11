//1)Скопіювати з файлу F1 у файл F2 всі рядки, крім тих, що починаються на букву А.
//2)Підрахувати кількість символів у першому слові F2.

#include <stdio.h>

//запис у F1
void write();
//копіювання у F2 з дотримання умови варіанту
void rewrite();
//вирахування кількості букв у першому слові F2
void WordNumber();

int main()
{
    write();
    rewrite();
    WordNumber();
}

//запис у F1
void write()
{
    FILE *f1;
    f1 = fopen("wer.txt", "w");
    char a[100];
    for (int i = 0; i<10; i++)
    {
        fgets(a,100,stdin);
        fputs(a,f1);
    }
    fclose(f1);
}

//копіювання у F2 з дотримання умови варіанту
void rewrite()
{
    FILE*f1, *f2;
    char a[100];
    f1 = fopen("wer.txt", "r");
    f2  =fopen("rew.txt", "w");
    while (fgets (a, 100, f1)!=NULL)
    if ( a[0]!='A') fputs(a,f2);
    fclose(f1);
    fclose(f2);
}

//вирахування кількості букв у першому слові F2
void WordNumber()
{
    FILE *f2;
    char a[100];
    f2  =fopen("rew.txt", "r");
    fgets (a, 100, f2);
    int j = 0;
    do
    {
        j++;
    }
    while (a[j]!=' ');
    printf ("%d\n", j);
    fclose(f2);
}
