/*#include<stdio.h>
#include<conio.h>

int main()
{
    int forward, backward=0, num,rem;
    printf("Enter the number:\n");
    scanf("%d",&num);
    forward = num;
    while(num!=0)
    {
        rem= num%10;
        backward=backward*10+rem;
        num/=10;
    }
    if(forward==backward)
        printf("%d is a palindrome.",forward);
    else
        printf("%d is not a palindrome.",forward);

    getch();
}*/
/*#include<stdio.h>
#include<conio.h>

int main()
{
    int x, sum=0, num,rem;
    printf("Enter the number:\n");
    scanf("%d",&num);
    x= num;
    while(num!=0)
    {
        rem= num%10;
        sum=sum+(rem*rem*rem);
        num/=10;
    }
    if(x==sum)
        printf("%d is an Armstrong number.",x);
    else
        printf("%d is not an Armstrong number.",x);

    getch();
}*/
/*
#include<stdio.h>
#include<conio.h>

int main()
{
    int  num,x;
    printf("Enter the number: ");
    scanf("%d",&num);
    x= num;


    if(x%2!=0 && x%3!=0 && x%5!=0 && x%7!=0 && x!=1 && x>=3 ||x==2 || x==3 || x==5 || x==7)
        printf("%d is a prime number.",x);

    else
            printf("%d is not a prime number.",x);

    getch();
}*/
/*#include<stdio.h>
#include<conio.h>

int main()
{
    int  x,y;
    printf("ENTER ANY TWO PRIME NUMBERS:\n");
    scanf("%d%d",&x,&y);

    if(x%2!=0 && x%3!=0 && x%5!=0 && x%7!=0 && x!=1 && x>=3 ||x==2 || x==3 || x==5 || x==7)
    {

    if(y%2!=0 && y%3!=0 && y%5!=0 && y%7!=0 && y!=1 && y>=3 ||y==2 || y==3 || y==5 || y==7)
    {
    if(x-y==2 || y-x==2)
     printf("%d AND %d ARE TWIN PRIMES.",x,y);

    else
            printf("%d AND %d ARE NOT TWIN PRIMES.",x,y);
    }
    }
    getch();
}*/
