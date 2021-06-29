#include <cstdio>
#define LARGE_VALUE 2000000000
int S[500005];
int left_sub_S[250005], right_sub_S[250005];
int count = 0;
void merge(int left, int right, int mid)
{
    int n_1 = mid - left, n_2 = right - mid;
    for (int i = 0; i < n_1; i++)
        left_sub_S[i] = S[left + i];
    left_sub_S[n_1] = LARGE_VALUE;
    for (int i = 0; i < n_2; i++)
        right_sub_S[i] = S[mid + i];
    right_sub_S[n_2] = LARGE_VALUE;
    int j = 0, k = 0;
    for (int i = 0; i < n_1 + n_2; i++)
    {
        count++;
        if (left_sub_S[j] >= right_sub_S[k])
        {
            S[left + i] = right_sub_S[k];
            k++;
        }
        else
        {
            S[left + i] = left_sub_S[j];
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
        merge(left, right, mid);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
    }
    mergeSort(0, n);
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", S[i]);
    }
    printf("%d\n", S[n - 1]);
    printf("%d\n", count);
    return 0;
}
