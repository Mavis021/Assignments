/*#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
    char sen[100],ch[50];
    int count[50],i,j,k=0,test;

    printf("ENTER A STIRNG:\n");
    gets(sen);

    int length = strlen(sen);
    for(i=0;i<length;i++)
    {
        if((sen[i]>='A'&&sen[i]<='Z')||(sen[i]>='a'&&sen[i]<='z'))
        {test = 1;
        for(j=0;j<strlen(sen);j++)
            if(sen[i]==ch[j])
              test =0;

         if(test==1)
         {
             ch[k]=sen[i];
             k++;
         }
        }
    }
    ch[k]='\0';
    for(i=0;ch[i]!='\0';i++)
    {
        count[i]=0;
        for(j=0;sen[j]!='\0';j++)
        {
        if(sen[j]==ch[i])
          count[i]+=1;
        }
    }

printf("\nCHARACTERS \t FREQUENCY\n");
    for(i=0;ch[i]!='\0';i++)
    printf(" %c \t\t %d\n",ch[i],count[i]);

        getch();
}
*/
