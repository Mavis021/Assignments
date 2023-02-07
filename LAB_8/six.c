/*#include<stdio.h>
#include<conio.h>
void descending(int *a,int n)
{int i, b, j;
     for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[j]>a[i])
            {
             b=a[i];
             a[i]=a[j];
             a[j]=b;
            }
        }
    }
}

void ascending(int a[], int n)
{int i, b, j;
     for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[j]<a[i])
            {
             b=a[i];
             a[i]=a[j];
             a[j]=b;
            }
        }
    }
}

void main()
{
    int b,i,j,n;
    printf("NUMBER OF ENEMENTS YOU WANT TO ENTER:\n");
    scanf("%d",&n);

    int *a=(int *)malloc(n*sizeof(int));
    printf("ENTER THE ELEMENTS OF AN ARRAY:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d] = ",i+1);
        scanf("%d",&a[i]);
    }
   descending(a,n);
   printf("\nTHE SORTED ARRAY IN DESCENDING ORDER IS:");
   for(i=0;i<n;i++)
   {
       printf("\n%d",a[i]);
   }

    ascending(a,n);
   printf("\n\nTHE SORTED ARRAY IN ASCENDING ORDER IS:");
   for(i=0;i<n;i++)
   {
       printf("\n%d",a[i]);
   }

   free(a);
   getch();
    }
*/
/*
#include<stdio.h>
#include<conio.h>
#define max 3

int diasum(int a[][max])
{int i,j, sum=0;

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
    {
        if(i==j)
            sum+=a[i][j];
    }
    return(sum);
}


void main()
{
    int s,a[max][max],i,j;

    printf("ENTER THE ELEMENTS OF A 3x3 MATRIX:\n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
    {
        printf("a[%d][%d] = ",i+1,j+1);
        scanf("%d",&a[i][j]);
    }

    printf("\nTHE ENTERED MATRIX,\n");
     for(i=0;i<3;i++)
      {
          for(j=0;j<3;j++)
            printf(" %d\t",a[i][j]);
        printf("\n");
      }

   s=diasum(&a);
   printf("\nTHE SUM OF MAIN DIAGONAL OF THE 3X3 ARRYAY IS: %d",s);


   getch();
    }
*/
