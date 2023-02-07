/*#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
	float a, b, c, x1, x2, d, q, w;
	printf(" Enter the coefficients of quadratic equation a, b, c");
	scanf("%f%f%f", &a, &b, &c);
	d = b * b - 4 * a * c;
	if (a!=0)
    {

	if (d == 0)
	{
		printf(" The real and equal roots are x1=%f and x2=%f", -b / (2 * a), -b / (2 * a));
	}
	else if (d > 0)
	{
		x1 = (-b + sqrt(d)) / (2 * a);
		x2 = (-b - sqrt(d)) / (2 * a);
		printf(" The real and unequal roots are: x1=%f and x2=%f", x1, x2);
	}

	else
	{
		d *= -1;
			q = (-b / (2 * a));
			w = (sqrt(d) / (2 * a));
			printf("The imaginary roots are: x1=%f+%fi and x2=%f-%fi", q, w, q, w);
	}
    }
    else
    {
        printf("ERROR :The value of 'a' should not be equal to 0. ");
    }

	getch();
}*/
