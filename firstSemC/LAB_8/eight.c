/*#include<stdio.h>
#include<conio.h>
#include<math.h>
#define val 20

int Armstrong(unsigned int a[val],int n)
{int i,count=0,sum,rem,x;

for(i=0;i<n;i++)
{

    sum=0;
    x=a[i];
    while(a[i]!=0)
    {
    rem=a[i]%10;
    sum+=pow(rem,3);
    a[i]/=10;
    }
 if(x==sum)
    count++;
}
    return(count);
}

void main()
{
    unsigned int a[val],i;
    int c,n;
    printf("ENTER THE LIMIT OF THE ARRAY:\n");
    scanf("%d",&n);
    printf("ENTER THE MEMBERS OF AN ARRAY:\n");
    for(i=0;i<n;i++)
    scanf("%u",&a[i]);

    c=Armstrong(a,n);

    printf("THE TOTAL ARMSTRONG NUMBERS PRESENT IN THE ARRAY IS %d",c);

getch();
}

*/

//2-D
/*#include<stdio.h>
#include<conio.h>
#include<math.h>

void main ()
{
    float a[4][4];
    int i,j,p;
    printf("A 4X4 MATRIX WHOSE ELEMENTS ARE GIVEN BY THE EXPRESSION (aij = 3^-(i+j)):\n");
    printf(" _\t\t\t\t  _\n");

    for(i=0;i<4;i++)
    {
        if(i==3)
        printf("|_");
        else
            printf("| ");
        for(j=0;j<4;j++)
    {
        p= -1*(i+j);
        a[i][j]=(float)pow(3,p);
        printf(" %0.4f ",a[i][j]);
    }
    if(i==3)
    printf("_|");
    else
        printf(" |\n");
    }
    getch();
}
*/
