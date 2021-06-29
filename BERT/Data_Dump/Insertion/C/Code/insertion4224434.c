#include <stdio.h>

void dump_arr(int arr[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d%s", arr[i], (i == n - 1) ? "\n" : " ");
    }
}

void insertion_sort(int arr[], int n){
    int i, j;
    for(i = 1; i < n; i++){
        int tmp = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > tmp; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = tmp;

        dump_arr(arr, n);
    }
}

int main(){
    int i, n, arr[100];
    
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        getchar();
        scanf("%d", &arr[i]);
    }
    
    dump_arr(arr, n);
    insertion_sort(arr, n);
}
