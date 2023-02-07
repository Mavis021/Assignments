#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
void main()
{
    int i,n,count=0,sum=0,average;
    char prompt[5];

    for(i=0;i<100;i++)
    {
        printf("ENTER NUMBER:");
        scanf("%d",&n);
        if(n%9==0&&n%6!=0&&(1<n<100))
        {
            count++;
            sum+=n;
        }
        else
            count=1;

        printf("\nDO YOU WISH TO CONTINUE?\n {yes/no}:\t");
        scanf("%s",prompt);
        if(strcmp(prompt,"no")==0)
            break;
    }
    average= sum/count;
    if(average==0)
   printf("NONE OF THE ENTERED DATA WAS DIVISIBLE BY 9.");
       else
    printf("THE AVERAGE OF THE NUMBERS DIVISIBLE BY 9 BUT NOT BY 6 IS %d",average);



    getch();
}

