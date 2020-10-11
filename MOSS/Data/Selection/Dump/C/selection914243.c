#include <stdio.h>
#define N 100

int main(void){

    int i, j, arr[N], n;
    int temp, min, count = 0;

    // input
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // sort
    for (i = 0; i < n-1; i++) {
        min = i;
        for (j = i; j < n; j++) {
            if(arr[j] < arr[min]) min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        if(i != min) count++;
    }


    for (i = 0; i < n-1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[n-1]);
    printf("%d\n", count);

    return 0;
}
