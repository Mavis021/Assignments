/*#include<stdio.h>
#include<conio.h>
#include<math.h>
int fact(int x)
{
    if (x==0)
    return (1);
    else
        return(x*fact(x-1));
}
void main()
{
    int x, i=1, y, t, power ;
    float sum=1, term , nume, deno ;
    printf("ENTER THE VALUE OF x:\n");
    scanf("%d",&x);
    y= pow(10,-6);

    do
    {
        power = i++;
        nume = pow(x,power);
        deno = fact(power);
        term= nume/deno;
        sum+=term;
        }while(term>y);

    printf("Sn= 1 + x/1! + (x^2)/2! + (x^3)/3!+... = %f",sum) ;

    getch();
}

*/
