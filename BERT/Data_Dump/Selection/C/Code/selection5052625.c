#include <stdio.h>

int main(){
    int i, j , min_num, total, tmp, cnt = 0, chancnt;
    int arr[100];

    scanf("%d", &total);
    for(i = 0; i <total; i++){
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < total-1; i++){
        min_num = i;
        for(j = i; j < total; j++){
            if(arr[j] < arr[min_num]){
                min_num = j;
            }
        }
        if(arr[i] != arr[min_num]){
            tmp = arr[i];
            arr[i] = arr[min_num];
            arr[min_num] = tmp;
            cnt++;
        }
    }
    for(i = 0; i < total; i++){
        if(i == total-1){
            printf("%d", arr[i]);
        }
        else{
            printf("%d ", arr[i]);
        }
    }
    printf("\n%d\n", cnt);
    return 0;
}
