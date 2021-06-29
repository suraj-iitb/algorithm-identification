#include <stdio.h>

void swap(int arr[], int index1, int index2);

int main()
{
    int n;
    scanf("%i", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);        
    }

    int counter = 0;

    for (int j = 0; j < n; j++)
    {
        int min = j;
        for (int k = j; k < n; k++)
        {
            if (arr[k] < arr[min])
            {
                min = k;
            }
        }
        
        if (j != min)
        {
            swap(arr, j, min);
            counter = counter + 1;
        }

    }

    for (int p = 0; p < n; p++)
    {
        printf("%i", arr[p]);
        if (p != n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
    printf("%i\n", counter);

}

void swap(int arr[], int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
