#include<stdio.h>
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int cnt = 0;
void print_array(int A[], int n){
    int i;
    printf("%d", A[0]);
    for(i = 1; i < n; i++) printf(" %d", A[i]);
    printf("\n");
}
void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int i, j, k;

    for(i = 0; i < n1; i++) L[i] = A[left+i];
    for(i = 0; i < n2; i++) R[i] = A[mid+i];

    L[n1] = SENTINEL;
    R[n2] = SENTINEL;

    i = 0;
    j = 0;

    for(k = left; k < right; k++){
        cnt++;
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }
}
void mergeSort(int A[], int left, int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}
int main(void){
    int A[MAX], n;
    int i;

    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);

    mergeSort(A, 0, n);

    print_array(A, n);
    printf("%d\n", cnt);

    return 0;
}
