/*#include<stdio.h>
#include<conio.h>
#include<string.h>

void arrange(char s[10][50])
{
    int i,j,c;
    char b[50];

    for(i=0;i<10;i++)
    {
        for(j=i+1;j<10;j++)
        {
            c=strcmp(s[i],s[j]);
            if(c>0)
                {
                strcpy(b,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],b);
                }
        }
    }
}

void main()
{
    int i;
    char sname[10][50];
    printf("ENTER FIRST NAME OF 10 STUDENTS:\n");
    for(i=0;i<10;i++)
        scanf("%s",sname[i]);

    arrange(sname);

    printf("\n IN ALPHABETICAL ORDER:\n");
    for(i=0;i<10;i++)
    printf("%s\n",sname[i]);
    getch();
}
*/
