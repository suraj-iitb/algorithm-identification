#include <stdio.h>
#include <stdlib.h>

int s[200000];

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int n;
    int q;
    int cnt;
    int i, j;

    scanf("%d", &n);
    for (i = 0; i < n; ++i){
        scanf("%d", s + i);
    }

    scanf("%d", &q);
    cnt = 0;
    for (i = 0; i < q; ++i){
        int t;

        scanf("%d", &t);
        if (bsearch(&t, s, n, sizeof(int), compare) != NULL){
            ++cnt;
        }
    }

    printf("%d\n", cnt);

    return (0);
}
