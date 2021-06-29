// 1_2_A
#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *numbers, int length){
    int flag = 1, i, tmp, cnt = 0;
    while(flag){
        flag = 0;
        for(i = length - 1; i >=1; i--){
            if(numbers[i] < numbers[i-1]){
                tmp = numbers[i];
                numbers[i] = numbers[i-1];
                numbers[i-1] = tmp;
                flag = 1;
                cnt += 1;
            }
        }
    }

    for(i = 0; i < length - 1; i++){
        printf("%d ", numbers[i]);
    }
    printf("%d\n", numbers[length - 1]);
    printf("%d\n", cnt);
    return;
}

int main(){
    int n, *numbers, i;
    scanf("%d", &n);
    numbers = (int *)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }

    BubbleSort(numbers, n);

    free(numbers);
    return 0;
}
