/*#include<stdio.h>
#include<conio.h>

int count_even(int );
int count_odd(int );

void main()
{
    int num,evnum,odnum;
    printf("ENTER A POSITIVE INTEGER:");
    scanf("%d",&num);

    evnum= count_even(num);
    printf("NUMBER OF EVEN DIGITS:",evnum);

    odnum= count_odd(num);
    printf("NUMBER OF ODD DIGITS:",odnum);

    getch();
}
int count_even(int n1)
{ int rem,ev=0;
    while(n1>0)
    {
    rem=n1%10;
    if(rem%2==0)
    {
     ev= ev++;
    }
    return(ev);
}}
int count_odd(int n2)
{
    int rem,od=0;
    while(n2>0)
    {
    rem=n2%10;
    if(rem%2==1)
    {
    od= od++;
    }}
    return(od);
}

*/
/*#include<stdio.h>
#include<conio.h>

int add(int ,int );
int main()
{
    int m=20,n=30,sum;
    sum= add(m,n);
    printf("sum=%d",sum);

    return 0;
}
int add(int a, int b)
{
    int add;
    add=a+b;
    return(add);
}
*/

/*#include<stdio.h>
#include<conio.h>
float add(float,float);
float sub(float,float);
float mul(float,float);
float div(float,float);
void main()
{
    float a, b, sum,diff,prod,divi;
    char ch;
    printf("operator:");
    scanf(" %c",&ch);
    printf("two operands:");
    scanf("%f%f",&a,&b);

    switch(ch)
    {
        case'+':
        sum=add(a,b);
        printf("sum = %f",sum);
        break;

        case'-':
        diff= sub(a,b);
        printf("difference = %f",diff);
        break;

        case'*':
        prod= mul(a,b);
        printf("product = %f",prod);
        break;

        case'/':
        divi=div(a,b);
        printf("division = %f",divi);
        break;

        default:
        printf("Enter a valid operator");
        break;
    }
    getch();
}
*/





