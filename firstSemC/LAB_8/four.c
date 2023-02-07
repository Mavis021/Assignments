/*#include<stdio.h>
#include<conio.h>

void main()
{
    int n,a['n'],b['n'],i;

    printf("ENTER THE NUMBER OF ENEMENTS:");
    scanf("%d",&n);

    printf("ENTER THE ELEMENTS OF FIRST ARRAY:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]",i);
        scanf("%d",&a[i]);
    }
     printf("ENTER THE ELEMENTS OF SECOND ARRAY:\n");
    for(i=0;i<n;i++)
    {
        printf("b[%d]",i);
        scanf("%d",&b[i]);
    }

    printf("THE SUM OF TWO ARRAYS :\n");
     printf("a[ ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

      printf("] + b[ ");
      for(i=0;i<n;i++)
        printf("%d ",b[i]);
      printf("] =");

      printf(" c[ ");
      for(i=0;i<n;i++)
      printf("%d ",a[i]+b[i]);
      printf("]");
      getch();

}
*/

/*#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
    int m,n,i,j,a[10][10],b[10][10];

    printf("ENTER THE ROW AND COLLUMN OF THE MATRIX:");
    scanf("%d%d",&m,&n);

    printf("ENTER THE ELEMENTS OF FIRST ARRAY:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
        printf("a[%d][%d]= ",i,j);
        scanf("%d",&a[i][j]);
        }
    }
     printf("ENTER THE ELEMENTS OF SECOND ARRAY:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
        printf("b[%d][%d]= ",i,j);
        scanf("%d",&b[i][j]);
        }
    }

    printf("THE SUM OF TWO ARRAYS :\n");

      for(i=0;i<m;i++)
      {
          for(j=0;j<n;j++)
      printf("%d\t",a[i][j]+b[i][j]);
      printf("\n");
      }
      getch();

}
*/

//dynamic memory allocation.
//1-D array
/*#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
    int n,i;

    printf("ENTER THE NUMBER OF ENEMENTS:");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
    int *b=(int *)malloc(n*sizeof(int));

    printf("ENTER THE ELEMENTS OF FIRST ARRAY:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]= ",i);
        scanf("%d",a+i);
    }
     printf("ENTER THE ELEMENTS OF SECOND ARRAY:\n");
    for(i=0;i<n;i++)
    {
        printf("b[%d]= ",i);
        scanf("%d",b+i);
    }

    printf("THE SUM OF TWO ARRAYS :\n");
     printf("a[ ");
    for(i=0;i<n;i++)
        printf("%d ",*(a+i));

      printf("] + b[ ");
      for(i=0;i<n;i++)
        printf("%d ",*(b+i));
      printf("] =");

      printf(" c[ ");
      for(i=0;i<n;i++)
      printf("%d ",*(a+i)+*(b+i));
      printf("]");

      free(a);
      free(b);
      getch();

}
*/

//2-D array

/*#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
    int m,n,i,j,o;

    printf("ENTER THE ROW AND COLLUMN OF THE MATRIX:");
    scanf("%d%d",&m,&n);

    o=m*n;
    int *a=(int *)malloc(o*sizeof(int));
    int *b=(int *)malloc(o*sizeof(int));

    printf("ENTER THE ELEMENTS OF FIRST ARRAY:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
        printf("a[%d][%d]= ",i,j);
        scanf("%d",a+j+m*i);
        }
    }
     printf("ENTER THE ELEMENTS OF SECOND ARRAY:\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
        printf("b[%d][%d]= ",i,j);
        scanf("%d",b+j+m*i);
        }
    }

    printf("THE SUM OF TWO ARRAYS :\n");

      for(i=0;i<m;i++)
      {
          for(j=0;j<n;j++)
      printf(" %d\t",*(a+j+m*i)+*(b+j+m*i));
      printf("\n");
      }

       free(a);
      free(b);

      getch();

}


*/
