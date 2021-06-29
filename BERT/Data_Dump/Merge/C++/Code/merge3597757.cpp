#include<stdio.h>
#define SENTINEL 2147483647
#define MAX 500000
int cnt;
int L[MAX],R[MAX];


void merge(int A[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    for (i=0; i<n1; i++) L[i]=A[left+i];
    for (i=0; i<n2; i++) R[i]=A[mid+i];
    L[n1]=SENTINEL;
    R[n2]=SENTINEL;
    i = 0;
    j = 0;
    for (k=left; k<right; k++) {
        cnt++;
        if (L[i]<=R[j]) {
            A[k] = L[i];
            i+=1;
        } else {
            A[k] = R[j];
            j+=1;
        }
    }
}

void merge_sort(int A[], int left, int right) {
    if (left+1<right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int i, n;
    int S[500000];
    cnt = 0;

    scanf("%d", &n);
    for (i=0; i<n; i++) scanf("%d", &S[i]);
    merge_sort(S, 0, n);
    for (i=0; i<n; i++) {
        if (i>0) printf(" %d", S[i]);
        else printf("%d", S[i]);
    }
    printf("\n");
    printf("%d\n", cnt);
    return 0;
}
