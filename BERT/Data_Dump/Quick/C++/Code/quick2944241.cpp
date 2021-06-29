#include <stdio.h>
#define MAX 100000
#define INF 1e10

struct Card {
    char suit;
    int value;
};

void merge(struct Card A[], int left, int mid, int right) {
    int k;
    int n1 = mid - left;
    int n2 = right - mid;
    
    struct Card L[n1+1], R[n2+1];
    for(int i=0; i<n1; i++) L[i] = A[left + i];
    for(int i=0; i<n2; i++) R[i] = A[mid + i];
    L[n1].value = R[n2].value = INF;
    
    int i=0, j=0;
    for (int k=left; k<right; k++) {
        if (L[i].value <= R[j].value) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(struct Card *A, int left, int right) {
    if(left+1 < right) {
        int mid = (left+right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int partition(struct Card *A, int p, int r) {
    struct Card x;
    x = A[r];
    int i = p-1;
    for (int j=p; j<r; j++) {
        if(A[j].value <= x.value) {
            i++;
            struct Card tmp=A[i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    struct Card tmp;
    tmp = A[i+1];
    A[i+1] = A[r];
    A[r] = tmp;
    
    return i+1;
}

void quickSort(struct Card A[], int p, int r) {
    int q;
    if(p<r) {
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

int main() {
    int n, v;
    struct Card A[MAX], B[MAX];
    char S[10];
    int stable = 1;
    
    scanf("%d", &n);
    
    for (int i=0; i<n; i++) {
        scanf("%s %d", S, &v);
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = v;
    }
    
    mergeSort(A, 0, n);
    quickSort(B, 0, n-1);
    
    for (int i=0; i<n; i++) {
        if(A[i].suit != B[i].suit) stable=0;
    }
    
    if(stable==1) printf("Stable\n");
    else printf("Not stable\n");
    for (int i=0; i<n; i++) {
        printf("%c %d\n", B[i].suit, B[i].value);
    }

    return 0;
}
