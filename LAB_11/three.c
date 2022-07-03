/*#include<stdio.h>
#include<conio.h>

struct date
{
    int dd; int mm ; int yy;
};

struct person
{
char name[50];
char address[50];
long int telephone;
struct date dob;
};

void main()
{
    struct person p[50];
    int i,j; char a;
    printf("\n \t\t\t\tINFORMATION COLLECTION:\n");

    for(i=0;i<50;i++)
    {
    printf("\n%d. NAME:\t",i+1);
    scanf(" %[^\n]",p[i].name);

    printf("\n ADDRESS:\t");
    scanf(" %[^\n]",p[i].address);

    printf("\n CONTACT NO.:\t");
    scanf("%ld",&p[i].telephone);

    printf("\n D.O.B :\n");
    printf("DATE:\t");
    scanf("%d",&p[i].dob.dd);

     printf("MONTH:\t");
    scanf("%d",&p[i].dob.mm);

     printf("YEAR:\t");
    scanf("%d",&p[i].dob.yy);

    printf("\n ENTER 'N' or 'n' TO STOP OR ANY OTHER KEY TO CONTINUE:");
    scanf(" %c",&a);
    if(a=='N'|| a=='n')
        break;
    }
    printf("\n THE REGISTERED DETAILS:");

    printf("\n S.N\t NAME \t\t\t\tADDRESS \t\tTELEPHONE \tD.O.B");

    for(j=0;j<=i;j++)
    {
        printf("\n %d\t %s \t\t%s \t\t%ld \t\t%d/%d/%d",j+1,p[j].name,p[j].address,p[j].telephone,p[j].dob.dd,p[j].dob.mm,p[j].dob.yy);
    }
    getch();
}
*/
