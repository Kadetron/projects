#include<stdio.h>
typedef struct complex{
int r;
int i;
}complex;
complex add(complex,complex);
complex sub(complex,complex);
complex multi(complex,complex);
complex divd(complex,complex);
void main()
{
    struct complex x,y,r;
    int n;
    printf("Enter the 1st real part: ");
    scanf("%d",&x.r);
    printf("Enter the 1st imaginary part: ");
    scanf("%d",&x.i);
    printf("Enter the 2nd real part: ");
    scanf("%d",&y.r);
    printf("Enter the 2nd imaginary part: ");
    scanf("%d",&y.i);
    printf("OPTIONS:\n1.Addition\n2.Substraction\n3.Multiplication\n4.Division");
    printf("\nEnter choice: ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
        r=add(x,y);
        printf("The result is: %d+(%di)",r.r,r.i);
        break;
        case 2:
        r=sub(x,y);
        printf("The result is: %d+(%di)",r.r,r.i);
        break;
        case 3:
        r=multi(x,y);
        printf("The result is: %d+(%di)",r.r,r.i);
        break;
        case 4:
        r=divd(x,y);
        printf("The result is: %d+(%di)",r.r,r.i);
        break;
        default:
            printf("wrong input");
    }
}
complex add(complex x, complex y)
{
    struct complex z;
    z.r=x.r+y.r;
    z.i=x.i+y.i;
    return z;
}
complex sub(complex x, complex y)
{
    struct complex z;
    z.r=x.r-y.r;
    z.i=x.i-y.i;
    return z;
}
complex multi(complex x, complex y)
{
    struct complex z;
    z.r=(x.r*y.r)-(x.i*y.i);
    z.i=(x.r*y.i)+(x.i*y.r);
    return z;
}
complex divd(complex x, complex y)
{
    struct complex z;
    z.r=(x.r*y.r)+(x.i*y.i)/(y.r*y.r+y.i*y.i);
    z.i=(x.i*y.r)-(x.r*y.i)/(y.r*y.r+y.i*y.i);
    return z;
}
