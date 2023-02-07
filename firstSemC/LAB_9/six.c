
//DYNAMIC MEMORY ALLOCATION

/*#include<stdio.h>
#include<conio.h>

void main()
{
    int sum=0,i;
    int *a= (int *)calloc(5,sizeof(int));
    if(a==NULL)
    {
    printf("MEMORY COULDN'T BE ALLOCATED");
    exit(1);
    }

    printf("ENTER THE ELEMENTS OF AN ARRAY of size 5:\n");

    for(i=0;i<5;i++)
    {
        printf("a[%d]=",i);
        scanf("%d",&a[i]);
        if(a[i]%10==0&&a[i]%15!=0)
        sum+=a[i];
        printf("\n");
    }

    printf("THE SUM OF ELEMENTS DIVISIBLE BY 10 BUT NOT BY 15 IS %d",sum);
    free(a);

    getch();
}
*/

// seven
/*#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
    int n,i;

    printf("ENTER THE NUMBER OF ENEMENTS:");
    scanf("%d",&n);
    int *a=(int *)malloc(n*sizeof(int));
     if(a==NULL)
    {
    printf("MEMORY COULDN'T BE ALLOCATED");
    exit(1);
    }
    int *b=(int *)malloc(n*sizeof(int));
     if(b==NULL)
    {
    printf("MEMORY COULDN'T BE ALLOCATED");
    exit(1);
    }

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

//eight
/*#include<stdio.h>
#include<conio.h>

void main()
{
    int b,i,j;
    int *a = (int *)calloc(5,sizeof(int));
     if(a==NULL)
    {
    printf("MEMORY COULDN'T BE ALLOCATED");
    exit(1);
    }

    printf("ENTER THE ELEMENTS OF AN ARRAY OF SIZE 5:\n");
    for(i=0;i<5;i++)
    {
        printf("a[%d] = ",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<5;i++)
    {
        for(j=i;j<5;j++)
        {
            if(a[j]>a[i])
            {
             b=a[i];
             a[i]=a[j];
             a[j]=b;
            }
        }
    }
    printf("THE HIGHEST ELEMENT IS %d.",*(a+0));
    printf("\nTHE LOWEST ELEMENT IS %d.",*(a+4));

    free(a);
    getch();
}
*/

//nine
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
     if(a==NULL)
    {
    printf("MEMORY COULDN'T BE ALLOCATED");
    exit(1);
    }

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
    }*/

    //ten
  /*  #include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int i;
    int *a= (int *)calloc(3,sizeof(int));
     if(a==NULL)
    {
    printf("MEMORY COULDN'T BE ALLOCATED");
    exit(1);
    }

    printf("ENTER THE MEMBERS OF AN ARRAY OF 3 ELEMENTS:\n");
    for(i=0;i<3;i++)
    scanf("%d",(a+i));

    for(i=0;i<3;i++)
    {
        *(a+i)=pow(*(a+i),3);
    }

    printf("\nTHE CUBE OF THE MEMBERS OF THE ARRAY IS:\n [");

    for(i=0;i<3;i++)
        printf("%d ",*(a+i));
        printf("]");

        free(a);
    getch();

}
*/

// eleven
/*#include<stdio.h>
#include<conio.h>
#include<math.h>


int Armstrong(unsigned int *a,int n)
{int i,count=0,sum,rem,x;

for(i=0;i<n;i++)
{

    sum=0;
    x=*(a+i);
    while(*(a+i)!=0)
    {
    rem=*(a+i)%10;
    sum+=pow(rem,3);
    *(a+i)/=10;
    }
 if(x==sum)
    count++;
}
    return(count);
}

void main()
{
    unsigned int i;
    int c,n;
    printf("ENTER THE LIMIT OF THE ARRAY:\n");
    scanf("%d",&n);

    unsigned int *a = (unsigned int *)calloc(n,sizeof(unsigned int));
    if(a==NULL)
    {
        printf("MEMORY CANNOT BE ALLOCATED.");
        exit(1);
    }
    printf("ENTER THE MEMBERS OF AN ARRAY:\n");
    for(i=0;i<n;i++)
    scanf("%u",(a+i));

    c=Armstrong(a,n);

    printf("THE TOTAL ARMSTRONG NUMBERS PRESENT IN THE ARRAY IS %d",c);

    free(a);
getch();
}
*/

//twelve
/*#include<stdio.h>
#include<conio.h>

void median(float *a,int n)
{
     int term1,term3, term2;
     term1 =(n+1)/2;
     term3=n/2;
     term2 = (n/2)+1;
     if(n%2!=0)
     {
      printf(" THE MEDIAN OF THE SERIES IS %0.2f\n",*(a+term1-1));
     }
     else
     {
         printf(" THE MEDIAN OF THE SERIES IS %0.2f\n",((*(a+term3-1)+*(a+term2-1))/2));
     }
}

void range(float *a,int n)
{
   printf("\n THE RANGE OF THE SERIES IS %0.2f\n",*(a+n-1)-*(a+0));
}

void variance(float *a,int n)
{
    float sumxn=0,sumxsqn=0,value;
    int i;
    for(i=0;i<n;i++)
        sumxn+=*(a+i)/n;
    for(i=0;i<n;i++)
        sumxsqn+=pow(*(a+i),2)/n;

     value=sumxsqn-pow(sumxn,2);
        printf("\n THE VARIANCE OF THE SERIES IS %0.2f\n",value);
}

void Standarddeviation(float *a,int n)
{
    float sumxn=0,sumxsqn=0,value,sd;
    int i;
    for(i=0;i<n;i++)
        sumxn+=*(a+i)/n;
    for(i=0;i<n;i++)
        sumxsqn+=pow(*(a+i),2)/n;

     value=sumxsqn-pow(sumxn,2);
     sd=sqrt(value);
        printf("\n THE STANDARD DEVIATION OF THE SERIES IS %0.3f.",sd);
}

void main()
{
    int i,b,n,j;

    printf("ENTER THE LIMIT OF THE ARRAY:\n");
    scanf("%d",&n);

    float *a = (float *)calloc(n,sizeof(float));
    if(a==NULL)
    {
        printf("MEMORY CANNOT BE ALLOCATED.");
        exit(1);
    }

    printf("ENTER THE ELEMENTS OF THE ARRAY:\n");
    for(i=0;i<n;i++)
    {
        printf("a[%d]=",i+1);
        scanf("%f",(a+i));
        printf("\n");
    }

    //ascending order
    for(i=0;i<n;i++)
 {
     for(j=i;j<n;j++)
    {
        if(*(a+i)>*(a+j))
            {
                b=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=b;
            }
    }
}

median(a,n);
range(a,n);
variance(a,n);
Standarddeviation(a,n);

free(a);
getch();
}
*/

//thirteen
/*#include<stdio.h>
#include<conio.h>
#define max 10

void calc(float *a)
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

printf("\nHEIGEST MEMBER = %g\n",*(a+max-1));
printf("\nLOWEST MEMBER = %g\n",*(a+0));
}

void main()
{
    float *a = (float *)malloc(max*sizeof(float));
    if(a==NULL)
    {
        printf("MEMORY COULDNOT BE ALLOCATED.");
        exit(1);
    }
    int i;
    printf(" ENTER ALL 10 MEMBERS OF THE ARRAY:\n");
    for(i=0;i<max;i++)
    {
        printf("a[%d]= ",i+1);
        scanf("%f",(a+i));
    }
    calc(a);
   printf("\nTHE SUM OF HIGHEST AND LOWEST MEMBER OF THE ARRAY IS %g.\n",*(a+max-1)+*(a+0));
   printf("\nTHE DIFFERENCE OF HIGHEST AND THE LOWEST MEMBER OF THE ARRAY IS %g.\n",*(a+max-1)-*(a+0));

free(a);
getch();
}
*/
