#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char suit;
    int value;
} Card;

void merge(Card A[], int left, int mid, int right) {
    int i = 0;
    int j = 0;
    int k;
    int n1 = mid - left;
    int n2 = right - mid;
    Card *L = (Card *)malloc((n1 + 1) * sizeof(Card));
    Card *R = (Card *)malloc((n2 + 1) * sizeof(Card));
    memcpy(L, A + left, (n1 + 1) * sizeof(Card));
    memcpy(R, A + mid, (n2 + 1) * sizeof(Card));
    L[n1].value = 2000000000;
    R[n2].value = 2000000000;
    for (k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
    free(R);
    free(L);
}

void mergeSort(Card A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(Card A[], int p, int r) {
    Card x = A[r];
    int i = p - 1;
    int j;
    for (j = p; j < r; j++) {
        if (A[j].value <= x.value) {
            Card tmp = A[j];
            i++;
            A[j] = A[i];
            A[i] = tmp;
        }
    }
    A[r] = A[i + 1];
    A[i + 1] = x;
    return i + 1;
}

void quickSort(Card A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

void printarray(Card A[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c %d\n", A[i].suit, A[i].value);
    }
}

int equals(Card A[], Card B[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (A[i].suit != B[i].suit) return 0;
    }
    return 1;
}

int main(void) {
    int n, i, q;
    Card A[100000];
    Card B[100000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf(" %c %d", &A[i].suit, &A[i].value);
        B[i] = A[i];
    }
    quickSort(A, 0, n - 1);
    mergeSort(B, 0, n);
    if (equals(A, B, n)) printf("Stable\n");
    else printf("Not stable\n");
    printarray(A, n);
    return 0;
}

