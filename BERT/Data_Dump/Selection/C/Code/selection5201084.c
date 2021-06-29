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

    int index, counter = 0;

    for (int i = 0; i < n; i++)
    {
        int index = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }

        }

        if (index != i)
        {

            int tmp = arr[i];
            arr[i] = arr[index];
            arr[index] = tmp;

            counter++;

        }

        

    }

    print_array(arr, n);
    printf("%i\n", counter);


}
