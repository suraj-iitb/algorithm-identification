#include <stdio.h>
#include <stdlib.h>

int binarySearch(int num, int *array, int left, int right)
{
    int mid = (left + right) / 2;

    if(num == array[mid])
        return 1;
    if(left > right)
        return 0;
    if(num < array[mid]) {
        binarySearch(num, array, left, mid - 1);
    } else {
        binarySearch(num, array, mid + 1, right);
    }
}

int main(void)
{
    int i, n, s, q, t, cnt = 0;
    int *s_array;

    scanf("%d", &n);
    s_array = malloc(sizeof(int) * n);
    for(i = 0; i < n; i++) {
        scanf("%d", &s);
        s_array[i] = s;
    }
    scanf("%d", &q);
    for(i = 0; i < q; i++) {
        scanf("%d", &t);
        cnt += binarySearch(t, s_array, 0, n - 1);
    }
    printf("%d\n", cnt);

    return 0;
}
