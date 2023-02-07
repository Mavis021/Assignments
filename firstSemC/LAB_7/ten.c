#include<stdio.h>
#include<conio.h>

long int fact( int n)
{
    if (n==0)
        return (1);
    else
        return (n*fact(n-1));
}

float power(float x ,int y)
{
    if(y==0)
        return (1);
    else
        return (x*power(x,y-1));
}

void main()
{
    float x, degree, numerator, term, sum=0;
    int i,t,sign=-1, pow;
    long int deno;

    printf("ENTER THE VALUE OF x IN DEGREE: ");
    scanf("%f",&x);

    printf("\nENTER THE NUMBER OF TERMS :");
    scanf("%d",&t);

    degree = x;
    x = (x*3.14)/180;

    for(i=1;i<=t;i++)
    {
        sign*= -1;
        pow= 2*i-1;
        deno= fact(pow);
        numerator = power(x,pow);

        term= (sign*numerator)/deno;
        sum+=term;
    }

    printf("\n sin(%0.2f) = %0.3f",degree,sum);

    getch();
}


