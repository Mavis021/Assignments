/*#include<stdio.h>
#include<conio.h>
#include<string.h>

int calculation(char *s,char *l,int *v,int *c)
{
    int i,j,count=0,ival=0,len=0;
    *v=0; *c=0;
    while(s[j]!='\0')
    {
        while(s[i]!=' '&&s[i]!='\0')
        {
            count++;
            i++;
        }
        if(count>len)
        {
            len =count;
             ival=i-len;
        }
        count=0;
        j=i+1;
        i++;
    }
    for(j=0;j<len;j++)
    {
        l[j]=s[ival];
        ival++;
    }
    l[len]='\0';

    //vowel count
   for(i=0;i<len;i++)
   {
       if(l[i]=='a'||l[i]=='e'||l[i]=='i'||l[i]=='o'||l[i]=='u'||l[i]=='A'||l[i]=='E'||l[i]=='I'||l[i]=='O'||l[i]=='U')
        *v+=1;
       else
        *c+=1;
   }
    return(len);
}

void main()
{
    char sentence[50],longest[20];
    int len, vowel,consonant;
    printf("WRITE A SENTENCE:\n");
    gets(sentence);
    len =calculation(sentence,longest,&vowel,&consonant);

    printf("\n\nTHE LONGEST WORD IN ABOVE SENTENCE IS ' %s ' \nWHICH HAS %d CHARACTERS %d VOWELS AND %d CONSONENTS.",longest,len,vowel,consonant);
    getch();
}
*/
