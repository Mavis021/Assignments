//lab1_2.c
// A program in c to determine the position of an alphabet in the given sentences

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i;
	char string[] = "idea without execution is worthless";
		for(i = 0; i < strlen(string); i++)
		{
			if (*(string + i) == 'c')
			{
				printf("\n THE CHARACTER 'C' IS IN POSITION: %d", i + 1);
			}
		}

		return(0);
}