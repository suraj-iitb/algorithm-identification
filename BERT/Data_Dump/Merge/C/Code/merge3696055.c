#include <stdio.h>
#include <limits.h>
int A[500000+5];
int swapCount = 0;

void merge(int, int, int);
void merge_sort(int, int);

int main()
{
    int i, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &A[i]);
    
    merge_sort(0, n);
    for (i = 0; i < n-1; i++) printf("%d ", A[i]);
    printf("%d\n", A[i]);
    printf("%d\n", swapCount);
    return 0;
}

void merge(int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    int i, j, k;
    for (i = 0; i < n1; i++) L[i] = A[left + i];
    for (i = 0; i < n2; i++) R[i] = A[mid + i];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    
    i = 0;
    j = 0;
    for (k = left; k < right; k++){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
            swapCount++;
        }
        else{
            A[k] = R[j];
            j++;
            swapCount++;
        }
    }
}

void merge_sort(int left, int right){
    if (left + 1 < right){
        int mid = (left + right)/2;
        merge_sort(left, mid);
        merge_sort(mid, right);
        merge(left, mid, right);
    }
}

