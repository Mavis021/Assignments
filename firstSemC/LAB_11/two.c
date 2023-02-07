/*#include<stdio.h>
#include<conio.h>

struct employee
{
char name[50];
char telephone[50];
int salary;

};

void main()
{
    int i,b,j,average=0;
    printf("REGISTER 10 OF YOUR EMPLOYEES:");
    struct employee e[10],e11;

    for(i=0;i<10;i++)
    {
    printf("\n%d. NAME:\t",i+1);
    scanf(" %[^\n]",e[i].name);

    printf("\n CONTACT INFO:\t");
    scanf(" %[^\n]",e[i].telephone);

    printf("\n SALARY :\t");
    scanf("%d",&e[i].salary);
    }
    for(i=0;i<10;i++)
    {
    for(j=i+1;j<10;j++)
    {
        if(e[i].salary<e[j].salary)
        {
            e11=e[i];
            e[i]=e[j];
            e[j]=e11;

        }
    }
    }
    for(i=0;i<10;i++)
        average+=(e[i].salary)/10;

        printf("\n SORTING FROM HIGHEST PAID TO LOWEST PAID:\n");
    for(i=0;i<10;i++)
    printf("\n EMPLOYEE %d:\n NAME:\t\t%s\n CONTACT INFO:\t%s\n SALARY:\t\t%d\n",i+1,e[i].name,e[i].telephone,e[i].salary);

    printf("\n HENCE, THE AVERAGE SALARY OF ALL TEN EMPLOYEE IS %d.",average);

    getch();
}
*/
