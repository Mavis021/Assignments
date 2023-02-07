/*#include<stdio.h>
#include<conio.h>

struct TIME
{
int hour;
int minutes;
int seconds;
};

void calculation(struct TIME t1,struct TIME t2,struct TIME *sum,struct TIME *diff)
{
    struct TIME a1,a2,s1,s2;
    a1=t1; s1=t1;
    a2=t2; s2=t2;
    //subtract
    diff->seconds=s2.seconds-s1.seconds;
    if(diff->seconds<0)
    {
        diff->seconds+=60;
        s2.minutes--;
    }
    diff->minutes=s2.minutes-s1.minutes;
    if(diff->minutes<0)
    {
        diff->minutes+=60;
        s2.hour--;
    }
    diff->hour=s2.hour-s1.hour;
    //add
     sum->seconds=a2.seconds+a1.seconds;
    if(sum->seconds>60)
    {
        sum->seconds-=60;
        a2.minutes++;
    }
    sum->minutes=a2.minutes+a1.minutes;
    if(sum->minutes>60)
    {
        sum->minutes-=60;
        a2.hour++;
    }
    sum->hour=a2.hour+a1.hour;

}

void main()
{
    struct TIME t1,t2,sum ={0,0,0},diff={0,0,0};;
    printf("ENTER START TIME : {hour minute second}\n");
    scanf("%d%d%d",&t1.hour,&t1.minutes,&t1.seconds);
    printf("ENTER END TIME : {hour minute second}\n");
    scanf("%d%d%d",&t2.hour,&t2.minutes,&t2.seconds);

    calculation(t1,t2,&sum,&diff);

    printf("\nDIFFERENCE OF START TIME AND END TIME:\n %d:%d:%d",diff.hour,diff.minutes,diff.seconds);
    printf("\nSUMATION OF START TIME AND END TIME:\n %d:%d:%d",sum.hour,sum.minutes,sum.seconds);

    getch();
}
*/
