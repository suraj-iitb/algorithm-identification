#include <stdio.h>

#define MAX 500000
#define SENTINEL 2000000000
int L[MAX/2 + 2], R[MAX/2 + 2], cnt=0, A[MAX];

void mergeSort(int A[], int left, int mid ,int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++) L[i] = A[left + i];
    for (int i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1]=R[n2]=SENTINEL;
    int i=0, j=0;
    for (int k= left; k < right; k++) {
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        cnt++;
    }
}

void merge(int A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (right + left) / 2;
        merge(A, left, mid);
        merge(A, mid ,right);
        mergeSort(A, left, mid, right);
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    
    merge(A, 0, n);
    
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    
    printf("\n");
    printf("%d", cnt);
    printf("\n");
    
    return 0;
    
}

