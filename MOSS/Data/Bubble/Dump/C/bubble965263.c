#include <stdio.h>
#define N 101


int main(){
    int n, i, j;
    int arr[N];
    int temp, cnt = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // bubble
    for(i = 0; i < n-1; i++) {
        for(j = n-1; j > i; j--) {
            if(arr[j-1] > arr[j]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                cnt++;
            }
        }
    }

    for(i = 0; i < n-1; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d\n", arr[n-1]);
    printf("%d\n", cnt);
    return 0;
}
