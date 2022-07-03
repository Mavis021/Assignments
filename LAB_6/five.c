//1
/*#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int i,num,term;
    printf("ENTER THE TERM:");
    scanf("%d",&term);
    for(i=1;i<=term;i++)
        printf("%d ",i);

    getch();
}
*/

//2
/*#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int i,num,term;
    printf("ENTER THE TERM:");
    scanf("%d",&term);
    for(i=2;i<=2*term;i+=2)
        printf("%d ",i);

    getch();
}

*/
//3
/*#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int i,num,term,j;
    printf("ENTER THE TERM:");
    scanf("%d",&term);
    for(i=0;i<=term;i++)
    {
        j=1+i*i;
        printf("%d ",j);
    }
getch();
}
*/

//4
/*#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int term,i,j;
    printf("ENTER THE TERM:");
    scanf("%d",&term);
    for(i=2;i<=term+1;i++)
    {
        j=pow((i-1),2);
        printf("(%d + %d)/%d, ",j,i*i,i);
    }
getch();
}*/

//5
/*#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
    int term,i,j;
    printf("ENTER THE TERM:");
    scanf("%d",&term);
    for(i=1;i<=term;i++)
    {
        j=2*i-1;
        printf("1/%d, ",j);
    }
getch();
}
*/
