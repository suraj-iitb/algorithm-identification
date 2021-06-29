#include <stdio.h>

int S[500000];
int L[500000];
int R[500000];
int cnt = 0;

void merge(int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++)
    {
        L[i] = S[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = S[mid + i];
    }
    L[n1] = 1000000000;
    R[n2] = 1000000000;
    int i = 0;
    int j = 0;

    for (int k = left; k < right; k++)
    {
        cnt++;
        if (L[i] <= R[j])
        {
            S[k] = L[i];
            i++;
        }
        else
        {
            S[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}

int main()
{
    int n,i;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }

for(i=0;i<6;i++){
    i++;
    if(i==5)break;
}

    mergeSort(0, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", S[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n%d\n", cnt);
}

