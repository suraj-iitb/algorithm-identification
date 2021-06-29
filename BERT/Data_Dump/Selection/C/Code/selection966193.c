#include <stdio.h>

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int n, i, j, min;
    int arr[101];
    int cnt = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n-1; i++) {
        min = i;
        for (j = i+1; j < n; j++) {
            if(arr[min] > arr[j]) {
                min = j; 
            }
        }
        if(min != i){
            cnt++;
            swap(&arr[i], &arr[min]);
        }
    }

    for (i = 0; i < n-1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[n-1]);
    printf("%d\n", cnt);



    return 0;
}
