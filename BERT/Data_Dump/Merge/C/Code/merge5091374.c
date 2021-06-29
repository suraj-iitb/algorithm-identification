#include <stdio.h>
#include <math.h>

#define M 500000

int L[M/2+2], R[M/2+2];
int cnt;

void merge(int *arr, int left, int mid, int right){
    int i, j, k;
    int n1 = mid-left;
    int n2 = right-mid;
    for(i = 0; i < n1; i++){
        L[i] = arr[left+i];
    }
    for(i = 0; i < n2; i++){
        R[i] = arr[mid+i];
    }
    L[n1] = R[n2] = INFINITY;

    i = 0;
    j = 0;
    for(k = left; k < right; k++){
        cnt++;
        if(L[i] <= R[j]){
            arr[k] = L[i++];
        }
        else{
            arr[k] = R[j++];
        }
    }
}

void mergesort(int *arr, int left, int right){
    int mid, i;
    if(left+1 < right){
        mid = (left+right)/2;
        mergesort(arr, left, mid);
        mergesort(arr, mid, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int arr[M], n, i;
    cnt = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n);

    for(i = 0; i < n; i++){
        if(i == n-1){
            printf("%d\n", arr[i]);
        }
        else{
            printf("%d ", arr[i]);
        }
    }
    printf("%d\n", cnt);
    
    return 0;
}
