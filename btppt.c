#include "stdio.h"
#include "math.h"

#define eps 0.000001

double g(double x)
{
    return cos(2*x) -3*x +5;
}

double h(double x)
{
    return exp(x) + 10*x -7 ;
}

double f(double x)
{
    return x*x;
}

double daoham(double x,double (*fx)(double))
{   
    double dentax = 0.1;
    double term = 1,y = 1;
    do
    {
        term = y;
        y = (fx(x+dentax)-fx(x))/dentax;
        dentax = dentax/10;
    } while (fabs(term - y)> eps);
    
    return y;
    
}

int main()
{

    double x;
    printf("hay nhap gia tri can tinh: ");
    scanf("%lf", &x);
    printf("gia tri dao ham fx la: %0.0lf\n",daoham(x,f));
    printf("gia tri dao ham gx la: %.6lf\n",daoham(x,g));
    printf("gia tri dao ham hx la: %.6lf\n",daoham(x,h));

    return 0;
}