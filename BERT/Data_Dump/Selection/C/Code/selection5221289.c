#include <stdio.h>

int main()
{

    int i, j, n;
    int arr[100];
    int count = 0;
    int temp, minIndex;

    //reading inputs
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &arr[i]);
    }

    //Selection Sort
    for (i = 0; i < n; i++)
    {
        minIndex = i;
        for (j = i; j < n; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }     
        }
        //Swap if the value of arr[i] is not equal to arr[minIndex]
        if (arr[i] != arr[minIndex]){
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            count++;
        }
    }

    /*Printing */
    for (i = 0; i < n; i++)
    {
        if (i >= 1)
            printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    printf("%d\n", count);
    return 0;
}
