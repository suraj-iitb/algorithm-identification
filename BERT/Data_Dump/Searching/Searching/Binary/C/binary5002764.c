#include <stdio.h>

int main() {
    int N, Q, matchtime = 0;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &Q);
    for (int h = 0; h < Q; h++){
        int temp, down = 0, up = N - 1, mid = (up + down)/2;
        scanf("%d", &temp);
        for (int i = 0; i < N; i++){
            if (temp == arr[mid] || temp == arr[up] || temp == arr[down]){
                matchtime++;
                break;
            } else {
                if (up + 1 == down) {
                    break;
                } else {
                    if (temp < arr[mid]) {
                        up = mid - 1;
                        mid = (up + down)/2;
                } else {
                        down = mid + 1;
                        mid = (up + down)/2;
                    }
                }
            }
        }
    }
    printf("%d\n", matchtime);
}
