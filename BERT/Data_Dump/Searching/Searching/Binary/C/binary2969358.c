

#include <stdio.h>
#include <stdlib.h>
int binarySearch(int sorted_list[], int number, int element);
int main(int argc, char** argv) {
    int number1,number2;
    int readScan = scanf("%d", &number1);
    int array1[number1];
    for(int i=0;i<number1;i++)
    {
        int readScan = scanf("%d", &array1[i]);
    }
    int readScan1 = scanf("%d", &number2);
    int array2[number2];
    for(int i=0;i<number2;i++)
    {
        int readScan = scanf("%d", &array2[i]);
    }
    int key;
    int count=0; 
    int left,right,mid;
    left=0;
    right = number1-1;
    for(int i=0;i<number2;i++)
    {
        if(binarySearch(array1, number1,array2[i]) != NULL)
            count++;
    }
    printf("%d\n", count);
    return(0);
}
int binarySearch(int sorted_list[], int number, int element)
{
    int low, high;
    low = 0;
    high = number-1;
    int middle;
    while (low <= high)
    {
        middle = low + (high - low)/2;
        if (element > sorted_list[middle])
            low = middle + 1;
        else if (element < sorted_list[middle])
            high = middle - 1;
        else
            return middle;
    }
    return NULL;
}


