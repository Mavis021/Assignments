/*#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void main()
{
    FILE *fp;
    int year; char ch;

    fp = fopen("D:\\C-PROG\\LEAP_YEAR.txt","a+");
       if (fp==NULL)
    {
        printf("THE FILE CANNOT BE OPPENED.\n");
        exit(1);
    }
    here:
        {
    printf("ENTER A YEAR:\n");
    scanf("%d",&year);
    if((year%4==0)&& ((year%400==0)||(year%100!=0)))
    {
        fprintf(fp," %d \n",year);
        printf("\n THE ENTERED YEAR IS A LEAP YEAR AND HAS BEEN ADDED IN 'LEPYEAR.TXT'.\n DO YOU WANT TO ENTER ANOTHER YEAR? ('Y'OR 'N') ");
        scanf(" %c",&ch);
        if(ch=='Y')
            goto here;
    }
    else
    {
        printf("\n THE ENTERED YEAR WAS NOT A LEAP YEAR:\n DO YOU WANT TO ENTER ANOTHER YEAR? ('Y'OR 'N')");
        scanf(" %c",&ch);
        if(ch=='Y')
            goto here;
    }

        }

        printf("\n YOU CAN VIEW THE YEARS IN {D:\\C-PROG\\LEAP_YEAR.txt}");
        fclose(fp);
    getch();
}
*/
