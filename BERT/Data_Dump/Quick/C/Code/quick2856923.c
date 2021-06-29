#include <stdio.h>
#define MAX 100000
#define SEN 2000000000

struct Card {
    char suit;
    int value;
};

struct Card L[MAX/2 + 2], R[MAX/2 + 2];

int partition(struct Card A[], int p, int r)
{
    int i, j;
    struct Card x = A[r];
    struct Card t;
    i = p - 1;
    for (j = p; j < r; j++) {
        if (A[j].value <= x.value) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[i + 1];
    A[i + 1] = A[r];
    A[r] = t;
    return i + 1;
}

void quick_sort(struct Card A[], int p, int r)
{
    if (p < r) {
        int q = partition(A, p, r);
        quick_sort(A, p, q-1);
        quick_sort(A, q+1, r);
    }
}

void merge(struct Card A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
    L[n1].value = R[n2].value = SEN;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void merge_sort(struct Card A[], int left, int right)
{
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int is_stable(struct Card C1[], struct Card C2[], int n)
{
    for (int i = 0; i < n; i++) {
        if (C1[i].suit != C2[i].suit) return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int n;
    struct Card C1[MAX];
    struct Card C2[MAX];
    char S[10];
    int v;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", S, &v);
        C1[i].suit  = S[0];
        C1[i].value = v;
        C2[i].suit  = S[0];
        C2[i].value = v;
    }
    merge_sort(C1, 0, n);
    quick_sort(C2, 0, n - 1);
    if (is_stable(C1, C2, n)) {
        printf("Stable\n");
    } else {
        printf("Not stable\n");
    }
    for (int i = 0; i < n; i++) {
        printf("%c %d\n", C2[i].suit, C2[i].value);
    }

    return 0;
}


