#include <stdio.h>

int main(){
    int i, j, tmp, total, cnt = 0;
    int arr[100];

    scanf("%d", &total);
    for(i = 0; i < total; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < total; i++){
        for(j = total-1; j > i; j--){
            if(arr[j] < arr[j-1]){
                tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
                cnt++;
            }
        }
    }
    for(i = 0; i < total; i++){
        if(i == total-1){
            printf("%d\n", arr[i]);
        }
        else{
            printf("%d ", arr[i]);
        }
    }
    printf("%d\n", cnt);
    return 0;
}
