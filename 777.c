#include <stdio.h>
#include <stdlib.h>



int sum (int , ...);


int main(){
    printf("%d\n", sum(3, 4, 5, 6));
    printf("%d\n", sum(7, 4, 5, 6, 2 ,3, 5, 7));
    printf("%d\n", sum(11, 3, 2, 6, 7, 9, 3, 4, 3, 4, 5, 4));
    return 0;
}

int sum (int n, ...){
int *p = &n; 
int s=0;
for ( ; n!=0;n--)
s+=*(++p);
return s;
}
