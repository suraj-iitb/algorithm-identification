#include<stdio.h>
#include<stdlib.h>
#define MAX 10000
void csort(int, int*);
main()
{
        int i, n, *table;
        scanf("%d", &n);
        table = (int*)malloc(sizeof(int) * n);
        for (i= 0; i < n; i++) {
                scanf("%d", &table[i]);
        }
        csort(n, table);
        for (i= 0; i < n - 1; i++) {
        printf("%d ", table[i]);
    }
        printf("%d\n", table[i]);
        free(table);
}
void csort(int n, int *table)
{
        int i, work[n], count[MAX + 1] = {0};
        for (i = 0; i < n; i++) {
                int key = table[i];
                count[key]++;
        }
        for (i = 0; i < MAX; i++) {
        count[i + 1] += count[i];
    }
        for (i = 0; i < n; i++) {
        int key = table[i];
                work[--count[key]] = key;
    }
        for (i = 0; i < n; i++) {
        table[i] = work[i];
    }
}
