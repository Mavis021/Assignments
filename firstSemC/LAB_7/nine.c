/*#include<stdio.h>
#include<conio.h>


int power(int x )
{
    int sign;

    if(x%2==0)
        sign=-1;
    else
        sign=+1;

    if(x==1)
        return(1);
    else
        return (sign*x*x+power(x-1));
}

void main()
{

    int n, sum=0;


    printf("ENTER THE NUMBER OF TERMS:\n");
    scanf("%d",&n);

    sum=power(n);

    printf(" SUM OF %d TERMS = %d",n,sum);

    getch();
}

*/
