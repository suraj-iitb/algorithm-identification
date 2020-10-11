#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[500010];
int count = 0;
int n;
void Merge(int start, int mid, int end) {
    int sta = start;
    int SecStart = mid + 1;
    int tmpSize = (end - start + 1);
    int *tmp = (int *) malloc(sizeof(int) * tmpSize);
    int index = 0;
    while (start <= mid && SecStart <= end) {
        count++;
        if (arr[start] > arr[SecStart]) {
            tmp[index++] = arr[SecStart++];
        } else {
            tmp[index++] = arr[start++];
        }
    }
    while (SecStart <= end) {
        count++;
        tmp[index++] = arr[SecStart++];
    }
    while (start <= mid) {
        count++;
        tmp[index++] = arr[start++];
    }
    memcpy(arr + sta, tmp, sizeof(int) * tmpSize);
    free(tmp);

}

void MergeSort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(start, mid);
        MergeSort(mid + 1, end);
        Merge(start, mid, end);
    }
}

int main() {

    //freopen("../in.txt", "r", stdin);

    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &(arr[i]));
    }
    bool flag = true;
    MergeSort(0, n - 1);
    for (i = 0; i < n; i++) {
        if (flag) {
            flag = false;
        } else {
            printf(" ");
        }
        printf("%d", arr[i]);
    }
    printf("\n%d\n", count);

    return 0;
}

