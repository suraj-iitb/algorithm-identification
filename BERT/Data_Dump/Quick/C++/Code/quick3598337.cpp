#include<stdio.h>
#define MAX 100000
#define SENTINEL 1000000001

typedef struct Card {
    char suit;
    int value;
} Card;

Card L[MAX/2 + 2], R[MAX/2+2];

int partition(Card A[], int p, int r) {
    Card x, y;
    int i, j;
    x = A[r];
    i = p-1;
    for (j=p; j<r; j++) {
        if (A[j].value<=x.value) {
            i++;
            y = A[j];
            A[j] = A[i];
            A[i] = y;
        }
    }
    i++;
    A[r] = A[i];
    A[i] = x;

    return i;
}

void quickSort(Card A[], int p, int r) {
    int q;
    if (p<r) {
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

void merge(Card A[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    for (i=0; i<n1; i++) L[i]=A[left+i];
    for (i=0; i<n2; i++) R[i]=A[mid+i];
    L[n1].value=SENTINEL;
    R[n2].value=SENTINEL;
    i = 0;
    j = 0;
    for (k=left; k<right; k++) {
        if (L[i].value<=R[j].value) {
            A[k] = L[i];
            i+=1;
        } else {
            A[k] = R[j];
            j+=1;
        }
    }
}

void merge_sort(Card A[], int left, int right) {
    if (left+1<right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    Card A[MAX], B[MAX];
    int n, i, j;
    bool stable=true;
    char S[10];

    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf("%s %d", S, &j);
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = j;
    }

    quickSort(A, 0, n-1);
    merge_sort(B, 0, n);
    
    for (i=0; i<n; i++) {
        if (A[i].suit != B[i].suit) {
            stable = false;
        }
    }
    if (stable) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }
    for (i=0; i<n; i++) {
        printf("%c %d\n", A[i].suit, A[i].value);
    }
    return 0;
}
