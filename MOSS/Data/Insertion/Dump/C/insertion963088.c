#include <stdio.h>
#define N 101

void Printing(int arr[], int n){
    int i;
    for(i = 0; i < n-1; i++){
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[n-1]);
}

void insertion(int arr[], int n) {
    int key, i, j;
    Printing(arr, n);
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && key < arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        Printing(arr, n);
    }
}


int main() {
    int n, i, arr[N];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertion(arr, n);
    return 0;
}
