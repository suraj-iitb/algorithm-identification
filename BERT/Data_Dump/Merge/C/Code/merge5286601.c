#include <stdio.h>

void mergesort(int arr[], int start, int end, int comparison[]);
int merge(int arr[], int start, int end);

int main(void)
{
    // Get input
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int p = 0; p < n; p++)
    {
        int num;
        scanf("%d", &num);
        arr[p] = num;
    }

    int comparison[1];
    comparison[0] = 0;

    // Driver Code
    mergesort(arr, 0, n-1, comparison);

    // Print the results
    for (int r = 0; r < n; r++)
    {
        printf("%d", arr[r]);
        if (r == n-1)
        {
            printf("\n");
        }
        else 
        {
            printf(" ");
        }
    }
    printf("%d\n", comparison[0]);

}

void mergesort(int arr[], int start, int end, int comparison[])
{
    int diff = end - start;

    if (start < end)
    {
        int mid;
        mid = start + ((end - start) / 2);

        mergesort(arr, start, mid, comparison);
        mergesort(arr, mid+1, end, comparison);

        int comps = merge(arr, start, end);
        comparison[0] = comparison[0] + comps;
    }    
    
}

int merge(int arr[], int start, int end)
{
    int comparisons = 0;

    int diff = end - start;
    int mid;
    mid = start + ((end - start) / 2);
 
    int size1 = mid - start + 1;
    int size2 = end - (mid+1) + 1;

    int arr1[size1];
    int arr2[size2];
 

    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[start+i];
    }

    for (int j = 0; j < size2; j++)
    {
        arr2[j] = arr[mid+1+j];
    }
    

 
    int i1, i2, i3;
    i1 = 0; // Iterator for "left" array
    i2 = 0; // Iterator for "right" array
    i3 = start; // Iterator for the "main" array

    while (i1 < size1 && i2 < size2) {
        if (arr1[i1] <= arr2[i2]) 
        {
            arr[i3] = arr1[i1];
            i1++;
            comparisons++;
        }
        else 
        {
            arr[i3] = arr2[i2];
            i2++;
            comparisons++;
        }

        i3++;
    }
 
    while (i1 < size1) 
    {
        arr[i3] = arr1[i1];
        i3++;
        i1++;
        comparisons++;
    }
 
    while (i2 < size2) 
    {
        arr[i3] = arr2[i2];
        i3++;
        i2++;
        comparisons++;
    }

    return comparisons;

}
