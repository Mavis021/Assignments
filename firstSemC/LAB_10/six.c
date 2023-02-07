#include<stdio.h>
#include<conio.h>

int length(char *s)
{
    int i;
    for(i=0;s[i]!='\0';i++);
    return(i);
}
void cat(char *s1,char *s2)
{
    int i,j;
    for(i=0;s1[i]!='\0';i++);
    for(j=0;s2[j]!='\0';j++)
    {
        s1[i-1]=s2[j];
        i++;
    }
    s1[i]='\0';
}
void copy(char *s1,char *s2)
{
    int i,j=0;
    char b[100];
    for(i=0;s2[i]!='\0';i++)
    {
        s1[i]=s2[i];
    }
    s1[i]='\0';
}

int compare(char *s1, char *s2)
{
    int i;
    for(i=0;s1[i]!='\0'||s2[i]!='\0';i++)
    {
        if(s1[i]<s2[i])
           {
               return(-1);
           break;
           }
        if(s1[i]==s2[i])
            {
                continue;
                return(0);
            }
        if(s2[i]<s1[i])
        {
            return(+1);
            break;
        }
        }
}

void main()
{
    int c;
    char sen1[100],sen2[50];
    printf("ENTER FIRST SENTENCE:\n");
    gets(sen1);
    printf("ENTER SECOND SENTENCE:\n");
    gets(sen2);


    //int len=length(sen);
    //printf("\nTHE LENGTH OF THE ENTERED STRING IS %d.",len);

   // cat(sen1,sen2);
    //printf("\n THE CONCATINATED SENTENCE IS: \n %s",sen1);

    //copy(sen1,sen2);
    //printf("\n AFTER COPYING: FIRST SENTENCE IS: \n %s",sen1);

     c=compare(sen1,sen2);
    if(c==1)
        printf("\nTHE SECOND STRING PRECEEDS THE FIRST STRING ALPHABETICALLY.");
    else if(c==0)
        printf("\n BOTH THE STRINGS ARE IDENTICAL");
    else
         printf("\nTHE FIRST STRING PRECEEDS SECOND STRING ALPHABETICALLY.");


    getch();
}


