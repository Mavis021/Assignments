/*#include<stdio.h>
#include<conio.h>

long int fact(int n);
int main()
{
    int n;
    long int r;
    printf("enter any number");
    scanf("%d",&n);
    r=fact(n);
    getch();
    return 0;
}
long int fact(int n)
{
    if(n==0)
        return(1);
    else
        return(n*fact(n-1));
}
*//*
#include<stdio.h>
#include<conio.h>

int power(int , int);
int main()
{
    int x,y,r;
    printf("enter the value of x and y:");
    scanf("%d%d",&x,&y);
    r=power(x,y);
    printf("x to the power y =%d",r);

    getch();
    return 0;
}
 int power(int x, int y)
{
    if(y==0)
        return(1);
    else
        return(x*power(x,y-1));
}*/
