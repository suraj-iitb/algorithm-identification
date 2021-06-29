#include <stdio.h>

#define N 100

int main(){
    int count = 0, array[N], flag = 1, num, i, j, temp, min;

    scanf("%d", &num);
    
    for(i = 0; i < num; i++){
        scanf("%d", &array[i]);
    }

    for(i = 0; i < num; i++){
        min = i;
        
        for(j = i; j < num; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }

    if(min != i){
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;   
        count++;
    }
    }

    for(i = 0; i < num; i++){
        if(i > 0)printf(" ");
        printf("%d", array[i]);
    }
    printf("\n");
    printf("%d\n", count);


    return 0;
}
