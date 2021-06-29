#include <stdio.h>

#define N 500000
#define INFTY 1000000000

int cnt = 0;

void merge(int A[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1], R[n2];
    L[n1] = INFTY;
    R[n2] = INFTY ;

    for (i = 0; i < n1; i++) L[i] = A[left + i];
    for (i = 0; i < n2; i++) R[i] = A[mid + i];

    i = 0;
    j = 0;

    for (k = left; k < right; k++)
    {
        if (L[i] <= R[j])
        {
          A[k] = L[i];
          cnt++;
          i=i+1;
        }
        else
        {
          A[k] = R[j];
          cnt++;
          j=j+1;
        }
    }
}

void mergeSort(int A[], int left, int right)
{
    if (left+1 < right)
    {
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    int n,i,A[N];

    scanf("%d",&n);
    for(i = 0; i < n; i++) scanf("%d",&A[i]);
    mergeSort(A, 0, n);
    for (i = 0; i < n; i++)
    {
      printf("%d", A[i]);
      if(i<n-1) printf(" ");
    }
    printf("\n");
    printf("%d\n",cnt);

    return 0;
}
