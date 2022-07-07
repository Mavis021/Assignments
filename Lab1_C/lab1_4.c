//lab1_4.c
//A program in c  to read name, rollno, address, and phone number of each student in your class using structure.
//Store the information in file so that you can recover the information later. While recovering the information from the file sort the information alphabetically according to the name

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct student
{
    int roll_no;
    char name[20];
    char address[20];
    char phone[20];
};

void main()
{
    FILE* fp;
    struct student* s, * read, temp;
    int i = 0, n, j = 0;
    char prompt[5];

    printf("ENTER THE NUMBER OF STUDENTS YOU WANT TO REGISTER :\n");
    scanf("%d", &n);

    s = (struct student*)malloc(n * sizeof(struct student));

    read = (struct student*)malloc(n * sizeof(struct student));

    fp = fopen("STUDENTSINFO.dat", "wb+");
    if (fp == NULL)
    {
        printf("ERROR IN CREATING THE FILE");
        exit(1);
    }

    printf("\t\t\t STUDENT'S INFORMATION:\n");
    for (i = 0; i < n; i++)
    {
        printf("NAME:\t");
        scanf(" %[^\n]", (s + i)->name);
        printf("ROLL NO. :\t");
        scanf("%d", &(s + i)->roll_no);
        printf("ADDRESS:\t");
        scanf(" %[^\n]", (s + i)->address);
        printf("PHONE NO:\t");
        scanf(" %[^\n]", (s + i)->phone);
        fwrite((s + i), sizeof(struct student), 1, fp);
    }

    fclose(fp);



    fp = fopen("STUDENTSINFO.dat", "rb");
    if (fp == NULL)
    {
        printf("ERROR IN OPENING THE FILE");
        exit(1);
    }

    printf("\nRECORD OF STUDENT IN STUDENTSINFO.dat:\n");

    for (i = 0; i < n; i++)
    {
        fread(read + i, sizeof(struct student), 1, fp);
    }



    //arrange in ascending order
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n - i; j++)
        {
            if (strcmp((read + i)->name, (read + j)->name) > 0)
            {
                temp = read[i];
                read[i] = read[j];
                read[j] = temp;

            }
        }
    }



    for (i = 0; i < n; i++)
    {
        printf("\nNAME:\t %s", (read + i)->name);
        printf("\nROLL NO. :\t %d", (read + i)->roll_no);
        printf("\nADDRESS:\t %s", (read + i)->address);
        printf("\nPHONE NO:\t %s", (read + i)->phone);
        printf("\n");
    }

    fclose(fp);
    free(s);
    free(read);
}
