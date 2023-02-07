/*#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int a[3],i;

    printf("ENTER THE MEMBERS OF AN ARRAY OF 3 ELEMENTS:\n");
    for(i=0;i<3;i++)
    scanf("%d",&a[i]);

    for(i=0;i<3;i++)
    {
        a[i]=pow(a[i],3);
    }

    printf("\nTHE CUBE OF THE MEMBERS OF THE ARRAY IS:\n [");

    for(i=0;i<3;i++)
        printf("%d ",a[i]);
        printf("]");

    getch();

}
*/

//2-d
/*#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int a[3][3],i,j;

    printf("ENTER THE MEMBERS OF A 3x3 MATRIX:\n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
    scanf("%d",&a[i][j]);

    for(i=0;i<3;i++)
    for(j=0;j<3;j++)
        a[i][j]=pow(a[i][j],5);

    printf("\nTHE MEMBERS OF THE MATRIX POWERED TO 5 IS:\n");
    for(i=0;i<3;i++)
      {
          for(j=0;j<3;j++)
        printf(" %d\t ",a[i][j]);
        printf("\n");
      }

    getch();

}
*/
