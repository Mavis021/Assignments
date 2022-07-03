//1D
/*#include<stdio.h>
#include<conio.h>
#define limit 20
void median(float a[limit],int n)
{
     int term1,term3, term2;
     term1 =(n+1)/2;
     term3=n/2;
     term2 = (n/2)+1;
     if(n%2!=0)
     {
      printf(" THE MEDIAN OF THE SERIES IS %0.2f\n",a[term1-1]);
     }
     else
     {
         printf(" THE MEDIAN OF THE SERIES IS %0.2f\n",(a[term3-1]+a[term2-1])/2);
     }
}

void range(float a[limit],int n)
{
   printf("\n THE RANGE OF THE SERIES IS %f\n",a[n-1]-a[0]);
}

void variance(float a[limit],int n)
{
    float sumxn=0,sumxsqn=0,value;
    int i;
    for(i=0;i<n;i++)
        sumxn+=a[i]/n;
    for(i=0;i<n;i++)
        sumxsqn+=pow(a[i],2)/n;

     value=sumxsqn-pow(sumxn,2);
        printf("\n THE VARIANCE OF THE SERIES IS %0.2f\n",value);
}

void Standarddeviation(float a[limit],int n)
{
    float sumxn=0,sumxsqn=0,value,sd;
    int i;
    for(i=0;i<n;i++)
        sumxn+=a[i]/n;
    for(i=0;i<n;i++)
        sumxsqn+=pow(a[i],2)/n;

     value=sumxsqn-pow(sumxn,2);
     sd=sqrt(value);
        printf("\n THE STANDARD DEVIATION OF THE SERIES IS %f.",sd);
}

void main()
{
    int i,b,n,j;
    float a[limit];
    printf("ENTER THE LIMIT OF THE ARRAY:\n");
    scanf("%d",&n);
    printf("ENTER THE ELEMENTS OF THE ARRAY:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=",i+1);
        scanf("%f",&a[i]);
        printf("\n");
    }

    //ascending order
    for(i=0;i<n;i++)
 {
     for(j=i;j<n;j++)
    {
        if(a[i]>a[j])
            {
                b=a[i];
                a[i]=a[j];
                a[j]=b;
            }
    }
}

//median(a,n);
//range(a,n);
//variance(a,n);
Standarddeviation(a,n);

getch();
}

*/
//2D
/*#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
    int i,j,r,c,o;
    printf("ENTER THE ROW OF MATRIX:");
    scanf("%d",&r);
    printf("ENTER THE COLUMN OF MATRIX:");
    scanf("%d",&c);
    o=r*c;
    int *a=(int *)malloc(o*sizeof(int));
    int *sum=(int *)malloc(r*sizeof(int));

    printf("ENTER THE MEMBERS OF THE MATRIX:\n");
    for(i=0;i<r;i++)
     {
        for(j=0;j<c;j++)
    {
        printf("a[%d][%d]= ",i,j);
        scanf("%d",a+j+(r*i+1));
    }
    printf("\n");
     }
       printf("\n THE GIVEN MATRIX,\n");
      for(i=0;i<r;i++)
     {
    for(j=0;j<c;j++)
    {
        printf(" \t%d",*(a+j+(r*i+1)));

    }
    printf("\n");
     }

    for(i=0;i<r;i++)
    {
       sum[i]=0;
        for(j=0;j<c;j++)
    {
        sum[i]+=*(a+j+(r*i+1));
    }
    }

    printf("\nTHE SUM OF MEMBERS OF EACH ROWS OF THE MATRIX ARE:\n");
    for(i=0;i<r;i++)
        {printf(" %d ",sum[i]);
        printf("\n");}

        free(a);
        free(sum);
    getch();
}

*/
