#include <stdio.h>
#define LEN 255

int main()
{
    char str[LEN];
    FILE *to;
    to = fopen("to.txt","r+a");
    if (to != NULL)
    {
        while(fgets(str, LEN, to))
            printf("%s", str);   
    }
    else
    printf("Error");
return 1;
}



#include <stdio.h>
#define LEN 100

int main()
{
    char PIB[LEN];
    FILE *f;
    f = fopen("f.txt","r+a");
    if (f != NULL)
    {
        while(fgets(PIB, LEN, f))
            printf("%s", PIB);
    }
    else
    printf("Error\n");
return 1;
}
