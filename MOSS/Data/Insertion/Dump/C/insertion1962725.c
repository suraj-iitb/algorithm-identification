// 1_1_A
#include<stdio.h>

void OutPut(int numbers[], int length){
    int i;
    for(i = 0; i < length - 1; i++){
        printf("%d ", numbers[i]);
    }
    printf("%d\n", numbers[length - 1]);

    return;
}

void InsertionSort(int numbers[], int length){
    int i, j, v;
    for(i = 1; i < length; i++){
        v = numbers[i];
        j = i - 1;
        while(j >= 0 && numbers[j] > v){
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = v;
        OutPut(numbers, length);
    }

    return;
}

int main()
{
    int i, length;
    int numbers[100];

    scanf("%d", &length);
    for(i = 0; i < length; i++){
        scanf("%d", &numbers[i]);
    }

    OutPut(numbers, length);
    InsertionSort(numbers, length);

    return 0;
}
