//lab1_3.c
//A program in c for storing and retriving the names and marks of the students in c programming

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data
{
	char name[30];
	int marks;
};


void main()
{
	struct data *m;
	int n, i=0;
	char prompt;
	
	printf("ENTER THE NUMBER OF STUDENTS YOU WANT TO REGISTER: \n ");
	scanf("%d", &n);

	m = (struct data*)malloc(n * sizeof(struct data)); // allocating the required memory

	for (i = 0; i < n; i++) // storing the datas of students
	{
		printf("STUDENT %d:\nNAME : ", i + 1);
		scanf("%s",(m + i)->name);
		printf("OBTAINED MARKS: ");
		scanf("%d", &(m + i)->marks);
		printf("\n");
	}
	printf("\nENTER 'Y' IF YOU WANT TO LOOK OVER THE STORED DATA: ");
	scanf(" %c", &prompt);

	if ("prompt == 'Y'")
	{
		for ( i = 0; i < n; i++) // retriving the datas of students
		{
			printf("STUDENT %d:\n ", i + 1);
			printf("NAME:%s\n",(m + i)->name);
		
			printf("OBTAINED MARKS : %d",(m + i)->marks);
			printf("\n");
		}
	}
	
	free(m);
}
