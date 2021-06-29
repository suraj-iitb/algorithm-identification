#include <stdio.h>

void insertion_sort(int *values, size_t n)
{
    for (int *elm = values + 1, *const end = values + n; elm < end; ++elm)
    {
        for (int *p = values, *const pend = p + n; p != pend; ++p)
        {
            printf("%d%c", *p, p == pend - 1 ? '\n' : ' ');
        }
        const int key = *elm;
        int *cmp;
        for (cmp = elm; cmp != values && *(cmp - 1) > key; --cmp)
        {
            *cmp = *(cmp - 1);
        }
        *cmp = key;
    }
}

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    int values[100];
    for (int *elm = values, *const end = elm + n; elm != end; ++elm)
    {
        scanf("%d", elm);
    }
    insertion_sort(values, n);
    for (int *p = values, *const pend = p + n; p != pend; ++p)
    {
        printf("%d%c", *p, p == pend - 1 ? '\n' : ' ');
    }
    return 0;
}

