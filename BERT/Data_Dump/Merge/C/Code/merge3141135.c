#include <stdio.h>

int count = 0;

int mergeSort(int *arr, int left, int right) {
    if (left  < right) {
        int mid = (left + right) >> 1;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int merge(int *arr, int left, int mid, int right) {
    int i,j, k;
    int nl = mid-left+1;
    int nr = right-mid;
    int arrL[nl], arrR[nr];
    
    for (i=0; i<nl; i++) arrL[i] = arr[i+left];
    for (j=0; j<nr; j++) arrR[j] = arr[j+mid+1];
    
    i = j = 0;
    k = left;
    while (i < nl && j < nr) {
        count++;
        if (arrL[i] <= arrR[j]) {
            arr[k++] = arrL[i++];
        } else {
            arr[k++] = arrR[j++];
        }
    }
    
    while (i < nl) {
        count++;
        arr[k++] = arrL[i++];
    }
    
    while (j < nr) {
        count++;
        arr[k++] = arrR[j++];
    }
}


int main(void){
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    mergeSort(arr, 0, n-1);
    
    for (int i=0; i<n; i++) {
        if (i != 0) printf(" ");
        printf("%d", arr[i]);
    }
    
    printf("\n%d\n", count);
}

