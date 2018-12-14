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
