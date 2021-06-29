#include <stdio.h>
#include <limits.h>

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

    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;

                counter++;
            }

        }

    }

    print_array(arr, n);
    printf("%i\n", counter);


}
