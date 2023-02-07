/*#include<stdio.h>
#include<conio.h>

int fact(unsigned int a)
{
    if(a==0)
        return(1);
    else
        return(a*fact(a-1));
}
int power(int a, int b)
{
    if(b==0)
        return(1);
    else
        return(a*power(a,b-1));
}
int sum(int a)
{
    if(a==0)
        return(0);
    else
    return(a+sum(a-1));
}
int HCF(int a , int b,int s)
{
   if(a%s==0&&b%s==0)
    return(s);
   else
    return(HCF(a,b,s-1));
}
void main()
{
    int n1, n2;
    printf("ENTER ANY TWO NUMBERS:\n");
    scanf("%d%d",&n1,&n2);

    if(n1>0)
    printf("\n THE FACTORIAL OF %d IS %d",n1,fact(n1));
    else
    printf("\n THE FACTORIAL OF %d CANNOT BE CALCULATED.\n",n1);
    if(n2>0)
    printf("\n THE FACTORIAL OF %d IS %d\n",n2,fact(n2));
    else
    printf("\n THE FACTORIAL OF %d CANNOT BE CALCULATED.\n",n2);

    printf("\n %d^%d = %d",n1,n2,power(n1,n2));
    printf("\n %d^%d = %d\n",n2,n1,power(n2,n1));

    printf("\n SUM FROM 1 to %d = %d",n1,sum(n1));
    printf("\n SUM FROM 1 to %d = %d\n",n2,sum(n2));

    if(n2>n1)
    printf("\n THE HCF OF %d AND %d IS %d",n1,n2,HCF(n1,n2,n2));
    else
    printf("\n THE HCF OF %d AND %d IS %d",n1,n2,HCF(n2,n1,n1));


    getch();
}

*/
