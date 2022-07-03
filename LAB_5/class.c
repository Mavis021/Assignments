/*#include<stdio.h>
#include<conio.h>
#include<math.h>
 int main()
 {
     int i, j, n, sign=-1,den=1;
     float x, sum=0,term, num;
     printf("Enter the value of x in radian and number of terms n:\n");
     scanf("%f%d",&x ,&n);

     for (i=0;i<n;i++)
     {
         sign*=-1;
         num = pow(x,2*i);
         den =1;
         for (j=1;j<=2*i;j++)
            den*=j;
         term= sign*(num/den);
         sum +=term;
     }
     printf("cos(%f)= %f",x,sum);

     getch();

 }*/

/* #include<stdio.h>
#include<conio.h>
#include<math.h>
 int main()
 {
     int i, j, n,den=1;
     float x, sum=0,term, num;
     printf("Enter the value of x in radian and number of terms n:\n");
     scanf("%f%d",&x ,&n);

     for (i=1;i<=n;i++)
     {
         num = pow(x,i);
         den =1;
         for (j=1;j<=i;j++)
            den*=j;
         term= (num/den);
         sum +=term;
     }
     printf("f(%f)= %f",x,sum);

     getch();

 }

*/
