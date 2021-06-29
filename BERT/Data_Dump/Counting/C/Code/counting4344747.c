#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

bool _countingSort(int *array, int n, int max) {
    int *cnt = malloc((max + 1) * sizeof(int));
    int *buff = malloc(n * sizeof(int));

    if(cnt == NULL || buff == NULL) {
        return false;
    }

    memset(cnt, 0, (max + 1) * sizeof(int));

    for(int i = 0; i < n; i++) {
        cnt[array[i]]++;
    }

    for(int i = 1; i < max + 1; i++) {
        cnt[i] += cnt[i - 1];
    }

    for(int i = n - 1; i >= 0; i--) {
        int insertIdx = cnt[array[i]] - 1;
        buff[insertIdx] = array[i];
        cnt[array[i]]--;
    }

    memcpy(array, buff, n * sizeof(int));

    free(cnt);
    free(buff);
    return true;
}

bool countingSort(int *array, int n) {
    int max = array[0];
    int min = array[0];
    for(int i = 1; i < n; i++) {
        max = MAX(max, array[i]);
        min = MIN(min, array[i]);
    }

    if(min < 0) {
        return false;
    }

    return _countingSort(array, n, max);
}

int main(void) {
    int n;

    scanf("%d", &n);
    int *array = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    countingSort(array, n);
    
    for(int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if(i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");


    free(array);
    return 0;
}
