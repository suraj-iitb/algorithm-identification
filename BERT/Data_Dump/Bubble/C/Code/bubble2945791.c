#include <stdio.h>
#include <stdlib.h>
int bubbleSort(int *a, int n);
int main(int argc, char** argv) {
    int number;
    int readScan = scanf("%d", &number);
    int array[number];
    for(int i = 0; i< number; i++)
    {
        int reasScan = scanf("%d", &array[i]);
    }
    int count;
    count = bubbleSort(array, number);
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

int bubbleSort(int *a, int n)
{
    int b;
    int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (a[j]>a[j+1])
			{
                            b = a[j];
                            a[j] = a[j+1];
                            a[j+1] =b;
                            count++;
			}
                      
		}
	}
    return count;
}
