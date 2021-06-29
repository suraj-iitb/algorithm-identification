#include <stdio.h>
#include <stdlib.h>

int main(){
        int n, i, j, minj, buffer, num_s = 0;
        int *array;

        scanf("%d", &n);

        array = (int *)malloc(n * sizeof(int));

        for(i = 0 ; i < n ; i++){
                scanf("%d", &array[i]);
        }

        for(i = 0 ; i < n ; i++){
                minj = i;
                for(j = i ; j < n ; j++){
                        if(array[j] < array[minj]){
                                minj = j;
                        }
                }
                if(minj != i){
                        buffer = array[minj];
                        array[minj] = array[i];
                        array[i] = buffer;
                        num_s++;
                }
        }

        for(i = 0 ; i < n ; i++){
                printf("%d", array[i]);
                if(i + 1 != n)printf(" ");
        }
        printf("\n");

        printf("%d\n", num_s);

        return 0;
}

