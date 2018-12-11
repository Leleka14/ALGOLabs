//Структура "Студент":
//-	прізвище, ім'я, по батькові;
//-	домашня адреса;
//-	група;
//-	рейтинг.
//Знищити всі елементи, у яких рейтинг меншее заданого, додати 1 елемент у кінець файлу.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct STUDENT
{
    char PIB [100];
    char address [100];
    char group[100];
    int rating;
};


void write(FILE *f);//запис данних у файл f.txt
void read(FILE *f); //виведення даних файлу
int find (FILE *f);//пошук студентів з рейтингом нижче 25
void kick(FILE *f, int l);//комісія
void add(FILE *f);//додання нового студента


int main ()
{
    FILE *f;
    f=fopen("f.txt", "w");
    write(f);
    fclose(f);
    f=fopen("f.txt","r");
    read(f);
    fclose(f);
    f=fopen("f.txt","r");
    int  o = find(f);
    fclose(f);
    f=fopen("f.txt","w");
    kick(f,o);
    fclose(f);
    f = fopen ("f.txt","a");
    add(f);
    fclose(f);
}

//запис данних у файл f.txt
void write(FILE *f)
{
    struct STUDENT e;
    for (int i= 0; i<3; i++)
    {
    //зчитування даних студента
        printf("Full Name: ");
        scanf("%[^.]%*c", e.PIB);
        //if (i>0) e.PIB[0]=' ';
        printf("Adress: ");
        scanf("%[^.]%*c", e.address);
        //e.address[0]=' ';
        printf("Group: ");
        scanf("%[^.]%*c", e.group);
        //e.group[0]=' ';
        printf("Rating: ");
        scanf("%d.", &e.rating);
        //запис
        fwrite(&e, sizeof(struct STUDENT),1,f);
    }
}

//читання данних
void read(FILE *f)
{
    struct STUDENT mas[3];
    int i = 0;
    while(!feof(f)&&i<3)
    {
        fread(&mas[i], sizeof(struct STUDENT),1,f);
        printf("Student %d: ", i+1);
        printf("\nПІБ:%s.\nАдреса:%s.\nГрупа:%s.\nРейтинг: %i\n", mas[i].PIB, mas[i].address, mas[i].group, mas[i].rating);
        i++;
    }
}

//пошук елементів з рейтингом більших 25
int find (FILE *f)
{
    FILE *help;
    int k = 0;
    struct STUDENT mas[3];
    help=fopen("help.txt", "w");
    for (int i = 0; i<3; i++)
    {
    fread(&mas[i], sizeof(struct STUDENT),1,f);
    if (mas[i].rating>25)
    {
        fwrite(&mas[i], sizeof(struct STUDENT),1,help); k++;}
    }
    fclose(help);
    return k;
}

//виданення непотрібних елементів
void kick(FILE *f,int l)
{
    FILE *help;
    struct STUDENT mas[3];
    int i =0;
    help=fopen("help.txt", "r");
    while(!feof(f)&&i<l)
    {
        fread(&mas[i], sizeof(struct STUDENT),1,help);
        fwrite(&mas[i], sizeof(struct STUDENT),1,f);
        i++;
    }
    fclose (help);
}

//додання нового елементу
void add(FILE *f)
{
    struct STUDENT e;
    printf("NEW STUDENT:");
    printf("Full Name: ");scanf("%[^.]%*c", e.PIB);
    printf("Adress: ");scanf("%[^.]%*c", e.address);
    printf("Group: ");scanf("%[^.]%*c", e.group);
    printf("Rating: "); scanf("%d", &e.rating);
    fwrite(&e, sizeof(struct STUDENT),1,f);
}
