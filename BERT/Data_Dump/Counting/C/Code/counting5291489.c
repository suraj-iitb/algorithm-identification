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

    // given in the question
    int k = 10000;
    int C[k];

    for (int i = 0; i < k; i++)
    {
        C[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        C[arr[i]] = C[arr[i]] + 1;
    }

    for (int i = 1; i < k; i++)
    {
        C[i] = C[i] + C[i - 1];
    }

    int B[n];

    for (int i = n - 1; 0 <= i; i = i - 1)
    {
        B[C[arr[i]] - 1] = arr[i];
        C[arr[i]] = C[arr[i]] - 1;
    }

    print_array(B, n);

}
