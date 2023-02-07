/*#include<stdio.h>
#include<conio.h>

void main()
{
    int a[5],b,i,j;

    printf("ENTER THE ELEMENTS OF AN ARRAY OF SIZE 5:\n");
    for(i=0;i<5;i++)
    {
        printf("a[%d] = ",i);
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
    printf("THE HIGHEST ELEMENT IS %d.",a[0]);
    printf("\nTHE LOWEST ELEMENT IS %d.",a[4]);
    getch();
}
*/

//2-D array
/*#include<stdio.h>
#include<conio.h>

void main()
{
    int a[3][3],b,i,j,k,l;

    printf("ENTER THE ELEMENTS OF AN ARRAY OF SIZE 3x3:\n");
    for(i=0;i<3;i++)
    {
        for(k=0;k<3;k++)
        {printf("a[%d][%d] = ",i+1,k+1);
        scanf("%d",&a[i][k]);
        }
    }
    for(i=0;i<3;i++)
    {
        for(k=0;k<3;k++)
        {
            for(l=0;l<3;l++)
            {
        for(j=0;j<3;j++)
        {
            if(a[l][j]>a[i][k])
            {
             b=a[i][k];
             a[i][k]=a[l][j];
             a[l][j]=b;
            }
        }
            }
        }
    }
    printf("THE HIGHEST ELEMENT IS %d.",a[2][2]);
    printf("\nTHE LOWEST ELEMENT IS %d.",a[0][0]);

    getch();
}
*/
