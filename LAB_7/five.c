/*#include<stdio.h>
#include<conio.h>

void add(int a, int b)
{
    int sum;
    sum= a+b;
  printf("\n%d + %d = %d",a,b,sum);
}

int fact(unsigned int a)
{
    if(a==0)
        return(1);
    else
        return(a*fact(a-1));
}

void check_prime( int i)
{
      if(i%2!=0 && i%3!=0 && i%5!=0 && i%7!=0 && i>=3 || i==2 || i==3 || i==5 || i==7)
        {
            printf(" %d IS A PRIME NUMBER.\n",i);
        }
        else
            printf("%d IS NOT A PRIME NUMBER.\n",i);
}

void main()
{
    int a, b, x;
    printf("ENTER ANY TWO NUMBERS:\n");
    scanf("%d%d",&a,&b);
    printf("\nENTER '1' TO ADD THE NUMBERS:\n");
    printf("ENTER '2' TO FIND THE FACTORIAL OF THE NUMBERS:\n");
    printf("ENTER '3' TO CHECK WEATHER THE NUMBERS ARE PRIME OR NOT:\n :");
    scanf("%d",&x);

    switch(x)
    {
    case 1 :
        add(a,b);
        break;

    case 2 :
        printf("\nTHE FACTORIAL OF %d IS %d\n",a,  fact(a));
        printf("THE FACTORIAL OF %d IS %d",b, fact(b));
        break;

    case 3:
        check_prime(a);
        check_prime(b);
        break;

        default:
        printf("PLEASE ENTER THE SPECIFIED NUMBER");
        break;

    }
    getch();
}
*/
