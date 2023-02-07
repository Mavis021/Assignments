/*#include<stdio.h>
#include<conio.h>

void main()
{
    int num, base=1, rem, sum=0 , x;
    printf("Enter a decimal number:");
    scanf("%d",&num);
    x=num;
while(num!=0)
{
    rem =num%2;
    sum=sum+rem*base;
    base=base*10;
    num=num/2;
}
printf("The binary equivalent of %d =%d",x,sum);
getch();
}*/

/*#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int num, rem, sum=0, x,i=0;
    printf("Enter a binary number:");
    scanf("%d",&num);
    x=num;
    while(num!=0)
 {
        rem=num%10;
        sum=sum+rem*pow(2,i);
        i++;
        num=num/10;
}
printf("decimalnumber:%d",sum);
    getch();
}
*/
//WAP to display a chessboard.
/*#include<stdio.h>
#include<conio.h>
void main()
{
    int i, j;
    for (i=1;i<=8;i++)
    {
        for (j=1;j<=8;j++)
        {
            if((i+j)%2==0)
                printf("\xdb");
            else
                printf(" ");
        }
        printf("\n");
    }

    getch();
}
*/
//write a program to display the following pattern

/*1
1 2
1 2 3
1 2 3 4
1 2 3 4 5

#include<stdio.h>
#include<conio.h>
int main()
{
    int num,i,j;
    printf("Enter a number:");
    scanf("%d",&num);

    for(i=1;i<=num;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    getch();
}*/
//WAP to read integer number and add the individual digits contained in it until the final sum is single digit.
/*#include<stdio.h>
#include<conio.h>
void main()
{
    int sum,rem;
    long int num;
    printf("Enter an integer number:");
    scanf("%ld",&num);
     do
     {
         sum=0;
         do
         {
             rem= num%10;
             sum=sum+rem;
             num=num/10;
         }while(num!=0);
         num=sum;

     }while(sum/10!=0);
     printf("Sum=%d",sum);

    getch();
}

#include<stdio.h>
#include<conio.h>
int main()
{
    int num,i,j;
    printf("Enter a number:");
    scanf("%d",&num);

    for(i=1;i<=num;i++)
    {
        for(j=1;j<=num;j++)
        {
            printf("%d",j);
        }
        printf("\n");
    }
    getch();
}*/
/*#include<stdio.h>
#include<conio.h>
int main()
{
    int num,i,j;
   printf("Enter a number:");
   scanf("%d",&num);


 for(j=1;j<=num;j++)
 {

    for(i=1;i<=j;i++)

        {
            printf("%d",i);
        }
        printf("\n");
    }
    getch();
}*/
/*#include<stdio.h>
#include<conio.h>
int main()
{
    int num,i,j;
   printf("Enter a number:");
   scanf("%d",&num);


 for(j=1;j<=num;j++)
 {

    for(i=1;i<=j;i++)

        {
            printf("*",i);
        }
        printf("\n");
    }
    getch();
}*/
/*#include<stdio.h>
#include<conio.h>
int main()
{
    int num,i,j;
   printf("Enter a number:");
   scanf("%d",&num);


 for(j=num;1<=j<=num;j--)
 {

    for(i=num;i<=j;i--)

        {
            printf("%d",i);
        }
        printf("\n");
    }
    getch();
}*/

