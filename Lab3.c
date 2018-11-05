#include <stdio.h>
#include <math.h>

int main(void)
{
    float a = 0.1, b = 0.8, e = 0.0001;
    #define M_PI 3.141592
    for(float x=a; x<=b; x+=(b-a)/10)
    {
        float y, SN = 0, SE = 0, Summ;
        y = (x * sin(M_PI / 3)) / (1 - 2 * x * cos(M_PI / 4) + pow(x, 2));
        for(int n = 1; n <= 40; n++)
        {
             Summ = pow(x, n + 1) * sin(n + 1 * (M_PI / 4));
             SN +=Summ;
        }
        float Sum = 0;
        int j = 0;
        do
        {
        	j++;
            Sum = pow(x, j + 1) * sin(j + 1 * (M_PI / 4));
            SE += Sum;
        }
        while( fabs(Sum)>=e);
        printf("X=%f    Y=%f    SN=%f    SE=%f\n", x, y, SN, SE);
    }

}
