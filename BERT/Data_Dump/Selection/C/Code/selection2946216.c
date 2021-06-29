#include <stdio.h>
#include <stdlib.h>
int selctionSort(int *a, int n);
int main(int argc, char** argv) {
    int number;
    int readScan = scanf("%d", &number);
    int array[number];
    for(int i = 0; i< number; i++)
    {
        int reasScan = scanf("%d", &array[i]);
    }
    int count;
    count = selctionSort(array, number);
    for(int i= 0; i< number; i++)
    {    
        if(i<number-1)
        {
            printf("%d ", array[i]);
        }
        if(i==number-1)
        {
               printf("%d", array[i]);
        }
    }
    printf("\n");
   
    printf("%d\n", count);
    return (EXIT_SUCCESS);
}

int selctionSort(int *a, int n)
{
    int b;
    int count = 0;
    int min ;
    for (int i = 0; i < n-1; i++)
    {   
        min = i;
        for (int j = i+1; j < n; j++)
	{
            if (a[j] < a[min])
            { 
                min = j;
            }   
        }  
        b= a[i];
        a[i]=a[min];
        a[min]=b;
        if(min != i)
        {
            count++;
        }
    }
    return count;
}
