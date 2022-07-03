
/*#include <stdio.h>
#include <conio.h>

int series(int, int);

void main()
{
    int n, x, ans;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    x = n;
    ans = series(n, x);
    printf("Sum to %d terms = %d", n, ans);
    getch();
}

int series(int n, int x)
{
    if (n == 1){
    if (x % 2 == 0)
        return (-1);
    else
        return (1);
    }
    else
    {
        if (x % 2 == 0)
            return (-n * n - series(n - 1, x));
        else
            return (n * n - series(n - 1, x));
    }
}
*/
/*
#include <stdio.h>
#include <conio.h>

int hcf(int, int, int);

void main()
{
    int a, b, largest, h;
    printf("Enter two numbers whose hcf is to be calculated: ");
    scanf("%d%d", &a, &b);
    largest = (a > b) ? a : b;
    h = hcf(a, b, largest);
    printf("HCF of %d & %d = %d", a, b, h);
    getch();
}

int hcf(int a, int b, int largest)
{
    if (a % largest == 0 && b % largest == 0)
        return (largest);
    else
        hcf(a, b, largest - 1);
}
*/
