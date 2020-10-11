#include<stdio.h>
#define MAX 500000
#define BUMP 10000000000

int count = 0;
int L[MAX / 2 + 2], R[MAX / 2 + 2];

void marge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    int i, j, m;
   
    for(i = 0; i < n1; i++) L[i] = A[left + i];
    for(i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = R[n2] = BUMP;
    for(i = 0, j = 0, m = left; m < right; m++){
        count++;
        if(L[i] <= R[j]){
            A[m] =L[i];
            i++;
        }else{
            A[m] = R[j];
            j++;
        }
    }
}

void margesort(int A[], int left, int right){
    if(left + 1 < right ){
        int mid = (right + left) / 2;
        margesort(A, left, mid);
        margesort(A, mid, right);
        marge(A, left, mid, right);
    }
}

int main(void){
    int A[MAX];
    int n, i;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    margesort(A, 0, n);

    for(i = 0; i < n - 1; i++){
        printf("%d ", A[i]);
    }
    printf("%d\n%d\n", A[i], count);
    return 0;
}

