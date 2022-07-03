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
    struct student s[max],read,r1;
    int i=0;
    char prompt[5],c;

    fp = fopen("D:\\C-PROG\\FIRSTBINARY.dat","wb+");
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

 fwrite(&s[i],sizeof(struct student),1,fp);
        printf("\n DO YOU WANT TO ADD ANOTHER RECORD?\n [yes/no]:\t");
        scanf("%s",prompt);
        if(strcmp(prompt,"no")==0)
            break;
    }

    fclose(fp);

     fp = fopen("D:\\C-PROG\\FIRSTBINARY.dat","rb");
    if(fp==NULL)
    {
        printf("ERROR IN OPENING THE FILE");
        exit(1);
    }

    fp1 = fopen("D:\\C-PROG\\SECONDBINARY.dat","wb");
    if(fp1==NULL)
    {
        printf("ERROR IN OPENING THE FILE");
        exit(1);
    }

    //coping to second.txt
    while(fread(&r1,sizeof(struct student),1,fp))
    {
        fwrite(&r1,sizeof(struct student),1,fp1);
    }


    printf("\n FIRST COPIED TO SECONDBINARY:\n");

    fclose(fp);
    fclose(fp1);

     fp1 = fopen("D:\\C-PROG\\SECONDBINARY.dat","rb");
    if(fp1==NULL)
    {
        printf("ERROR IN OPENING THE FILE");
        exit(1);
    }

    printf("\nRECORD OF STUDENT IN SECONDBINARY:\n");


    //printing from second.txt
    i=0;
     while(fread(&read,sizeof(struct student),1,fp1))
    {
       printf("\nSTUDENT %d:\n",i+1);
        printf("ROLL NO. :\t %d",read.roll_no);
        printf("\nNAME:\t %s",read.name);
        printf("\nADDRESS:\t %s",read.address);
        printf("\nPHONE NO:\t %s",read.phone);
        printf("\nSCORE:\t %.2f",read.score);
        printf("\n");
         i++;
       }
    fclose(fp1);
    getch();
}
*/
