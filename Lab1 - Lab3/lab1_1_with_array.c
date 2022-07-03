//lab1_1.c
//A program in c for finding the average expenditure for each month each year, each year and average over the range of years specified.
//Use arrays to construct a table, display the table of expenditure and find the sum and average.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i, j=0, year_1, year_2, n, t_sum = 0;
	float t_avg = 0;
	char prompt_year[11], start[5], end[5],months_name[][13] = {"YEAR", "JANUARY","FEBUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};

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
	float* average = (float*)malloc(n * sizeof(float)); //allocating the required memories
	int* sum = (int*)malloc(n * sizeof(int));
	int* months = (int*)malloc(n * 12 * sizeof(int));

	//Prompting the user to enter the monthly expenditure
	for (i = 0; i <= n; i++)
	{
		sum[i] = 0;
		average[i] = 0;
		printf("\nENTER THE MONTHLY EXPENSES OF YEAR %d AS MENTIONED:\n", year_1 + i);
		
		for (j = 0; j < 12; j++)
		{
			printf("%s: ",months_name[j+1]);
			scanf(" %d", (months+i*12+j));

			sum[i] += *(months+i*12 + j);
			average[i] += (float)sum[i]/ 12;
		}
		t_sum += sum[i];
		t_avg += (float)sum[i] / ((n + 1)*12);
	}
	//system("cls"); //trying to clear the console

   //printing the table of expenditure
	for (i = 0; i < 13; i++)
	{
		printf("%-17s", months_name[i]);
	}
	printf("%-17s%-17s", "SUM", "AVERAGE");

	for (j = 0; j <=n; j++)
	{
		printf("\n");
		printf("%-17d", year_1 + j);

		for (i = 0; i < 12; i++)
		{
			printf("%-17d", *(months + j * 12 + i));

		}
		printf("%-17d%-17.2f", sum[j], average[j]);
	}

	printf("\n TOTAL SUM OF EXPENDITURE FROM %d to %d IS %d \n TOTAL AVERAGE EXPENDITURE FROM %d TO %d is %0.3f", year_1, year_2, t_sum, year_1, year_2, t_avg);

	free(sum);
	free(average);


	free(months);
	return(0);
}