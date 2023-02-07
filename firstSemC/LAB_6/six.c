//1
/*#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int term,i,j, sum=2;
    printf("ENTER THE TERM:");
    scanf("%d",&term);
    printf("\n s = 2 ");

    for(i=2;i<=term;i++)
    {
        j=i*2;
        printf("+ %d ",j);
        sum+=j;
    }
    printf("= %d",sum);
getch();
}

*/

//2
/*#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int term,i,j,n,k, sign=1;
    float  sum=1,t, den;
    printf("ENTER THE TERM:");
    scanf("%d",&term);
    printf("S = 1/e = 1 ");
    for(n=1;n<=term-1;n++)
    {
        sign*=-1;
        j=pow(-1,(n+1));
        printf("+(%d/%d!) ",j,n);

         den =1;
         for (k=1;k<=n;k++)
            den*=k;
         t= sign/den;
         sum +=t;
    }
     printf("= %f",sum);
getch();
}

*/
//3
/*#include<stdio.h>
#include<conio.h>
#include<math.h>
 int main()
 {
     int i, j, n,den=1,  sign=-1;
     float x, sum=0,term, num;
     printf("ENTER THE VALUE OF x:\n");
     scanf("%f",&x);
    printf("ENTER THE NUMBER OF TERMS:\n");
     scanf("%d",&n);

     for (i=0;i<=n-1;i++)
     {
         sign*=-1;
         num = pow(x,2*i);
         den =1;
         for (j=1;j<=2*i;j++)
            den*=j;
         term= (sign*num/den);
         sum +=term;
     }
     printf("f(%f) = 1- x^2/2! + x^4/4! - x^6/6!...= %f",x,sum);

     getch();

 }
*/
