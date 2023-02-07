/*#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, n=5;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            printf("%2d",j);
            printf("\n");
    }
    getch();
}
*/

//b
/*#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, n=5;

    for(i=1;i<=n;i++)
    {
        for(j=5;j>=i;j--)
            printf("%2d",j);
            printf("\n");
    }


    getch();
}
*/

//3
/*#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, n=5;
    char name[10]="NEPAL";


   for(i=1;i<=n;i++)
    {
        printf("%d",i);
        for(j=1;j<=i;j++)

            printf("%2c",name[i-1]);
            printf("\n");
    }


    getch();
}*/

//4
/*#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, n=5;
    char name1[5]="ABCDE";
    char name2[5]="AbCdE";

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(i%2==0)
             printf("%2c",name1[j-1]);

             else
                printf("%2c",name2[j-1]);
        }
            printf("\n");
    }


    getch();
}
*/

//5
/*#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, k, n=5;

    for(i=1;i<=n;i++)
    {
        for(j=i;j<n;j++)
         printf(" # ");

        for(k=5;k>(n-i);k--)
            printf(" * ");
            printf("\n");
    }


    getch();
}*/
//6
/*#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, k, n1=7, n2=4;

    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n2;j++)
     {
         if((i+j)<=n2 || (i-j)>=n2 )
            printf("   ");
         else
     printf(" %d ",j);
    }
            printf("\n");


    }
    getch();
}
*/

//7
/*#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, k, n=4;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=7;j++)
     {
         if( i>j || (i+j)>8  )
        printf("   ");
         else
     printf(" * ");
    }
            printf("\n");


    }
    getch();
}

*/
//8
/*#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, k, n=12;

    for(i=0;i<=3;i++)
    {
        for(j=1;j<=(7-i);j++)
        printf("  ");

        for(k=1;k<12;k++);
            if(k==(6+i)||k==(6+i))
        printf(" %d ",i);


            printf("\n");

    }
    getch();
}*/
//9
/*#include<stdio.h>
#include<conio.h>

void main()
{
    int i, j, k, n=4;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(4-i);j++)
            printf("   ");
        for(j=1;j<=i;j++)
     printf(" %d ",j);
         for(j=i-1;j>0;j--)
            printf(" %d ",j);
            printf("\n");

    }
    getch();
}
*/

//8
#include<stdio.h>
#include<conio.h>

void main()
{

    int row, col, temp, n;
    printf("ENTER THE NUMBER THAT YOU WANT AT THE CENTRE OF THE DIAMOND PATTERN: ");
    scanf("%d",&n);

    // upper part
    for(row=0;row<=n;row++)
    {
        for(col=0;col<=2*n;col++)
        {
            if(row<=(n/2))
            {
                if(col==(n-row)|| col==(n+row))
                 printf(" %d ",row);
                else
                    printf("   ");
            }

            else if((n/2)<row<=n)
            {
                if(col==(n-row)|| col ==(n+row))
                    printf(" %d ",n-row);
                else if(col == row)
                printf(" %d ",row);
                else if(col==(2*n-row))
                    printf(" %d ",row);
                else
                    printf("   ");
            }

        }

        printf("\n");
    }

    temp = row;
     // lower part
    for(row=temp;row<=2*n;row++)
    {
        for(col=0;col<2*n;col++)
        {
            if(row<(n+(n/2)))
            {
                if(col==(row-n)|| col ==(3*n-row))
                    printf(" %d ",(row-n));
                else if(col == row)
                printf(" %d ",(2*n-row));
                else if(col==(2*n-row))
                    printf(" %d ",(2*n-row));
                else
                    printf("   ");
            }

            else
            {
                if(col==(row-n))
                 printf(" %d ",(n-col));
                 else if(col==(3*n-row))
                    printf(" %d ",(col-n));
                else
                    printf("   ");
            }


        }

        printf("\n");
    }

    getch();
}

