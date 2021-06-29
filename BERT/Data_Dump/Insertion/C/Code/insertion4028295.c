#include<stdio.h>

void print_array(int *array, int num){
    for(int i = 0; i < num; i++){
        printf("%d", array[i]);
        if(i != num-1) printf(" ");
    }
    printf("\n");
}

int main(void){
    int i = 0, j = 0, temp, num;
    int array[100];

    scanf("%d", &num);
    while(i < num && scanf("%d", &array[i++]) == 1);

    print_array(array, num);
    for(i = 1; i < num; i++){
        temp = array[i];
        for(j = i - 1; j >= 0 && array[j] > temp; j--){
            array[j+1] = array[j];
        }
        array[j+1] = temp;
        print_array(array, num);
    }
    
    return 0;
}
