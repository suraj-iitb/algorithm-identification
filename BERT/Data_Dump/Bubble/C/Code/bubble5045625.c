#include <stdio.h>

#define N 100

int main(){
    int count = 0, array[N], flag = 1, num, i, temp;

    scanf("%d", &num);
    
    for(i = 0; i < num; i++){
        scanf("%d", &array[i]);
    }

    while (flag){
        flag = 0;
        for(i = num - 1; i > 0; i--){
            if(array[i] < array[i-1]){
                temp = array[i];
                array[i] = array[i-1];
                array[i-1] =temp;
                
                count++;
                flag = 1;
            }
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
