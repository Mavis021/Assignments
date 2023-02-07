/*#include<stdio.h>
#include<conio.h>

struct MEMORY
{
int kilobytes;
int bytes;
int bits;
};
void calculation(struct MEMORY t1,struct MEMORY t2,struct MEMORY *sum,struct MEMORY *diff)
{
    struct MEMORY a1,a2,s1,s2;
    a1=t1; s1=t1;
    a2=t2; s2=t2;
    //subtract
    diff->bits=s2.bits-s1.bits;
    if(diff->bits<0)
    {
        diff->bits+=8;
        s2.bytes--;
    }
    diff->bytes=s2.bytes-s1.bytes;
    if(diff->bytes<0)
    {
        diff->bytes+=1024;
        s2.kilobytes--;
    }
    diff->kilobytes=s2.kilobytes-s1.kilobytes;
    //add
     sum->bits=a2.bits+a1.bits;
    if(sum->bits>8)
    {
        sum->bits-=8;
        a2.bits++;
    }
    sum->bytes=a2.bytes+a1.bytes;
    if(sum->bytes>1024)
    {
        sum->bytes-=1024;
        a2.kilobytes++;
    }
    sum->kilobytes=a2.kilobytes+a1.kilobytes;

}

void main()
{
    struct MEMORY m1,m2,sum ={0,0,0},diff={0,0,0};;
    printf("ENTER FIRST MEMORY SPACE: {kilobytes: bytes: bits}\n");
    scanf("%d%d%d",&m1.kilobytes,&m1.bytes,&m1.bits);
    printf("ENTER SECOND MEMORY SPACE: {kilobytes: bytes: bits}\n");
    scanf("%d%d%d",&m2.kilobytes,&m2.bytes,&m2.bits);

    if(m2.kilobytes>m1.kilobytes)
    calculation(m1,m2,&sum,&diff);
    else
     calculation(m2,m1,&sum,&diff);

    printf("\nDIFFERENCE OF THE MEMORY SPACES:\n %dKB:%dB:%dBits",diff.kilobytes,diff.bytes,diff.bits);
    printf("\nSUMATION OF THE MEMORY SPACES:\n %dKB:%dB:%dBits",sum.kilobytes,sum.bytes,sum.bits);

    getch();
}
*/
