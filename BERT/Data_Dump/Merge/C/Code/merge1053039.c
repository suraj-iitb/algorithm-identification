#include <stdio.h>
#include <stdlib.h>

#define SENTINEL 1000000001

int *array;
int cnt = 0;

void mergeSort(int begin, int end);

int main(void)
{
    int i;

    int n;
    scanf("%d", &n);
    array = malloc(sizeof(int) * n);
    if (array == NULL) {
        printf("ERROR! Cannot allocate memory in main().\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    mergeSort(0, n);

    for (i = 0; i < n; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", array[i]);
    }
    printf("\n");
    printf("%d\n", cnt);

    free(array);

    return 0;
}

void merge(int begin, int mid, int end);

void mergeSort(int begin, int end)
{
    if (begin + 1 < end) {
        int mid = (begin + end) / 2;
        mergeSort(begin, mid);
        mergeSort(mid, end);
        merge(begin, mid, end);
    }
}

void merge(int begin, int mid, int end)
{
    int i, j, k;

    int n_left = mid - begin;
    int n_right = end - mid;
    int *left, *right;
    left = malloc(sizeof(int) * (n_left + 1));
    right = malloc(sizeof(int) * (n_right + 1));
    if (left == NULL || right == NULL) {
        printf("ERROR! Cannot allocate memory in merge().\n");
        exit(1);
    }

    for (i = 0; i < n_left; i++) {
        left[i] = array[begin + i];
    }
    left[n_left] = SENTINEL;

    for (i = 0; i < n_right; i++) {
        right[i] = array[mid + i];
    }
    right[n_right] = SENTINEL;

    i = j = 0;
    for (k = begin; k < end; k++) {
        if (left[i] <= right[j]) {
            array[k] = left[i++];
        } else {
            array[k] = right[j++];
        }
        cnt++;
    }

    free(left);
    free(right);
}
