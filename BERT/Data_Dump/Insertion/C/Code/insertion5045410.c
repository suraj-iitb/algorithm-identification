#include <stdio.h>

#define N 100

int main(){
    int num, i, j, temp, array[N];
    
    scanf("%d",&num);

    for (i = 0; i < num; i++){
        scanf("%d",&array[i]);
    }

    for(j = 0; j < num; j++){
            if(j > 0) printf(" ");
            printf("%d", array[j]);

        }

        printf("\n");

    for (i = 1; i < num; i++){
        temp = array[i];
        j = i - 1;
        while(j >= 0 && array[j] > temp){
            array[j+1] = array[j];
            j--;
            array[j+1] = temp;
        }

        for(j = 0; j < num; j++){
            if(j > 0) printf(" ");
            printf("%d", array[j]);

        }

        printf("\n");
        
    }
    return 0;
}
