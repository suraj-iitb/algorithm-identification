#include <cstdio>

const int N = 600000;
const int MAX = 2000000000;

int n, cnt;

void merge(int *A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int L[N], R[N];
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = MAX; R[n2] = MAX;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int* A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int A[N];
    scanf("%d", &n);
    cnt = 0;
    for(int i = 0; i < n; i++) scanf("%d", &A[i]);
    mergeSort(A, 0, n);

    for(int i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", cnt);
}

