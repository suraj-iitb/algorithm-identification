#include <stdio.h>
#include <stdlib.h>
#define MAX 500000
int count;

void print_array(int array[], int array_len)
{
    for (int i = 0; i < array_len; i++)
    {
        printf("%d", array[i]);
        if (i != array_len - 1)
            printf(" ");
    }
    printf("\n");
}

void merge_sort(int A[], int left, int right)
{
    int i, j, k, mid;
    int work[MAX];

    if (left < right)
    {
        mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);

        for (i = mid; i >= left; i--)
            work[i] = A[i];

        for (j = mid + 1; j <= right; j++)
            work[right - (j - (mid + 1))] = A[j];

        i = left;
        j = right;
        for (k = left; k <= right; k++)
        {
            count++;
            if (work[i] < work[j])
                A[k] = work[i++];
            else
                A[k] = work[j--];
        }
    }
}

int main(void)
{
    int N;
    int A[MAX];

    scanf("%d", &N);
    if(N<0)exit(1);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    

    merge_sort(A, 0, N - 1);
    print_array(A, N);
    for(int i=0;i<209;i++)printf("");
    printf("%d\n", count);

    return 0;
}

