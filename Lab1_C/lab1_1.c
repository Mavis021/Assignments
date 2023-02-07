//lab1_1.c
//A program in c for finding the average expenditure for each month each year, each year and average over the range of years specified.
//Use arrays to construct a table, display the table of expenditure and find the sum and average.

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct months
{
	int jan;
	int feb;
	int march;
	int april;
	int may;
	int june;
	int july;
	int aug;
	int sept;
	int oct;
	int nov;
	int dec;
};



void main()
{
	struct months* mon;
	int i, j, year_1, year_2, n, t_sum = 0;
	float t_avg = 0;
	char prompt_year[11], start[5], end[5];

	printf("ENTER THE RANGE OF YEARS YOU WANT THE AVERAGE EXPENDITURE OF: 'eg: 2077-2079'\n");
	gets(prompt_year);

	for (i = 0; i < strlen(prompt_year); i++) //seperating the single character input into two year denoting characters
	{
		if (i < 4)
		{
			start[i] = prompt_year[i];
		}
		else if (i > 4)
		{
			end[i - 5] = prompt_year[i];
		}
	}

	year_1 = atoi(start); // converting the string characters into integers
	year_2 = atoi(end);

	n = year_2 - year_1;
	float* average = (float*)malloc(n * sizeof(float));
	int* sum = (int*)malloc(n * sizeof(int));
	mon = (struct months*)malloc(n * sizeof(struct months));  //allocating the required memory

	//Prompting the user to enter the monthly expenditure
	for (i = 0; i <= n; i++)
	{
		printf("\nENTER THE MONTHLY EXPENSES OF YEAR %d AS MENTIONED:\n", year_1 + i);
		printf("JANUARY: ");
		scanf("%d", &(mon + i)->jan);
		printf("FEBRUARY: ");
		scanf("%d", &(mon + i)->feb);
		printf("MARCH: ");
		scanf("%d", &(mon + i)->march);
		printf("APRIL: ");
		scanf("%d", &(mon + i)->april);
		printf("MAY: ");
		scanf("%d", &(mon + i)->may);
		printf("JUNE: ");
		scanf("%d", &(mon + i)->june);
		printf("JULY: ");
		scanf("%d", &(mon + i)->july);
		printf("AUGUST: ");
		scanf("%d", &(mon + i)->aug);
		printf("SEPTMENBER: ");
		scanf("%d", &(mon + i)->sept);
		printf("OCTOBER: ");
		scanf("%d", &(mon + i)->oct);
		printf("NOVEMBER: ");
		scanf("%d", &(mon + i)->nov);
		printf("DECEMBER: ");
		scanf("%d", &(mon + i)->dec);

		sum[i] = ((mon + i)->jan + (mon + i)->feb + (mon + i)->march + (mon + i)->april + (mon + i)->may + (mon + i)->june + (mon + i)->july + (mon + i)->aug + (mon + i)->sept + (mon + i)->oct + (mon + i)->nov + (mon + i)->dec);
		average[i] = (float)sum[i] / 12;
		t_avg += (*(average + i)) / (n + 1);
		t_sum += sum[i];
	}
	//system("cls"); //trying to clear the console

   //printing the table of expenditure

	printf("%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s\n", "YEAR", "JANUARY", "FEBUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER");
	for (i = 0; i <= n; i++)
	{

		printf("%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d%10d\n", year_1 + i, (mon + i)->jan, (mon + i)->feb, (mon + i)->march, (mon + i)->april, (mon + i)->may, (mon + i)->june, (mon + i)->july, (mon + i)->aug, (mon + i)->sept, (mon + i)->oct, (mon + i)->nov, (mon + i)->dec);

	}

	printf("\n TOTAL SUM OF EXPENDITURE FROM %d to %d IS %d \n TOTAL AVERAGE EXPENDITURE FROM %d TO %d is %f", year_1, year_2, t_sum, year_1, year_2, t_avg);

	free(sum);
	free(average);
	free(mon);

}