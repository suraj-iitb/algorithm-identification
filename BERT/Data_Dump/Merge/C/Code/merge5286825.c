#include <stdio.h>
#include <limits.h>

int COMPARISONS = 0;

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

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    int L[n1 + 1];
    int R[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i]; 
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[mid + i];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0;

    for (int s = left; s < right; s++)
    {
        if (L[i] <= R[j])
        {
            arr[s] = L[i];
            i++;
            COMPARISONS++;
        }
        else
        {
            arr[s] = R[j];
            j++;
            COMPARISONS++;
        }
        
    }

}

void merge_sort(int arr[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid, right);
        merge(arr, left, mid, right);
    }
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

    merge_sort(arr, 0, n);
    print_array(arr, n);
    printf("%i\n", COMPARISONS);

}
