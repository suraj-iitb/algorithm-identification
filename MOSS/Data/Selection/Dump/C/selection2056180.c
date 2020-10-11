// 1_2_B
#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int *numbers, int length){
    int i, j, minj, tmp, cnt = 0;
    for(i = 0; i < length; i++){
        minj = i;
        for(j = i; j < length; j++){
            if(numbers[j] < numbers[minj]) minj = j;
        }
        if(minj != i){
            tmp = numbers[i];
            numbers[i] = numbers[minj];
            numbers[minj] = tmp;
            cnt++;
        }
    }

    for(i = 0; i < length - 1; i++){
        printf("%d ", numbers[i]);
    }
    printf("%d\n", numbers[i]);
    printf("%d\n", cnt);
    return;
}

int main(){
    int n, i, *numbers;
    scanf("%d", &n);
    numbers = (int *)malloc(sizeof(int) * n);
    for(i = 0; i < n; i++){
        scanf("%d", &numbers[i]);
    }

    SelectionSort(numbers, n);

    free(numbers);
    return 0;
}
