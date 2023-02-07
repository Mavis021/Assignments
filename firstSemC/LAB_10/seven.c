/*#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
    int i,j;
    char sen[50],ch;
    printf("ENTER A STRING:\n");
    gets(sen);
    int length = strlen(sen);

    for(i=0;i<length;i++)
    {
        for(j=i;j<length;j++)
        {
          if((sen[i]>='A'&&sen[i]<='Z')||(sen[i]>='a'&&sen[i]<='z'))
           { if(sen[i]>sen[j])
            {
               ch=sen[i];
               sen[i]=sen[j];
               sen[j]=ch;
            }
           }
        }
    }
    sen[length]='\0';
    printf("\nALPHABETICAL ARRANGEMENT OF ABOVE STRING:\n %s",sen);

    getch();
}

*/
