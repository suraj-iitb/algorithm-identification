#include <stdio.h>

int main()
{
    int n;
    scanf("%i", &n);  
    int arr[n]; 
    for (int r = 0; r < n; r++)
    {
        scanf("%i", &arr[r]);
        printf("%i", arr[r]);
        if (r != n - 1)
        {
            printf(" ");
        }
    } 

    printf("\n");
    
    for (int j = 1; j < n; j++)
    {
        int key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = key; 

        for (int q = 0; q < n; q++)
        {
            printf("%i", arr[q]);
            if (q != n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");

    }
    
}


