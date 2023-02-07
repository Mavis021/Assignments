/*#include<stdio.h>
#include<conio.h>
int count(int);
int main()
{
    int n1,n2,i,x,back_x, rem,c,j=0,k=0;

    printf("ENTER THE LOWER LIMIT:\n");
    scanf("%d",&n1);

    printf("ENTER THE UPPER LIMIT:\n");
    scanf("%d",&n2);

    printf("THE PRIME NUMBERS BETWEEN %d AND %d are:\n",n1,n2);




    for(i=n1;i<=n2;i++)

    {

        if(i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0 && i>=3 || i==2 || i==3 || i==5 || i==7)
        {   j++;
            printf(" %d\t [COUNT=%d]\n",i,j);

            }
    }

    printf("\nTHE PALINDROME NUMBERS BETWEEN %d AND %d ARE:\n",n1,n2);
    for(i=n1;i<=n2;i++)
    {
        x=i;
        back_x=0;
        while(x)
        {
            rem = x%10;
             x=x/10;
            back_x= back_x*10+rem;
        }
        if(i==back_x)
        {
              k++;
            printf(" %d\t [COUNT = %d]\n",i,k);
    }
    }

    return 0;
}

*/
