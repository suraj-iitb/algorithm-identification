#define N 500005
#define INF 2000000000
#include <stdio.h>

int A[N];
int L[N / 2 + 2];
int R[N / 2 + 2];
int cnt;

void showArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d" + !i, A[i]);
    }
    printf("\n");
}

void merge(int A[], int left, int mid, int right) {
    // 此为数组中实际元素的个数
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    L[n1] = INF;
    R[n2] = INF;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right) {
    // 如果当前子数组还有两个以上元素
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left ,mid, right);
    }
} 

int main() {
    int n = 0;
    cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }    
    mergeSort(A, 0, n);
    showArray(A, n);
    printf("%d\n", cnt);
    return 0;
}
