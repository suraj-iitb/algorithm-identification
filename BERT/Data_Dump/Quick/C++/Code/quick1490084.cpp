#include <cstdio>
#define N 100000
#define MAX 1000000000

typedef struct {
    char type;
    long long value;
} Card;

void exchange(Card A[], int index, int r) {
    Card tmp = A[index];
    A[index] = A[r];
    A[r] = tmp;
}

int Partition(Card A[], int p, int r) {
    int x = A[r].value;
    int i = p - 1;
    for (int j = p; j<r; j++) {
        if (A[j].value <= x) {
            i++;
            exchange(A, i, j);
        }
    }
    exchange(A, i+1, r);
    return i + 1;
}

void Quicksort(Card A[], int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        Quicksort(A, p, q - 1);
        Quicksort(A, q + 1, r);
    }
}

void merge(Card A[], long long left, long long mid, long long right) {
    long long n1 = mid - left + 2;
    long long n2 = right - mid + 1;
    Card L[n1], R[n2];
    for (long long i=0; i<n1-1; i++) {
        L[i] = A[left + i];
    }
    for (long long i=0; i<n2-1; i++) {
        R[i] = A[mid + 1 + i];
    }

    L[n1-1].value = MAX;
    R[n2-1].value = MAX;

    long long l = 0, r = 0;
    for (long long i=left; i<=right; i++) {
        if (L[l].value <= R[r].value) {
            A[i] = L[l];
            l++;
        } else {
            A[i] = R[r];
            r++;
        }
    }
}

void merge_sort(Card A[], long long left, long long right) {
    if (left < right) {
        long long mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge(A, left, mid, right);
    }
}

int
main() {
    int n;
    Card A[N];
    Card B[N];
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        char c;
        long long s;
        scanf(" %c %lld", &c, &s);
        A[i].type = B[i].type = c;
        A[i].value = B[i].value = s;
    }

    merge_sort(B, 0, n - 1);
    Quicksort(A, 0, n - 1);
    bool isStable = true;
    for (int i=0; i<n; i++) {
        if (A[i].type != B[i].type || A[i].value != B[i].value) {
            isStable = false;
            break;
        }
    }

    if (isStable) printf("Stable\n");
    else printf("Not stable\n");

    for (int i=0; i<n; i++) {
        printf("%c %lld\n", A[i].type, A[i].value);
    }


    return 0;
}
