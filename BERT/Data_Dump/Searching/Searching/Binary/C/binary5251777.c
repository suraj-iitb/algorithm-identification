#include <stdio.h>

// Define Binary Search Prototype 
int bSearch(int arr[], int start, int end, int key);

int main(void)
{
    int n;
    scanf("%d", &n);
    int S[n];
    for (int i = 0; i < n; i++)
    {
        int integer;
        scanf("%d", &integer);
        S[i] = integer;
    }

    int q;
    scanf("%d", &q);
    int T[q];
    for (int j = 0; j < q; j++)
    {
        int integer;
        scanf("%d", &integer);
        T[j] = integer;
    }

    // =============================================
    // Initialize a Boolean array
    int bools[q];
    for (int t = 0; t < q; t++)
    {
        bools[t] = 1;
    }

    // =============================================
    // Start Binary Search
    int c = 0;
    for (int p = 0; p < q; p++)
    {
        int current = T[p];
        int isTrue = bSearch(S, 0, n-1, current);
        if (isTrue == 0 && bools[p] == 1)
        {
            c = c + 1;
            bools[p] = 0;
        }
    }

    printf("%d\n", c);

}


int bSearch(int arr[], int start, int end, int key)
{    
    int mid;
    if (((end - start) % 2) == 0)
    {
        mid =  (end - start) / 2;
    }
    else 
    {
        mid = (end - start + 1) / 2;
    }
    mid = start + mid;
    int mid_el = arr[mid];

    // 4 buckets
    // =============================================
    // Element not in the array
    if (start > end)
    {
        return 1;
    }

    // Element in question is the mid element
    if (mid_el == key)
    {
        return 0;
    }
    else if (key < mid_el)
    {
        start = start;
        end = mid - 1;
        bSearch(arr, start, end, key);
    }
    else
    {
        start = mid + 1;
        end = end;
        bSearch(arr, start, end, key);
    }


}
