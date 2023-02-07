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
};

void main()
{
    FILE *fp;
    struct student s[max],read;
    int i=0;
    char prompt[5];

    fp = fopen("D:\\C-PROG\\STUDENTSINFO.txt","w+");
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

 fwrite(&s[i],sizeof(struct student),1,fp);
        printf("\n DO YOU WANT TO ADD ANOTHER RECORD?\n [yes/no]:\t");
        scanf("%s",prompt);
        if(strcmp(prompt,"no")==0)
            break;
    }

    fclose(fp);

    fp = fopen("D:\\C-PROG\\STUDENTSINFO.txt","r");
    if(fp==NULL)
    {
        printf("ERROR IN OPENING THE FILE");
        exit(1);
    }

    printf("\nRECORD OF STUDENT IN STUDENTSINFO.txt:\n");

    i=0;
    while(fread(&read,sizeof(struct student),1,fp))
    {
         printf("\nSTUDENT %d:\n",i+1);
        printf("ROLL NO. :\t %d",read.roll_no);
        printf("\nNAME:\t %s",read.name);
        printf("\nADDRESS:\t %s",read.address);
        printf("\nPHONE NO:\t %s",read.phone);
        printf("\n");
         i++;
    }

    fclose(fp);
    getch();
}
*/
