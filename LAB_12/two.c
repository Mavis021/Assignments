/*#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
    char *str,words[10][20],prompt[5];
    int i,j,k,test,n;

    str =words;
    FILE *fp;

    fp =fopen("D:\\C-PROG\\no_vowels.txt","w+");
    if(fp == NULL)
    {
        printf("ERROR IN OPENING THE FILE.");
        exit(1);
    }

    i=0;
    while(1)
    {
    printf("ENTER A WORD:\n");
    scanf(" %s",words[i]);
    i++;
    printf("DO YOU WANT TO ADD ANOTHER WORD? [YES/NO] : ");
    scanf(" %s",prompt);
    if(strcmp(prompt,"NO")==0)
        break;
        }

    //writing in file
    for(j=0;j<i;j++)
    {
        test=0;
        for(k=0;k<strlen(words[j]);k++)
    {
        char compare = words[j][k];
         if(compare=='a'||
            compare=='e'||
            compare=='i'||
            compare=='o'||
            compare=='u'||
            compare=='A'||
            compare=='E'||
            compare=='I'||
            compare=='O'||
            compare=='U')
            test=1;
    }
    if(test==0)
        fprintf(fp," %s ",words[j]);
    }

     fclose(fp);

    fp = fopen("D:\\C-PROG\\no_vowels.txt","r");

     if(fp == NULL)
    {
        printf("ERROR IN OPENING THE FILE.");
        exit(1);
    }

    printf("\n\n THE DATA FROM THE FILE:\n");

    fgets(str,100,fp);
    puts(str);
    fclose(fp);


    getch();
}
*/
