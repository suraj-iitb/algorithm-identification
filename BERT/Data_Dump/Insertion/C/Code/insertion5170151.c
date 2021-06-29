#include <stdio.h>

void print_array (int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            printf("%i ", arr[i]);
        }
        else
        {
            printf("%i", arr[i]);
        }
              
    }

    printf("\n");

}

int main (void)
{
    int n;
    scanf("%i", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%i", &arr[i]);
    }

    print_array(arr, n);

    for (int i = 1; i < n; i++)
    {
        int unsorted_first = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > unsorted_first)
        {
            arr[j + 1] = arr[j]; 
            j = j - 1;
        }

        arr[j + 1] = unsorted_first;

        print_array(arr, n);

    }
    
}

