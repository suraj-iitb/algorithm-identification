#define N 100005
#define INF 2000000000
#include <stdio.h>

struct Card {
    char suit;
    int value;
};

struct Card A[N];  //快速排序
struct Card A1[N]; //归并排序
struct Card L[N / 2 + 2], R[N / 2 + 2];

void merge(struct Card C[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) {
        L[i] = C[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = C[mid + i];
    }
    L[n1].value = INF;
    R[n2].value = INF;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
            C[k] = L[i++];
        }
        else {
            C[k] = R[j++];
        }
    }
}

void mergeSort(struct Card C[], int left, int right) {
    if (left < right - 1) {
        int mid = (left + right) / 2;
        mergeSort(C, left, mid);
        mergeSort(C, mid, right);
        merge(C, left, mid, right);
    }
}

void swap(struct Card *a, struct Card *b) {
    struct Card tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(struct Card A[], int p, int r) {
    int x = A[r].value;
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j].value <= x) {
            i = i + 1;
            swap(&A[i], &A[j]);
        }
    }
    swap(&A[i + 1], &A[r]);
    return i + 1;
}

void quickSort(struct Card A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main() {
    int flag = 1;
    int n = 0;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        scanf("%C %d", &A[i].suit, &A[i].value);
        getchar();
        A1[i] = A[i];
    }
    mergeSort(A1, 0, n);
    quickSort(A, 0, n - 1);
    for (int i = 0; i < n; i++) {
        if (A1[i].suit != A[i].suit) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        printf("Stable\n");
    }
    else {
        printf("Not stable\n");
    }
    for (int i = 0; i < n; i++) {
        printf("%C %d\n", A[i].suit, A[i].value);
    }
    return 0;
}
