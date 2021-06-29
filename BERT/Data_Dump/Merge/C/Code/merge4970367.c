#include <stdio.h>
#include <limits.h>

int A[500010];
int L[250010];
int R[250010];
long long cnt;

void merge(int *A, int left, int mid, int right)
{
    int n1, n2;
    int i, j, k;
    
    n1 = mid - left;
    n2 = right - mid;
    
    // L[0...n1], R[0...n2] を生成
    for (i = 0; i < n1; i++){
        L[i] = A[left + i];
    }
    
    for (i = 0; i < n2; i++){
        R[i] = A[mid + i];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    i = j = 0;
    for (k = left; k < right; k++){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        cnt++;
    }
}
            
void mergeSort(int *A, int left, int right)
{
    int mid;
    
    if (left + 1 < right){
        mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void)
{
    int n;
    int i;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    
    mergeSort(A, 0, n);
    
    for (i = 0; i < n; i++){
        if (i != 0){
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n%lld\n", cnt);
    
    return (0);
}

