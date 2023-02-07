/*#include<stdio.h>
#include<conio.h>

void main()
{
    int m,n,p,q,a[10][10],b[10][10]; int c[10][10];
    printf("ENTER THE SIZE OF FIRST MATRIX:\n");
    scanf("%d%d",&m,&n);
    printf("ENTER THE VALUES OF ITS MEMBERS:\n");
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
    {
        printf("a[%d][%d]= ",i,j);
        scanf("%d",&a[i][j]);
    }

    printf("ENTER THE SIZE OF SECOND MATRIX:\n");
    scanf("%d%d",&p,&q);
    if(n=p)
    {
    printf("ENTER THE VALUES OF ITS MEMBERS:\n");
    for(int i=0;i<p;i++)
        for(int j=0;j<q;j++)
    {
        printf("b[%d][%d]= ",i,j);
        scanf("%d",&b[i][j]);
    }

    }

    else
    {printf("ERROR: PLEASE ENTER A VALID MATRIX SIZE.\n");}





    for(int k=0;k<m;k++)
        for(int l=0; l<q; l++)
    {
        for(int i=0;i<n;i++)
            printf("%d....%d\n",a[k][n],b[n][k]);
        c[k][l]+= a[k][n]*b[n][k];
    }

     printf("\n MULTIPLICATION OF THE TWO MATRICES:\n ");
     for(int k=0;k<m;k++)
     {printf("|");
        for(int l=0; l<q; l++)
      printf(" %d ",c[k][l]);
      printf("|\n");
     }

     getch();
}
*/
