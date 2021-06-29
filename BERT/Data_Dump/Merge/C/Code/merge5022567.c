#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[500001];
int cnt = 0;
int n;
void Merge(int left, int mid, int right) {
    int sta = left;
    int SecStart = mid + 1;
    int tmpSize = (right - left + 1);
    int *tmp = (int *)malloc(sizeof(int) * tmpSize);
    int index = 0;
    while (left <= mid && SecStart <= right) {
        cnt++;
        if (arr[left] > arr[SecStart]) {
            tmp[index++] = arr[SecStart++];
        } else {
            tmp[index++] = arr[left++];
        }
    }
    while (SecStart <= right) {
        cnt++;
        tmp[index++] = arr[SecStart++];
    }
    while (left <= mid) {
        cnt++;
        tmp[index++] = arr[left++];
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
    printf("\n%d\n", cnt);

    return 0;
}

