#include <stdio.h>
#define N 100


int main(void){

    int n, i, arr[N], temp, j;
    int count = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 1; i < n; i++){
        for (j = (n-1); j > 0; j--) {
            if(arr[j] < arr[j-1]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                count++;
            }
        }
    }

    for (i = 0; i < n-1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[n-1]);
    printf("%d\n", count);

    return 0;
}
