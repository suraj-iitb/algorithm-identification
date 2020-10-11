#include <stdio.h>
#include <stdlib.h>

#define N 500000

int S[N], cnt = 0;

void merge(int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    int L[n1 + 1], R[n2 + 1], i, j, k;
    for (i = 0; i < n1; i++) {
        L[i] = S[left + i];
    }
    for (i = 0; i < n2; i++) {
        R[i] = S[mid + i];
    }
    L[n1] = 1000000001;
    R[n2] = 1000000001;
    i = 0;
    j = 0;
    for (k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            S[k] = L[i++];
        } else {
            S[k] = R[j++];
        }
        cnt++;
    }
}

void mergeSort(int left, int right) {
    int mid;
    
    if (left + 1 < right) {
        mid = (left + right)/2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid, right);
    }
}


int main(void){
    int i, n;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }
    
    mergeSort(0, n);
    
    for (i = 0; i < n - 1; i++) {
        printf("%d ", S[i]);
    }
    printf("%d\n%d\n", S[i], cnt);
    
    return 0;
}

