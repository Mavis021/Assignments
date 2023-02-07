/*#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define max 50
struct student
{
    int roll_no;
    char name[20];
    char address[20];
    char phone[20];
    float score;
};

void main()
{
    FILE *fp,*fp1;
    struct student s[max];
    int i=0;
    char prompt[5],c;

    fp = fopen("D:\\C-PROG\\FIRST.txt","w+");
    if(fp==NULL)
    {
        printf("ERROR IN OPENING THE FILE");
        exit(1);
    }

    printf("\t\t\t STUDENT'S INFORMATION:\n");
    for(i=0;i<max;i++)
    {
        printf("\nSTUDENT %d:\n",i+1);
        printf("ROLL NO. :\t");
        scanf("%d",&s[i].roll_no);
        printf("NAME:\t");
        scanf(" %[^\n]",s[i].name);
        printf("ADDRESS:\t");
        scanf(" %[^\n]",s[i].address);
        printf("PHONE NO:\t");
        scanf(" %[^\n]",s[i].phone);
        printf(" SCORE:\t");
        scanf("%f",&s[i].score);

 fprintf(fp,"ROLL NO: %d\nSTUDENT's NAME: %s\nADDRESS: %s\nPHONE NO.: %s\nSCORE:%.2f\n",s[i].roll_no,s[i].name,s[i].address,s[i].phone,s[i].score);
        printf("\n DO YOU WANT TO ADD ANOTHER RECORD?\n [yes/no]:\t");
        scanf("%s",prompt);
        if(strcmp(prompt,"no")==0)
            break;
    }

    fclose(fp);

     fp = fopen("D:\\C-PROG\\FIRST.txt","r");
    if(fp==NULL)
    {
        printf("ERROR IN OPENING THE FILE");
        exit(1);
    }

    fp1 = fopen("D:\\C-PROG\\SECOND.txt","w");
    if(fp1==NULL)
    {
        printf("ERROR IN OPENING THE FILE");
        exit(1);
    }

    //coping to second.txt
    c=fgetc(fp);
    while(c!=EOF)
    {
        fputc(c,fp1);
        c=fgetc(fp);
    }

    printf("\n FIRST.txt COPIED TO SECOND.txt:\n");

    fclose(fp);
    fclose(fp1);

     fp1 = fopen("D:\\C-PROG\\SECOND.txt","r");
    if(fp1==NULL)
    {
        printf("ERROR IN OPENING THE FILE");
        exit(1);
    }

    printf("\nRECORD OF STUDENT IN SECOND.txt:\n");


    //printing from second.txt
     while(1)
    {
        c = getc(fp1);//reading the characters of file and then assigning it to the character c
       if(c == EOF)
        break;

       else
        putchar(c);//printf("%c",c) orr fprintf(stdout,"%c",c) orr fputc(c,stdout)
    }
    fclose(fp1);
    getch();
}
*/
