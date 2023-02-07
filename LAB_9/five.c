/*#include<stdio.h>
#include<conio.h>
//#include<alloc.h>//header file for memory management functions

void main(void)
{
    int n,i;
    float *address; //pointer variable declaration
    printf("Enter number of elements:");
    scanf("%d",&n);
    address = (float*)calloc(n,sizeof(float));
    //using calloc function to allocate memory for n number of float member
    if(address == NULL)//to check whether the requested memory is allocated or not
    {
        printf("Memory can not be allocated.");
        exit(1);//to exit from the program. if the contents of address is NULL
    }

    for(i=0;i<n;i++)
    {
        printf("\n Address of %d block %d",i,(address+i));
    }
    free(address);//to deallocate memory
}
*/
