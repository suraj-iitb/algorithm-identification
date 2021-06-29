#include <stdio.h>

void insertSort(int *arr, int n) {
    for(int i=1; i<n; i++) {
        int tmp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>tmp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = tmp;
        for(int k=0; k<n; k++) {
            if(k == n-1) {
                printf("%d\n", arr[k]);
            } else {
                printf("%d ", arr[k]);
            }
        }
    }
}
int main() {
    int n, arr[100];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int k=0; k<n; k++) {
        if(k == n-1) {
            printf("%d\n", arr[k]);
        } else {
            printf("%d ", arr[k]);
        }
    }
    insertSort(arr, n);
    return 0;
}
