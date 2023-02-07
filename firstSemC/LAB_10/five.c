/*#include<stdio.h>
#include<conio.h>
#include<string.h>

void reverse(char *w,int l,char *r,int i)
{
  if(w[i]=='\0')
    r[i]='\0';
  else
  {
      r[i]=w[l-1];
  reverse(w,l-1,r,i+1);
  }
}

void main()
{
    char word[20],rev[20];
    int i=0;
    printf("ENTER A WORD:\n");
    gets(word);
    int length=strlen(word);

    reverse(word,length,rev,i);
    printf("THE REVERSE OF THE ABOVE WORD IS %s.",rev);
    getch();
}
*/
