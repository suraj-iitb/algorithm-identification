#include <stdio.h>
#include <stdlib.h>

int main(){
        int i, j, key,  n;
        int *array;

        scanf("%d", &n);

        array = (int *)malloc(n * sizeof(int));

        for(i = 0 ; i < n ; i++){
                scanf("%d", &array[i]);
        }

        for(j = 0 ; j < n ; j++){
                printf("%d", array[j]);
                if(j == n - 1)break;
                printf(" ");
        }
        printf("\n");

        for(i = 1 ; i < n ; i++){
                key = array[i];
                j = i - 1;
                while(j >= 0 && array[j] > key){
                        array[j+1] = array[j];
                        j--;            
                }
                array[j+1] = key;
                
                for(j = 0 ; j < n ; j++){
                        printf("%d", array[j]);
                        if(j == n - 1)break;
                        printf(" ");
                }
                printf("\n");
        } 

        return 0;
}

