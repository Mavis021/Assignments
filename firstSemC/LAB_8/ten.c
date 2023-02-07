/*#include<stdio.h>
#include<conio.h>
#define max 10

void calc(float a[max])
{
    int p,i,j;

    //ascending order
    for(i=0;i<max;i++)
        for(j=i;j<max;j++)
            if(a[i]>a[j])
            {
                p=a[i];
                a[i]=a[j];
                a[j]=p;
            }
    printf("\nASCENDING ORDER:\n ARRAY MEMBERS \t POSITION\n");
    for(i=0;i<max;i++)
        printf(" %g \t\t %d \n",a[i],i+1);

printf("\nHEIGEST MEMBER = %g\n",a[max-1]);
printf("\nLOWEST MEMBER = %g\n",a[0]);
}

void main()
{
    float a[max];
    int i;
    printf(" ENTER ALL 10 MEMBERS OF THE ARRAY:\n");
    for(i=0;i<max;i++)
    {
        printf("a[%d]= ",i+1);
        scanf("%f",&a[i]);
    }
    calc(a);
   printf("\nTHE SUM OF HIGHEST AND LOWEST MEMBER OF THE ARRAY IS %g.\n",a[max-1]+a[0]);
   printf("\nTHE DIFFERENCE OF HIGHEST AND THE LOWEST MEMBER OF THE ARRAY IS %g.\n",a[max-1]-a[0]);

getch();
}
*/

//2-D
/*#include<stdio.h>
#include<conio.h>
#define max 10

void processMatrix(int a[][max], int b[][max],int m,int n, int q)
{
    int c[max][max];

    for(int i=0;i<m;i++)
        for(int j=0;j<q;j++)
    {
        c[i][j]=0;
        for(int k=0;k<n;k++)
            c[i][j]+=a[i][k]*b[k][j];
    }
   showMatrix(c,m,q);
}

void readMatrix(int m[][max],int x,int y)
{
    int i,j;
    for(i=0;i<x;i++)
        for(j=0;j<y;j++)
        scanf("%d",&m[i][j]);
}

void showMatrix(int m[][max],int x,int y)
{
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        printf(" \t%d ",m[i][j]);
         printf("\n");
    }
}

void main()
{
    int c[max][max],a[max][max],b[max][max],m,n,p,q;
    here:
        {
    printf("ENTER THE ORDER OF FIRST MATRIX(<10):\n");
    scanf("%d%d",&m,&n);
    printf("ENTER THE ORDER OF SECOND MATRIX(<10):\n");
    scanf("%d%d",&p,&q);

    if(n==p)
    {
        printf("ENTER THE ELEMENTS OF FIRST MATRIX:\n");
        readMatrix(a,m,n);
    }
    else
    {
    printf("PLEASE ENTER A VALID ORDERS OF MATRIX:\n");
    goto here;
    }}

    printf("ENTER THE ELEMENTS OF SECOND MATRIX:\n");
    readMatrix(b,p,q);

     printf("THE PRODUCT MATRIX IS:\n");
      processMatrix(a,b,m,n,q);



      getch();
}
*/
