/*
#include<stdio.h>
#include<conio.h>

struct edetails
{
char name[50];
char address[50];
long int phone;
long int salary;

};

void main()
{
    int n,i;
    printf("\n HOW MANY EMPLOYEES DO YOU WANT TO REGISTER:\n");
    scanf("%d",&n);
    struct edetails e[n];
    for(i=0;i<n;i++)
    {
    printf("\n%d. NAME:\t ",i+1);
    scanf(" %[^\n]",e[i].name);

    printf("\n ADDRESS:\t");
    scanf(" %[^\n]",e[i].address);

    printf("\n CONTACT NO.:\t");
    scanf("%ld",&e[i].phone);

    printf("\n SALARY :\t");
    scanf("%ld",&e[i].salary);
    }
    for(i=0;i<n;i++)
    {
    printf("\n NEW EMPLOYEE %d:\n NAME:\t\t%s\n ADDRESS:\t%s\n CONTACT INFO:\t%ld\n SALARY:\t\t%ld\n",i+1,e[i].name,e[i].address,e[i].phone,e[i].salary);
    }

    getch();
}
*/
