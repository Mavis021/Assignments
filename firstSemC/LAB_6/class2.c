/*#include<stdio.h>
#include<conio.h>

int swap(int *a , int *b)
{
    int z;
    z=*a;
    *a=*b;
    *b=z;
}

void main()
{
   int x, y;
   printf("Enter the values of x and y");
   scanf("%d%d",&x,&y);

   printf("\nTHE VALUES OF X AND Y BEFORE SWAP x=%d AND x = %d",x,y);
   swap(&x,&y);
   printf("\nAFTER SWAPPING THE VALUES BECOMES x = %d AND y = %d",x,y);

   getch();
}
*/


// LOCAL VARIABLE
/*#include<stdio.h>
#include<conio.h>

void first();
void second();

void main()
{
    int a =100, b=20,c;
    second();
    c=a/b;
    first();
    printf("\n IN MAIN c= %d",c);
    getch();
}

void second()
{
    int a= 1000, b=10, c;
    c=a/b;

    printf("\n IN SECOND FUNCTION c = %d",c);
}
void first()
{
    int a= 100, b=5, c;
    c=a/b;

    printf("\n IN FIRST FUNCTION c = %d",c);
}
*/

// GLOBAL VARIABLED: these variables can be accessed by any function comprising the program.
// They are bot recreated if the function is recalled. To declare a global variable, we declare it
//outside the functions before main.
/*#include<stdio.h>
#include<conio.h>

void first();
void second();

int a=1, b=2, c;

void main()
{
    first();
    a, b;
    c= a+b;

    printf("\n IN MAIN a+b = %d",c);
   printf("\n%d ",&a);
    getch();
}

void first()
{

    second();
      c= a+b;
    printf("\n IN FIRST a+b = %d",c);
      printf("\n%d ",&a);
}

void second()
{
    printf("ENTER THE VALUES OF a AND b:");
    scanf("%d%d",&a,&b);
      printf("\n%d ",&a);
}
*/
//Extent of variables(lifetime, longevity)
// The time period during which the memory is associated with the variable
//in called the extend of the variable. The life time of a variable is catagorized by the storage class.
//The storage class of a variable indicates the allocation of storage space to the variable.
//The storage classes are of four types:

// a. Auto variable , register variable, static variable, Extern variable


// Find the average of 5 elements of one dimensional array

/*#include<stdio.h>
#include<conio.h>
void main()
{
    float a[5],avg, sum=0;
    int i;
    for(i=0;i<5;i++)
    {
        printf("\n a[%d] = ",i);
         scanf("%f",&a[i]);
         sum+=a[i];
    }
    avg = sum/5;
    printf("Average = %f",avg);
    getch();
}
*/
//WAP to find the largest element of an array.
/*#include<stdio.h>
#include<conio.h>
void main()
{
    int a[5],largest;
    int i,j;
    for(i=0;i<5;i++)
    {
        printf("\n a[%d] = ",i);
         scanf("%d",&a[i]);
    }
   largest= a[0];
         for(i=1;i<5;i++)
         {
             if(a[i]>largest)
                largest = a[i];
         }
    printf("largest = %d",largest);
    getch();
}*/
