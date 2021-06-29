#include<stdio.h>

void trace(int arr[], int N) {
    int i;
    for (i=0; i<N; i++) {
        if (i>0) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int N) {
    int j, i ,k;
    for (i=1; i<N; i++) {
        k=arr[i];
        j=i-1;
        while (j>=0 && arr[j]>k) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
        trace(arr, N);
    }
}

int main() {
    int i, j, N;
    int arr[100];
    
    scanf("%d", &N);
    for (i=0; i<N; i++) scanf("%d", &arr[i]);
    
    trace(arr, N);
    insertionSort(arr, N);
    
    return 0;
}
