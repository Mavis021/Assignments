/*#include<stdio.h>
#include<conio.h>

void countsDigits(int *,int *);
void main()
{
    unsigned int a,x;
    int CO1=0,CO2=1,CE2=1,CE1=0,rem, countev, countod;
     printf("ENTER A LONG INTEGER NUMBER:\n");
    scanf("%u",&a);
    x=a;

    while(a)
    {
        rem=a%10;
         a/=10;
        if(rem%2==0)
        countsDigits(&CE1,&CE2);
        else
        countsDigits(&CO1,&CO2);
    }

    printf("THERE ARE %d EVEN NUMBERS AND %d ODD NUMBERS IN %u.",CE1,CO1,x);
  getch();
}

void countsDigits(int *a,int *b)
{
    *a = *a+*b;
}

*/
