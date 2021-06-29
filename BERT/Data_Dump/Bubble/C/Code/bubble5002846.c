#include <stdio.h>

int main() {
    int N, temp, swaptime = 0;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    for (int h = 0; h < N-1; h++) {
        for (int i = 0; i < N-h-1; i++) {
            if (arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                swaptime++;
            }
        }
    }
    for (int i = 0; i < N-1; i++){
        printf("%d ", arr[i]);
    }
    printf("%d\n%d\n", arr[N-1], swaptime);
    
}
