#include <stdio.h>
int bubble_sort(int n, int arr[])
{
    int flag = 1, sorted_index = 0, inverse = 0, cache;
    while (flag)
    {
        flag = 0;
        for (int i = n-1; i > sorted_index; i--)
        {
            if (arr[i] < arr[i-1])
            {
                cache = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = cache;
                inverse++;
                flag = 1;
            }
        }
        sorted_index++;
    }
    return inverse;
}
int main(void)
{
    int n, inverse;
    int arr[105];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    inverse = bubble_sort(n, arr);
    for (int i = 0; i < n-1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[n-1]);
    printf("%d\n", inverse);
    return 0;
}
