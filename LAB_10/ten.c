/*#include<stdio.h>
#include<conio.h>
#include<string.h>

void conversion(char *s)
{
    int l=strlen(s),i;
    for(i=0;i<l;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
           s[i]=s[i]+32;
        else if(s[i]>='a'&&s[i]<='z')
            s[i]=s[i]-32;
    }

}

void main()
{
    char str[100];
    printf("ENTER A STRING:\n");
    gets(str);

    conversion(str);
    printf("\n AFTER CONVERSION: \n %s",str);

    getch();
}
*/
